#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"
#include <fstream>

class Transaction {
public:
    int account;
    std::string type;
    std::string description;
    double debit;
    double credit;
    Date date;

    Transaction();

    Transaction(const int& acc, const std::string &t,
        const Date& d, const std::string &desc,
        double deb, double cre);

    void input();

    void display() const;
    void saveToFile(const std::string& filename) const;
};

#endif // TRANSACTION_H