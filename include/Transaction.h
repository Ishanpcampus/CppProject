#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
public:
    std::string type;
    std::string date;
    std::string description;
    std::double amount;
private:
    Transaction();
    void input();
    void display() const;
    void saveToFile(const std::string filename) const;

};

#endif