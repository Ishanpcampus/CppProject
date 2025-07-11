#ifndef INVENTORY_H
#define INVENTORY_H
#include<vector>
#include<iostream>
#include<fstream>
#include <string>

struct Item{
    std::string itemName;
    int quantity;
    double price;
};

class Inventory {
private:
    std::vector<Item> items;

public:
    Inventory();
    //void input();
    void addItem();
    void updatePrice(const std:: string nam, const int& p);
    void updateQuantity(const std::string nam, const int& q);
    void viewInventory() const;
    double getPriceByName(const std::string& itemName) const;
    void saveInventoryToFile(const std::string& filename) const;
    void loadInventoryFromFile();
    void checkReorderAlerts();
};

#endif
