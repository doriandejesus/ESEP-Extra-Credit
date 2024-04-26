#include <string>
#include <unordered_map>
using namespace std;

class InMemoryDB {
private:
    unordered_map<string, int> data; // Key-value store
    unordered_map<string, int> tempData; // Temporary storage for transaction changes
    bool inTransaction;
    
public:
    InMemoryDB();
    virtual int get(string key);
    virtual void put(string key, int val);
    virtual void begin_transaction();
    virtual void commit();
    virtual void rollback();

    virtual ~InMemoryDB() {} // Adding a virtual destructor for polymorphic behavior
};
