#include "User.h"
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<User> User::users;
User::User(const std::string& uname,const std::string& pass,const std::string& r): username(uname), password(pass), role(r) {}
User::loadUsersFromFile(){}//JANAK

bool User::loginUser(const std::string& uname, const std::string& pass){
    for(const auto &user:users){
        if (user.username == uname){
            if(user.password == pass){
                return true;
            }
        }

    }
    return false;
}

bool User::registerUser(const std::string &uname,const std::string &pass,const std::string &r){
    for(const auto &user:users){
        if (user.username == uname){
            std::cout<<"User already registered!\n";
            return false;
        }
        //save to file
    }
}

bool User::isAdmin(const std::string& uname){
    for(const auto &user:users){
        if (user.username == uname){
            return(user.role == "admin");
        }
    }
    return false;
}


