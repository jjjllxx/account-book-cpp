#include "Initialisation.h"
#include "DataBus.h"
#include <iostream>
#include <sqlite3.h>

bool abc::Initialisation::initialise()
{
    if (abc::Initialisation::createUserTable() == false)
    {
        return false;
    }

    if (abc::Initialisation::createIncomeTable() == false)
    {
        return false;
    }

    if (abc::Initialisation::createExpenseTable() == false)
    {
        return false;
    }

    return true;
}

bool abc::Initialisation::createUserTable()
{
    const char* sql = "CREATE TABLE IF NOT EXISTS USER("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "NAME           TEXT    NOT NULL,"
                      "PASSWORD       TEXT    NOT NULL );";

    char* errMsg = nullptr;
    if (sqlite3_exec(abc::DataBus::openDatabase(), sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
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

bool abc::Initialisation::createIncomeTable()
{
    const char* sql = "CREATE TABLE IF NOT EXISTS INCOME ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "DESCRIPTION TEXT,"
                      "TYPE TEXT NOT NULL,"
                      "AMOUNT REAL NOT NULL,"
                      "DATE DATE NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(abc::DataBus::openDatabase(), sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
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

bool abc::Initialisation::createExpenseTable()
{
    const char* sql = "CREATE TABLE IF NOT EXISTS EXPENSE ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "DESCRIPTION TEXT,"
                      "TYPE TEXT NOT NULL,"
                      "AMOUNT REAL NOT NULL,"
                      "DATE DATE NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(abc::DataBus::openDatabase(), sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
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