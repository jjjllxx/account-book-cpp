#include "Initialisation.h"
#include <iostream>

bool abc::Initialisation::initialise()
{
    sqlite3* db = nullptr;

    if (sqlite3_open("account_book.db", &db) != SQLITE_OK)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    if (abc::Initialisation::createUserTable(db) == false)
    {
        return false;
    }

    if (abc::Initialisation::createIncomeTable(db) == false)
    {
        return false;
    }

    if (abc::Initialisation::createExpenseTable(db) == false)
    {
        return false;
    }

    sqlite3_close(db);

    return true;
}

bool abc::Initialisation::createUserTable(sqlite3* db)
{
    const char* sql = "CREATE TABLE IF NOT EXISTS USER("
                      "ID INT PRIMARY KEY     NOT NULL,"
                      "NAME           TEXT    NOT NULL,"
                      "PASSWORD       TEXT    NOT NULL );";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);

        return false;
    }
    else
    {
        std::cout << "Table 'USER' created successfully or already exists." << std::endl;

        return true;
    }
}

bool abc::Initialisation::createIncomeTable(sqlite3* db)
{
    const char* sql = "CREATE TABLE IF NOT EXISTS INCOME ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "DESCRIPTION TEXT,"
                      "TYPE TEXT NOT NULL,"
                      "AMOUNT REAL NOT NULL,"
                      "DATE DATE NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);

        return false;
    }
    else
    {
        std::cout << "Table 'INCOME' created successfully or already exists." << std::endl;

        return true;
    }
}

bool abc::Initialisation::createExpenseTable(sqlite3* db)
{
    const char* sql = "CREATE TABLE IF NOT EXISTS EXPENSE ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "DESCRIPTION TEXT,"
                      "TYPE TEXT NOT NULL,"
                      "AMOUNT REAL NOT NULL,"
                      "DATE DATE NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);

        return false;
    }
    else
    {
        std::cout << "Table 'EXPENSE' created successfully or already exists." << std::endl;

        return true;
    }
}