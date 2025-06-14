#ifndef EXPENSE_SERVICE_HPP
#define EXPENSE_SERVICE_HPP

#include <string>
#include <vector>
#include "../include/Expense.hpp"

namespace tracker {
    int add_expense(const std::string &, double);
    std::vector<Expense> list_expenses();
    bool update_expense(int, const std::string &, double);
    bool delete_expense(int);
    double get_summary(int month = -1);
}

#endif