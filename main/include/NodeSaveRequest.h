//
// Created by KangDroid on 2021/02/09.
//

#ifndef CLNODEREGISTER_NODESAVEREQUEST_H
#define CLNODEREGISTER_NODESAVEREQUEST_H

#include <iostream>

using namespace std;

class NodeSaveRequest {
public:
    NodeSaveRequest() {
        id = 10;
        hostPort = "8080";
    }
public:
    int id;
    string hostName;
    string hostPort;
    string ipAddress;
    string masterUrl;
};


#endif //CLNODEREGISTER_NODESAVEREQUEST_H