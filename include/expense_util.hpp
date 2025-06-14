#ifndef EXPENSE_UTIL_HPP
#define EXPENSE_UTIL_HPP

#include <string>

namespace tracker {
    std::string get_today(const char *format = "%Y-%m-%d");
    std::string get_month(int, const char *format = "%Y-%m");
    std::string format_currency(double);
}

#endif