//
// Created by ishan on 7/9/25.
//

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "Transaction.h"
#include "Date.h"
#include <vector>

class TransactionManager {
  private:
  std::vector<Transaction> transactions;
  public:
  void addTransaction(const Transaction& transaction);
  bool removeTransaction(const std::string& filename, const std::string& account, const std::string& description);
  void loadFromFile(const std::string& filename);
  double calculateBalance(const std::string& account) const;
};
#endif //TRANSACTIONMANAGER_H
