#include "Transaction.h"
#include "Date.h"
#include <iostream>
#include <sstream>
Transaction::Transaction() : account(), type(""), description(""), debit(0.0), credit(0.0), date() {}
Transaction::Transaction(const int& acc, const std::string &t, const Date& d, const std::string &desc, double deb, double cre):account(acc) ,type(t), date(d),description(desc), debit(deb), credit(cre) {}

//Input from user
void Transaction::input() {

    //Account number input
    std::cout << "Enter account number: ";
    std::cin >> account;

    //Type of transaction
    std::cout<<"Enter type of transaction (credit/debit): ";
    std::cin >>type;

    if(type!="credit" && type!="debit") {
        std::cerr<<"Wrong transaction type!\n Enter debit or credit"<<std::endl;
    }

    //Input Description
    std::cout<<"Enter description: ";
    std::cin.ignore();
    std::getline(std::cin,description);

    //Input Amount
    std::cout<<"Enter amount: ";
    if(type=="credit") {
        std::cin>>credit;
        debit = 0.0;
    }

    if(type=="debit") {
        std::cin>>debit;
        credit = 0.0;
    }

    //Input Date
    std::cout<<"Enter date: ";
    date.setDate();

}

//Displays user input data
void Transaction::display() const {
    std::cout<<"Type: "<<type<<std::endl;
    std::cout<<"Description: "<<description<<std::endl;
    std::cout<<"debit: "<<debit<<std::endl;
    std::cout<<"Credit: "<<credit<<std::endl;
    std::cout<<"Date: "<<date<<std::endl;
}

//Writting data to file
void Transaction::saveToFile(const std::string& filename) const {
//file kholne ani save garne ani amount save garda type == "credit" ? credit : -debit garne
}

