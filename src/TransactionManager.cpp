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

double TransactionManager::calculateBalance(const std::string &account) const {
    double balance = 0.0;
    for (const auto &t : transactions) {
        balance += t.credit;
        balance -= t.debit;
        return balance;
    }
}
