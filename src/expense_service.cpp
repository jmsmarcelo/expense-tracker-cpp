#include "../include/expense_service.hpp"
#include "../include/Expense.hpp"
#include "../include/expense_persistence.hpp"
#include "../include/expense_util.hpp"

int tracker::add_expense(const std::string &description, double amount) {
    Expense expense;
    expense.id = get_next_id();
    expense.date = get_today();
    expense.description = description;
    expense.amount = amount;
    add_expense_to_file(expense);
    return expense.id;
}
std::vector<tracker::Expense> tracker::list_expenses() {
    return get_expenses_from_file();
}
bool tracker::update_expense(int id, const std::string &description, double amount) {
    std::vector<Expense> expenses = get_expenses_from_file();
    for(auto &expense: expenses) {
        if(expense.id == id) {
            if(!description.empty()) {
                expense.description = description;
            }
            if(amount > 0) {
                expense.amount = amount;
            }
            update_expense_file(expenses);
            return true;
        }
    }
    return false;
}
bool tracker::delete_expense(int id) {
    std::vector<Expense> expenses = get_expenses_from_file();
    for(auto it = expenses.begin(); it != expenses.end(); ++it) {
        if(it->id == id) {
            expenses.erase(it);
            update_expense_file(expenses);
            return true;
        }
    }
    return false;
}
double tracker::get_summary(int month) {
    std::string year;
    if(month == -1) year = get_today().substr(0, 4);
    std::vector<Expense> expenses = get_expenses_from_file();
    double total {0.0};
    for(const auto &expense: expenses) {
        if(month == -1 || expense.date.substr(0, 7) == get_month(month)) {
            total += expense.amount;
        }
    }
    return total;
}