#ifndef EXPENSE_SERVICE_HPP
#define EXPENSE_SERVICE_HPP

#include <string>
#include <vector>
#include "../include/Expense.hpp"

namespace tracker {
    int add_expense(const std::string &, double);
    std::vector<Expense> list_expenses();
}

#endif