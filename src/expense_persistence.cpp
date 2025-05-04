#include <string>
#include <fstream>
#include <filesystem>
#include "../include/expense_persistence.hpp"
#include "../include/expense_util.hpp"

constexpr char const *NEXT_ID_FILE = "next_id";
constexpr char const *EXPENSE_DATA_FILE = "expense_data.csv";
constexpr char const *EXPENSE_DATA_HEADER = "ID,Date,Description,Amount\n";

namespace tracker {
    void set_next_id(int);
    std::string expense_to_string(Expense &);
}
int tracker::get_next_id() {
    std::ifstream file(NEXT_ID_FILE);
    int id {1};
    if(file.is_open()) {
        file >> id;
        file.close();
    }
    set_next_id(id + 1);
    return id;
}
void tracker::set_next_id(int id) {
    std::ofstream file(NEXT_ID_FILE);
    if(file.is_open()) {
        file << id;
        file.close();
    }
}
void tracker::add_expense_to_file(Expense &expense) {
    bool file_exists = std::filesystem::exists(EXPENSE_DATA_FILE);
    std::ofstream file(EXPENSE_DATA_FILE, std::ios::app);
    if(file.is_open()) {
        if(!file_exists) {
            file << EXPENSE_DATA_HEADER;
        }
        file << expense_to_string(expense);
        file.close();
    }
}
std::string tracker::expense_to_string(Expense &expense) {
    return std::to_string(expense.id) + "," + expense.date + ",\""
           + expense.description + "\"," + format_currency(expense.amount)
           + "\n";
}