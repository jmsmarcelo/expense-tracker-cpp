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