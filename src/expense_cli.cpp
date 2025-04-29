#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>
#include "../include/expense_cli.hpp"

namespace tracker {
    int add_command(int, char **);
    int list_command(int, char **);
    int update_command(int, char **);
    int delete_command(int, char **);
    int summary_command(int, char **);
    int print_help(int, char **);

    static std::unordered_map<std::string, std::function<int(int, char **)>> command_handles {
        {"add", add_command},
        {"list", list_command},
        {"update", update_command},
        {"delete", delete_command},
        {"summary", summary_command},
        {"help", print_help}
    };
}

int tracker::handle_command(int argc, char **argv) {
    if(argc == 1) {
        std::cerr << "No command provided. Use 'help' for usage information" << std::endl;
        return 1;
    }
    const std::string cmd = argv[1];
    auto it = command_handles.find(cmd);
    if(it == command_handles.end()) {
        std::cerr << "Unknown command: " << cmd << ". Use 'help' for usage information" << std::endl;
        return 1;
    }
    return it->second(argc, argv);
}