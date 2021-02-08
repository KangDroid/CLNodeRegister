#include <gtest/gtest.h>
#include "NodeSaveRequest.h"
#include "argument_parser.h"
#include "server_request.h"

using namespace std;

TEST(ArgumentParsing, isHostnameSet) {
    NodeSaveRequest node_tmp;
    int argc = 3;
    char * argv[] = {
            "./a.out", "--hostname", "localhost"
    };

    parse_arguments(node_tmp, argc, argv);

    EXPECT_EQ(node_tmp.hostName, "localhost");
}

TEST(ArgumentParsing, ishostPortSet) {
    NodeSaveRequest node_tmp;
    int argc = 3;
    char * argv[] = {
            "./a.out", "--hostport", "8080"
    };

    parse_arguments(node_tmp, argc, argv);

    EXPECT_EQ(node_tmp.hostPort, "8080");
}

TEST(ArgumentParsing, isIpAddrSet) {
    NodeSaveRequest node_tmp;
    int argc = 3;
    char * argv[] = {
            "./a.out", "--ipaddr", "192.168.0.8"
    };

    parse_arguments(node_tmp, argc, argv);

    EXPECT_EQ(node_tmp.ipAddress, "192.168.0.8");
}

TEST(ArgumentParsing, isBlendedWorking) {
    NodeSaveRequest node_tmp;
    int argc = 7;
    char * argv[] = {
            "./a.out",
            "--ipaddr", "192.168.0.8",
            "--hostname", "localhost",
            "--hostport", "8080"
    };

    parse_arguments(node_tmp, argc, argv);

    EXPECT_EQ(node_tmp.hostName, "localhost");
    EXPECT_EQ(node_tmp.hostPort, "8080");
    EXPECT_EQ(node_tmp.ipAddress, "192.168.0.8");
}

TEST(ArgumentParsing, isShortBlendedWorking) {
    NodeSaveRequest node_tmp;
    int argc = 7;
    char * argv[] = {
            "./a.out",
            "-i", "192.168.0.8",
            "-H", "localhost",
            "-p", "8080"
    };

    parse_arguments(node_tmp, argc, argv);

    EXPECT_EQ(node_tmp.hostName, "localhost");
    EXPECT_EQ(node_tmp.hostPort, "8080");
    EXPECT_EQ(node_tmp.ipAddress, "192.168.0.8");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}