#include "DataBus.h"
#include "Initialisation.h"
#include "Registration.h"

#include <iostream>

int main()
{
    if (abc::Initialisation::initialise() == true)
    {
        abc::Registration::registerUser();
    }

    abc::DataBus::closeDatabase();

    return 0;
}