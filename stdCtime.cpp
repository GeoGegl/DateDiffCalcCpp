#include <iostream>
#include <ctime>
#include <string>

std::tm createDate(int year, int month, int day) {
    std::tm date = {};
    date.tm_year = year - 1900; // Year since 1900
    date.tm_mon = month - 1;    // 0-based month
    date.tm_mday = day;
    return date;
}

int calculateDaysDifference(const std::tm& start, const std::tm& end) {
    std::time_t start_time = std::mktime(const_cast<std::tm*>(&start));
    std::time_t end_time = std::mktime(const_cast<std::tm*>(&end));
    double difference = std::difftime(end_time, start_time) / (60 * 60 * 24);
    return static_cast<int>(difference);
}

int main() {
    int year1, month1, day1;
    int year2, month2, day2;

    std::cout << "Enter the first date (YYYY MM DD): ";
    std::cin >> year1 >> month1 >> day1;

    std::cout << "Enter the second date (YYYY MM DD): ";
    std::cin >> year2 >> month2 >> day2;

    std::tm date1 = createDate(year1, month1, day1);
    std::tm date2 = createDate(year2, month2, day2);

    int daysDifference = calculateDaysDifference(date1, date2);
    std::cout << "Number of days between dates: " << daysDifference << std::endl;

    return 0;
}
