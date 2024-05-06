#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& filename);
    ~Database();

    bool open();
    void close();
    bool insertUser(const std::string& firstname, const std::string& lastname, const std::string& username, const std::string& password);
    bool insertTransaction(const float& amount, const std::string& transaction_type, const std::string& date, std::string& username);


private:
    sqlite3 *db;
    std::string filename;
};

#endif // DATABASE_H
