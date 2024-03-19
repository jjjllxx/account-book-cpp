#pragma once

#include <sqlite3.h>

namespace abc
{
namespace Initialisation
{
    bool initialise();
    bool createUserTable(sqlite3* db);
    bool createIncomeTable(sqlite3* db);
    bool createExpenseTable(sqlite3* db);

} // namespace Initialisation
} // namespace abc