#include "DataBus.h"

#include <iostream>

abc::DataBus& abc::DataBus::instance()
{
    static abc::DataBus instance;
    return instance;
}

sqlite3* abc::DataBus::openDatabase()
{
    if (abc::DataBus::instance().db != nullptr)
    {
        return abc::DataBus::instance().db;
    }

    if (sqlite3_open("account_book.db", &abc::DataBus::instance().db) != SQLITE_OK)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(abc::DataBus::instance().db) << std::endl;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    return abc::DataBus::instance().db;
}

void abc::DataBus::closeDatabase()
{
    if (abc::DataBus::instance().db != nullptr)
    {
        sqlite3_close(abc::DataBus::instance().db);
        abc::DataBus::instance().db = nullptr;
    }
}