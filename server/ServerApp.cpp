#include "Polygon.hpp"
#include "crow.h"
#include "rapidjson/document.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/convex-hull")
            .methods(crow::HTTPMethod::OPTIONS,crow::HTTPMethod::POST)
                    ([](const crow::request& req){
                        crow::response response;
                        response.add_header("Access-Control-Allow-Origin", "*");
                        if(req.method == "OPTIONS"_method)
                        {
                            response.add_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
                            response.add_header("Access-Control-Allow-Headers", "*");
                        }
                        else{
                            rapidjson::Document reqBody;
                            reqBody.Parse(req.body.data());
                            const rapidjson::Value &jsonPoints = reqBody["points"];

                            std::vector<Point> startingPoints;
                            for (auto iter = jsonPoints.Begin(); iter != jsonPoints.End(); iter++) {
                                const rapidjson::Value &currPoint = *iter;
                                Point newPoint;
                                if (!currPoint.IsObject()) {
                                    return crow::response(400);
                                }
                                for (auto elIter = currPoint.MemberBegin(); elIter != currPoint.MemberEnd(); elIter++) {
                                    if (std::strcmp(elIter->name.GetString(),"x") == 0) {
                                        newPoint.x = elIter->value.GetInt();
                                    } else if (std::strcmp(elIter->name.GetString(),"y") == 0) {
                                        newPoint.y = elIter->value.GetInt();
                                    }
                                }
                                startingPoints.push_back(newPoint);
                            }

                            Polygon P(startingPoints);
                            AlgoIterator itr = P.GetStepsOfJarvisAlgorithm();

                            response.body = itr.to_json();

                        }
                        return response;
                    });

    app.port(18080).multithreaded().run();
}