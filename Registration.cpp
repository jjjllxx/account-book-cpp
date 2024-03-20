#include "Registration.h"
#include "DataBus.h"
#include <cctype>
#include <iostream>
#include <string>

void abc::Registration::registerUser()
{
    std::string name;

    while (abc::Registration::isNameValid(name) == false)
    {
        std::cout << "Please enter user name:\n"
                     "1. length from 3 to 10.\n"
                     "2. Start with english letter.\n"
                     "3. Only containes english letter and _\n";
        std::cin >> name;
    }

    while (abc::Registration::isNameValid(name) == false)
    {
        std::cout << "Please enter user name:\n"
                     "1. Length from 3 to 10.\n"
                     "2. Start with english letter.\n"
                     "3. Only containes english letter and _\n";
        std::cin >> name;
    }

    std::string pw1;
    while (abc::Registration::isPasswordValid(pw1) == false)
    {
        std::cout << "Please enter password(length from 8 to 20):\n";
        std::cin >> pw1;
    }

    std::string pw2;
    while (pw2 != pw1)
    {
        std::cout << "Please re-enter password(same as last one):\n";
        std::cin >> pw2;
    }

    if (insertToDatabase(name, pw1) == true)
    {
        std::cout << "Register successfully!" << std::endl;
    }
}

bool abc::Registration::insertToDatabase(const std::string& name,
                                         const std::string& pw)
{
    sqlite3* db = abc::DataBus::openDatabase();

    const char* sqlInsert = "INSERT INTO USER (NAME, PASSWORD) VALUES (?, ?);";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        abc::DataBus::closeDatabase();
        return false;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, pw.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        std::cerr << "Error inserting values: " << sqlite3_errmsg(db) << std::endl;
        abc::DataBus::closeDatabase();
        return false;
    }

    // Finalize the prepared statement and close the database
    sqlite3_finalize(stmt);

    return true;
}

bool abc::Registration::isNameValid(const std::string& name)
{
    if (name.size() < 3 || name.size() > 10)
    {
        return false;
    }

    if (std::isalpha(name.front()) == 0)
    {
        return false;
    }

    for (const char ch : name)
    {
        if (std::isalpha(ch) == 0 && std::isalnum(ch) == 0 && ch != '_')
        {
            return false;
        }
    }

    return true;
}

bool abc::Registration::isPasswordValid(const std::string& pw)
{
    if (pw.size() < 8 || pw.size() > 20)
    {
        return false;
    }

    int check = 0;

    for (const char c : pw)
    {
        if (c >= 'a' && c <= 'z')
        {
            check |= 1;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            check |= 2;
        }
        else if (c >= '0' && c <= '9')
        {
            check |= 4;
        }
        else
        {
            check |= 8;
        }
    }

    return check == 7 || check == 11 || check > 12;
}
