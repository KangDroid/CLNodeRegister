//
// Created by KangDroid on 2021/02/09.
//

#include <iostream>
#include <boost/program_options.hpp>
#include "NodeSaveRequest.h"

using namespace std;
using namespace boost::program_options;

void parse_arguments(NodeSaveRequest& node_request, int argc, char** argv) {
    variables_map vm;
    options_description desc("Supported Options/Args");
    desc.add_options()
            ("help,h", "Show a help screen")
            ("hostname,H", value<string>(), "The name to call Host[Just string-based name]")
            ("ipaddr,i", value<string>(), "The IP Address of Node Server")
            ("hostport,p", value<string>(), "Node Server's Port");

    store(parse_command_line(argc, argv, desc), vm);

    if (vm.count("help") || vm.empty()) {
        cout << desc << endl;
        exit(0);
    }

    if (vm.count("hostname")) {
        node_request.hostName = vm["hostname"].as<string>();
    }

    if (vm.count("hostport")) {
        node_request.hostPort = vm["hostport"].as<string>();
    }

    if (vm.count("ipaddr")) {
        node_request.ipAddress = vm["ipaddr"].as<string>();
    }
}