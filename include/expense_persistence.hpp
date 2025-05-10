#ifndef EXPENSE_PERSISTENCE_HPP
#define EXPENSE_PERSISTENCE_HPP

#include <vector>
#include "../include/Expense.hpp"

namespace tracker {
    int get_next_id();
    void add_expense_to_file(Expense &);
    std::vector<Expense> get_expenses_from_file();
    void update_expense_file(std::vector<Expense> &);
}

#endif