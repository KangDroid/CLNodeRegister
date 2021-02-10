//
// Created by KangDroid on 2021/02/09.
//

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include "NodeSaveRequest.h"

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

void request_server(NodeSaveRequest& node_request) {
    string url = node_request.masterUrl + "/api/admin/node/register";

    // The Client
    http_client client_req(url);

    // The body
    http_request request_type(methods::POST);

    json::value main_post = json::value::object();
    main_post["id"] = json::value::number(node_request.id);
    main_post["hostName"] = json::value::string(node_request.hostName);
    main_post["hostPort"] = json::value::string(node_request.hostPort);
    main_post["ipAddress"] = json::value::string(node_request.ipAddress);

    request_type.set_body(main_post);
    json::value main_response;

    try {
        client_req.request(request_type).then([&main_response](http_response hr) {
            main_response = hr.extract_json().get();
        }).wait();
    } catch (const exception& expn) {
        cerr << "Error: ";
        cerr << expn.what() << endl;
    }

    string error_message = main_response["errorMessage"].as_string();
    if (!error_message.empty()) {
        cerr << "Error: " << error_message << endl;
    } else {
        cout << "Successfully registered node!" << endl;
        cout << "IP: " << main_response["ipAddress"].as_string() << endl;
        cout << "Port: " << main_response["hostPort"].as_string() << endl;
        cout << "Registered As: " << main_response["regionName"].as_string() << endl;
    }
}