#include "argument_parser.h"

int main(int argc, char **argv) {
    NodeSaveRequest node_request;

    // Parse Arguments
    parse_arguments(node_request, argc, argv);

    return 0;
}