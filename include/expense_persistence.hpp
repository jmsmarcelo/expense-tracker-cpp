#ifndef EXPENSE_PERSISTENCE_HPP
#define EXPENSE_PERSISTENCE_HPP

#include "../include/Expense.hpp"

namespace tracker {
    int get_next_id();
    void add_expense_to_file(Expense &);
}

#endif