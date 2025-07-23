#include<iostream>
#include "Inventory.h"
#include<fstream>

Inventory::Inventory(){}//Nothing just a default constructor
//to get price of item
double Inventory::getPriceByName(const std::string& itemName) const {
    for (const Item& I : items) {
        if (I.itemName == itemName)
            return I.price;
    }
    return -1; // Item not found
}

//Adds Items in the inventory
void Inventory::addItem()
{
    int n;
    std::cout<<"Enter the no. of items you want to add: ";
    std::cin>>n;

    //Manipulating vector using a simple loop
    for(int i=0; i<n; i++){

        Item I;
        std::cout<<"Enter the name of the "<<i+1<<" th item: "; 
        std::cin>>I.itemName;

        std::cout<<"Enter the quantity of the item: ";
        std::cin>>I.quantity;

        std::cout<<"Enter the price of the item: ";
        std::cin>>I.price;

        items.push_back(I);//Think like appending the structure I to the vector items
        
    }

    return;
}

//Updates price if needed
void Inventory::updatePrice(const std::string nam, const int &p)
{

//This is called for each loop. Think like all the vector members are loaded to the variable in left
    for( Item &I: items){
        if(nam == I.itemName){
            I.price = p;
        }
    }

    return;
}

//Updates inventory based on the quantity
void Inventory::updateQuantity(const std::string nam, const int& q)
{
    for(Item &I: items){
        if(nam == I.itemName){
            I.quantity += q;
        }
    }

    //I will also add some code here to check if the quantity is 0 and then remove it

    return;
}

//Displays Item in the inventory
void Inventory::viewInventory() const
{
    for(const Item& I: items){
        std::cout<<"Name of item: "<<I.itemName<<std::endl<<"Quantity of item: "<<I.quantity<<
            std::endl<<"Price of Item: "<<I.price<<std::endl;
        
        std::cout<<"\n";
    }

    return;
}
//function to return inventory for balance sheet
const std::vector<Item> &Inventory::getItems() const {
    return items;
}


//Writes all items present in the vector to the file
/*void Inventory::saveInventoryToFile("data/inventory.txt") const
{
    std::ofstream outfile("inventory.txt", std::ios::app);

    for(const Item& I: items){
        outfile<<I.itemName<<std::endl;
        outfile<<I.quantity<<std::endl;
        outfile<<I.price<<std::endl;
    }

    return;
}

//In future I will also add a code here to clear all the inventory

//Reads all items from the inventory and assigns them to the vector
void Inventory::loadInventoryFromFile()
{
    std::ifstream infile("data/inventory.txt");

    while(!EOF){
        Item I;
        infile>>I.itemName;
        infile>>I.quantity;
        infile>>I.price;
        items.push_back(I);
    }

    return;
}

//Checks if the item is less than or equal to 15 and displays an alert message if it does
void Inventory::checkReorderAlerts()
{
    for(const Item I: items){
        if(I.quantity <= 15){
            std::cout<<"The "<<I.itemName<<" is almost finished!!! You may reorder it."<<std::endl;
        }
    }

    return;
}
*/