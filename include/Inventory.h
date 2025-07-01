#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory {
private:
    std::string itemName;
    int quantity;
    double price;

public:
    Inventory();
    void input();
    void display() const;
    void saveToFile(const std::string& filename) const;
};

#endif
