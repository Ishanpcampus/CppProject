//
// Created by ishan on 7/9/25.
//
#include "Date.h"
#include <iostream>

Date::Date() : year(2000), month(1), day(1) {}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

void Date::setDate() {
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter day: ";
    std::cin >> day;
}

void Date::setYear(int y) {
    year = y;
}
void Date::setMonth(int m) {
    month = m;
}
void Date::setDay(int d) {
    day = d;
}

int Date::getYear() const {
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}