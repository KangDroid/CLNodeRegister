#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;

int main(int argc, char **argv) {
    variables_map vm;
    options_description desc("Supported Options/Args");
    desc.add_options()
            ("help,h", "Show a help screen");

    store(parse_command_line(argc, argv, desc), vm);

    if (vm.count("help") || vm.empty()) {
        cout << desc << endl;
        return 0;
    }

    return 0;
}