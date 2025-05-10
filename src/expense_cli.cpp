#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>
#include "../include/expense_cli.hpp"
#include "../include/expense_service.hpp"
#include "../include/expense_util.hpp"

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

    void print_expenses(const std::vector<Expense> &);
    size_t get_width(const std::string &);
    std::string set_text_wwidth(const std::string &, size_t, char = 'c');
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
    if(argc != 2) {
        std::cerr << "Invalid number of arguments for list command" << '\n'
                  << "Usage: " << argv[0] << " list" << std::endl;
        return 1;
    }
    auto expenses = list_expenses();
    if(expenses.empty()) {
        std::cout << "No expenses found" << std::endl;
        return 0;
    }
    print_expenses(expenses);
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

void tracker::print_expenses(const std::vector<Expense> &expenses) {
    size_t max_id_width = 2;
    size_t max_description_width = 11;
    size_t max_amount_width = 6;
    for(const auto &expense: expenses) {
        max_id_width = std::max(max_id_width, get_width(std::to_string(expense.id)));
        max_description_width = std::max(max_description_width, get_width(expense.description));
        max_amount_width = std::max(max_amount_width, get_width(format_currency(expense.amount)) + 1);
    }
    std::cout << set_text_wwidth("ID", max_id_width, 'c') << ' '
              << set_text_wwidth("Date", 10, 'c') << ' '
              << set_text_wwidth("Description", max_description_width, 'c') << ' '
              << set_text_wwidth("Amount", max_amount_width, 'c') << std::endl;
    if(expenses.empty()) {
        std::cout << set_text_wwidth("No expenses found", (10 + max_id_width + max_description_width + max_amount_width));
        return;
    }
    for(const auto &expense: expenses) {
        std::cout << set_text_wwidth(std::to_string(expense.id), max_id_width, 'r') << ' '
                  << set_text_wwidth(expense.date, 10, 'c') << ' '
                  << set_text_wwidth(expense.description, max_description_width, 'l') << ' '
                  << set_text_wwidth("$" + format_currency(expense.amount), max_amount_width, 'r')
                  << std::endl;
    }
}
size_t tracker::get_width(const std::string &str) {
    size_t count {0};
    for(unsigned char c: str) {
        if((c & 0xC0) != 0x80) {
            ++count;
        }
    }
    return count;
}
std::string tracker::set_text_wwidth(const std::string &str, size_t width, char align) {
    size_t str_width = get_width(str);
    if(str_width >= width) {
        return str;
    }
    size_t padding = width - str_width;
    size_t left_padding {0};
    size_t right_padding {0};
    if(align == 'l') {
        right_padding = padding;
    } else if(align == 'r') {
        left_padding = padding;
    } else if(align == 'c') {
        left_padding = padding / 2;
        right_padding = padding = left_padding;
    }
    return std::string(left_padding, ' ') + str + std::string(right_padding, ' ');
}