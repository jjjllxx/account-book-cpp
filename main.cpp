#include "Initialisation.h"
#include "Registration.h"

#include <iostream>

int main()
{
    if (abc::Initialisation::initialise() == true)
    {
        abc::Registration::registerUser();
    }

    return 0;
}