#include <iostream>
#include <sqlite3.h>

int main()
{
    // Open a connection to the database
    sqlite3* db = nullptr;

    if (sqlite3_open("account_book.db", &db) != SQLITE_OK)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Create SQL statement
    const char* sql = "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY     NOT NULL,"
                      "NAME           TEXT    NOT NULL,"
                      "AGE            INT     NOT NULL,"
                      "ADDRESS        CHAR(50),"
                      "SALARY         REAL );";

    // Execute SQL statement
    char* errorMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errorMsg) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errorMsg << std::endl;
        sqlite3_free(errorMsg);
    }
    else
    {
        std::cout << "Table created successfully" << std::endl;
    }

    // Close the connection
    sqlite3_close(db);

    return 0;
}
