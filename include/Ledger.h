#ifndef LEDGER_H
#define LEDGER_H

#include <vector>
#include <string>

class LedgerEntry {
public:
    std::string username;
    std::string date;
    std::string type;
    double amount;
    std::string description;

    LedgerEntry(const std::string& u, const std::string& d, const std::string& t, double a, const std::string& desc);
    void display() const;
};

class Ledger {
private:
    std::vector<LedgerEntry> entries;

public:
    void loadFromFile(const std::string& filename);
    void addEntry(const LedgerEntry& entry);
    void saveToFile(const std::string& filename) const;
    void displayAll() const;
};

#endif
