#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>
#include "../include/expense_cli.hpp"
#include "../include/expense_service.hpp"

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

int tracker::add_command(int argc, char **argv) {
    if(argc != 6) {
        std::cerr << "Invalid number of arguments for add command." << '\n'
                  << "Usage: " << argv[0] << " add --description <description> --amount <amount>"
                  << std::endl;
        return 1;
    }
    std::string description {""};
    double amount {0.0};
    for(int i {2}; i < argc; ++i) {
        std::string opt = argv[i];
        if(i + 1 >= argc || (argv[i + 1][0] == '-' && argv[i + 1][1] == '-')) {
            std::cerr << "Missing value for option: " << opt << std::endl;
            return 1;
        } else if(opt == "--description") {
            description = argv[++i];
        } else if(opt == "--amount") {
            try {
                amount = std::stod(argv[++i]);
            } catch(const std::invalid_argument &e) {
                std::cerr << "Invalid amount value: " << e.what() << std::endl;
                return 1;
            }
        }
    }
    if(description.empty() || amount <= 0) {
        std::cerr << "Invalid arguments for add command" << std::endl;
        return 1;
    }
    try {
        int id = add_expense(description, amount);
        std::cout << "Expense added successfully (ID: " << id << ")" << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error adding expense: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
int tracker::list_command(int argc, char **argv) {
    return 0;
}
int tracker::update_command(int argc, char **argv) {
    return 0;
}
int tracker::delete_command(int argc, char **argv) {
    return 0;
}
int tracker::summary_command(int argc, char **argv) {
    return 0;
}
int tracker::print_help(int argc, char **argv) {
    return 0;
}