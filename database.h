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
    bool insertFinRecords(const float& Amont, const std::string& Description, const std::string& Date, const int& UserID, const int& FinTypeID);


private:
    sqlite3 *db;
    std::string filename;
};

#endif // DATABASE_H
