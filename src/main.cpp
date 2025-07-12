#include <iostream>
#include "Inventory.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "Ledger.h"

int main() {
    Inventory inventory;
    TransactionManager transactionManager;
    Ledger ledger;

    transactionManager.loadFromFile("transaction.txt");

    bool running = true;
    while (running) {
        int choice;
        std::cout << "\n📘 Welcome to AccountingApp 📘\n";
        std::cout << "----------------------------------\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View All Transactions\n";
        std::cout << "3. Add Items to Inventory\n";
        std::cout << "4. View Inventory\n";
        std::cout << "5. View Ledger for Account\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Transaction transaction;
                transaction.input(inventory);  // Item price lookup from inventory
                transactionManager.addTransaction(transaction);
                transaction.saveToFile("data/transaction.txt");
                break;
            }
            case 2: {
                std::vector<Transaction> txs = transactionManager.getAllTransactions();
                for (const auto& t : txs) {
                    t.display();
                }
                break;
            }
            case 3: {
                inventory.addItem();
                break;
            }
            case 4: {
                inventory.viewInventory();
                break;
            }
            case 5: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                ledger.loadFromTransactions(transactionManager.getAllTransactions());
                ledger.displayStyledLedger(accountNumber);
                break;
            }
            case 6: {
                running = false;
                std::cout << "🔚 Exiting AccountingApp... Bye, Ishan!\n";
                break;
            }
            default:
                std::cout << "❌ Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
