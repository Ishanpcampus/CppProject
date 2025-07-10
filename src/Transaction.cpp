#include "Transaction.h"
#include "Date.h"
#include <iostream>
#include <sstream>
#include "Inventory.h"

Transaction::Transaction() : account(), type(""), description(""), debit(0.0),
credit(0.0), date() {}//sets default value


Transaction::Transaction(const int& acc, const std::string &t,
    const Date& d, const std::string &desc, double deb,
    double cre):account(acc) ,type(t), date(d),
description(desc), debit(deb), credit(cre) {}//sets value entered by the user

//Takes input from the user
void Transaction::input() {

    //Name
    std::cout << "Enter account number: ";
    std::cin >> account;

    //Type
    std::cout<<"Enter type of transaction (credit/debit): ";
    std::cin >>type;

    //Checks if the type is invalid
    if(type!="credit" && type!="debit") {
        std::cerr<<"Wrong transaction type!\n Enter debit or credit"<<std::endl;
    }
    
    //Description
    std::cout<<"Enter description: ";
    std::cin.ignore();//Clears the buffer containing new line character in the buffer due to cin or cerr
    std::getline(std::cin,description);//To input a whole line from standard input i.e keyboard

    //Amount
    std::cout<<"Enter amount: ";

    //checks if credit or debit and performs accordingly
    if(type=="credit") {
        std::cin>>credit;
        debit = 0.0;
    }

    if(type=="debit") {
        std::cin>>debit;
        credit = 0.0;
    }

    //Date of transaction
    std::cout<<"Enter date: ";
    date.setDate();

    return;
}

//Displays all the details entered by the user
void Transaction::display() const {
    std::cout<<"Type: "<<type<<std::endl;
    std::cout<<"Description: "<<description<<std::endl;
    std::cout<<"debit: "<<debit<<std::endl;
    std::cout<<"Credit: "<<credit<<std::endl;
    std::cout<<"Date: "<<date<<std::endl;
}

//Saves all details to the file
void Transaction::saveToFile(const std::string& filename) const {
//file kholne ani save garne ani amount save garda type == "credit" ? credit : -debit garne
/*std::ofstream infile(filename, std::ios::app);
     if (!infile) {
        std::cerr << "error opening file for writing\n";
        return;
     }
      double amount = (type == "credit") ? credit : -debit;
     infile<<"Account no\t\tTypes\t\tdescription\t\tdebit\t\tcredit\t\t amount \t\t date\n";
     infile<<account<<"\t\t"<<type<<"\t\t"<<description<<"\t\t"<<debit<<"\t\t"<<credit<<"\t\t"<<amount<<"\t\t"<<date;
   

    infile<<"\n---------------------------------\n";
    infile.close(); */
    
    //opens file in append mode and binds with a ofstream object
    std::ofstream outfile(filename, std::ios::app);

    //Checks if there is error in opening the file
    if (!outfile) {
        std::cerr << "error opening file: " << filename << "\n";
        return;
    }

   //Saving details in file
    outfile << account << ","
            << type << ","
            << description << ","
            << debit << ","
            << credit << ","
            << date.getDay() << "/" << date.getMonth() << "/" << date.getYear()
            << "\n";

    //file closed
    outfile.close();

    return;
}

