#include <gtest/gtest.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <filesystem>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}