#include <sstream>
#include <iomanip>
#include "../include/expense_util.hpp"

namespace tracker {
    tm *get_current_time();
    std::string format_tm(const char *, tm *);
}
std::string tracker::get_today(const char *format) {
    auto ltm = get_current_time();
    return format_tm(format, ltm);
}
tm *tracker::get_current_time() {
    time_t now = time(0);
    return localtime(&now);
}
std::string tracker::format_tm(const char *format, tm *time) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), format, time);
    return std::string(buffer);
}
std::string tracker::format_currency(double amount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}