#include <iostream>
#include <string>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int year, int month) {
    static const int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days_per_month[month - 1];
}

int daysFromStartOfYear(int year, int month, int day) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(year, m);
    }
    days += day;
    return days;
}

int daysSinceReferenceDate(int year, int month, int day) {
    int days = 0;
    for (int y = 1; y < year; ++y) {
        days += isLeapYear(y) ? 366 : 365;
    }
    days += daysFromStartOfYear(year, month, day);
    return days;
}

int calculateDaysDifference(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days1 = daysSinceReferenceDate(year1, month1, day1);
    int days2 = daysSinceReferenceDate(year2, month2, day2);
    return days2 - days1;
}

int main() {
    int year1, month1, day1;
    int year2, month2, day2;

    std::cout << "Enter the first date (YYYY MM DD): ";
    std::cin >> year1 >> month1 >> day1;

    std::cout << "Enter the second date (YYYY MM DD): ";
    std::cin >> year2 >> month2 >> day2;

    int daysDifference = calculateDaysDifference(year1, month1, day1, year2, month2, day2);
    std::cout << "Number of days between dates: " << daysDifference << std::endl;

    return 0;
}