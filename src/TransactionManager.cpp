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
void TransactionManager::loadFromFile(const std::string& filename ) {
    
std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << " Unable to open file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string accStr, natstr,itmstr,qun , ratstr,amoutstr,  desc, debitStr, creditStr, dateStr;

        std::getline(ss, accStr, ',');
        std::getline(ss, natstr, ',');
        std::getline(ss,itmstr,',');
        std::getline(ss,qun,',');
        std::getline(ss,ratstr,',');
         std::getline(ss,amoutstr,',');
        std::getline(ss, desc, ',');
       
        std::getline(ss, debitStr, ',');
        std::getline(ss, creditStr, ',');
        std::getline(ss, dateStr, ',');

        double rat=std::stod(ratstr);
        double am=std::stod(amoutstr);
        int quant=std::stoi(qun);
     
        int acc = std::stoi(accStr);
        double debit = std::stod(debitStr);
        double credit = std::stod(creditStr);

        // Parse date
        int day, month, year;
        char slash1, slash2;
        std::stringstream ds(dateStr);
        ds >> day >> slash1 >> month >> slash2 >> year;
/*account(0), type(""), nature(""), itemName(""), description(""),
      rate(0.0), amount(0.0), quantity(0),
      debit(0.0), credit(0.0), date() {}*/
        Date date(year, month, day);
        Transaction t(acc,natstr, itmstr ,desc, rat,  am, quant, desc, debit, credit ,date);
        transactions.push_back(t);
    }

    file.close();
}
double TransactionManager::calculateBalance(const std::string &account) const {
    double balance = 0.0;
    for (const auto &t : transactions) {
        balance += t.credit;
        balance -= t.debit;
        return balance;
    }
}
