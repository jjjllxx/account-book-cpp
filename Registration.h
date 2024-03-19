#pragma once

#include <string>
namespace abc
{
namespace Registration
{
    void registerUser();
    bool insertToDatabase(const std::string& name,
                          const std::string& pw);
    bool isNameValid(const std::string& name);
    bool isPasswordValid(const std::string& pw);

} // namespace Registration
} // namespace abc