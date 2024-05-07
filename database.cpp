#include "database.h"
#include <iostream>

Database::Database(const std::string& filename) : db(nullptr), filename(filename) {}

Database::~Database() {
    close();
}

bool Database::open() {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::insertUser(const std::string& firstname, const std::string& lastname, const std::string& username, const std::string& password) {
    std::string sql = "INSERT INTO users (firstname, lastname, username, password) VALUES (?,?,?,?);";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, firstname.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, lastname.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, password.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}


bool Database::insertFinRecords(const float& Amont, const std::string& Description, const std::string& Date, const int& UserID, const int& FinTypeID) {
    std::string sql = "INSERT INTO Fin_records (ID, Amont, Description, Date, UserID, FinTypeID) VALUES (?, ?, ?,?,?,?)";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_double(stmt, 1, static_cast<double>(Amont));
    sqlite3_bind_text(stmt, 2, Description.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, Date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, static_cast<int>(UserID));
    sqlite3_bind_int(stmt, 5, static_cast<int>(FinTypeID));

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}