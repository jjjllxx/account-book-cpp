#pragma once

#include <sqlite3.h>

namespace abc
{
class DataBus
{
public:
    static abc::DataBus& instance();

    static sqlite3* openDatabase();
    static void     closeDatabase();

private:
    DataBus() = default;
    sqlite3* db;

public:
    DataBus(DataBus const&)        = delete;
    void operator=(DataBus const&) = delete;
};
} // namespace abc
