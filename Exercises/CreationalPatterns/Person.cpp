#include "pch.h"

#include "Person.h"
#include "PersonBuilder.h"

#include <iomanip>
#include <sstream>

PersonBuilder Person::create()
{
    return PersonBuilder();
}

std::string Person::str()
{
    std::stringstream ss;
    ss << m_address.str() << m_employment.str();
    return ss.str();
}

std::string Address::str()
{
    std::stringstream ss;
    ss << "Address data: " << number << " " << address << ", " << city << ", "
       << country << ". " << post_code << "\n";
    return ss.str();
}

std::string Employment::str()
{
    std::stringstream ss;
    ss << "Employment data: " << position << " at " << company
       << " earning annualy $" << annual_income << "\n";
    return ss.str();
}
