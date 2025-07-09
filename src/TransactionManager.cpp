//
// Created by ishan on 7/9/25.
//
#include "TransactionManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

void TransactionManager::addTransaction(const Transaction &t) {
    transactions.push_back(t);
}
void TransactionManager::addTransaction(const Transaction &t) {
    //work for you janak
    /*    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Unable to open file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string acc, type, desc, amountStr, dateStr;
        std::getline(ss, acc, ',');
        std::getline(ss, type, ',');
        std::getline(ss, desc, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, dateStr);

        double debit = 0.0, credit = 0.0;
        double amt = std::stod(amountStr);
        if (type == "credit") credit = amt;
        else debit = -amt;

        Transaction t(acc, type, Date(), desc, debit, credit);
        transactions.push_back(t);
    }

    file.close();
}code by chatgpt*/
}
double TransactionManager::calculateBalance(const std::string &account) const {
    double balance = 0.0;
    for (const auto &t : transactions) {
        balance += t.credit;
        balance -= t.debit;
        return balance;
    }
}
