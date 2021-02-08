#include "argument_parser.h"
#include "server_request.h"

int main(int argc, char **argv) {
    NodeSaveRequest node_request;

    // Parse Arguments
    parse_arguments(node_request, argc, argv);

    request_server(node_request);

    return 0;
}