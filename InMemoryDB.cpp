#include "InMemoryDB.h"
#include <unordered_map>
#include <stdexcept>
#include <string>
using namespace std;

InMemoryDB::InMemoryDB() : inTransaction(false) {}

void InMemoryDB::begin_transaction() {
    if (inTransaction) {
        throw logic_error("A transaction is already in progress.");
    }
    inTransaction = true;
}

void InMemoryDB::put(string key, int val) {
    if (!inTransaction) {
        throw logic_error("No transaction is in progress.");
    }
    tempData[key] = val;
}

int InMemoryDB::get(string key) {
    if (data.find(key) != data.end()) {
        return data[key];
    } 
    else {
        return -1; // Return -1 if key not found
    }
}

void InMemoryDB::commit() {
    if (!inTransaction) {
        throw logic_error("No transaction is in progress.");
    }
    data.insert(tempData.begin(), tempData.end());
    tempData.clear();
    inTransaction = false;
}

void InMemoryDB::rollback() {
    if (!inTransaction) {
        throw logic_error("No transaction is in progress.");
    }
    tempData.clear();
    inTransaction = false;
}
