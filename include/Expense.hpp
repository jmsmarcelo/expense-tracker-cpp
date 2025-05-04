#ifndef EXPENSE_HPP
#define EXPENSE_HPP

#include <string>

namespace tracker {
    struct Expense {
        int id {0};
        std::string date {""};
        std::string description {""};
        double amount {0.0};
    };
}

#endif