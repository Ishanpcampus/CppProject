#include <iostream>
#include <string>
#include <conio.h>

std::string getPassword() {
    std::string password;
    char ch;
    std::cout << "Enter your password: ";
    while ((ch = _getch()) != '\r') { // Enter key
        if (ch == '\b') { // Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password += ch;
            std::cout << '*'; // Mask input
        }
    }
    std::cout << std::endl;
    return password;
}

int main() {
    std::string pwd = getPassword();
    std::cout << "Password captured securely." << std::endl;
    return 0;
}
