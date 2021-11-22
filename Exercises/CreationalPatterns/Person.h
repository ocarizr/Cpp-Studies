#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Address
{
    int number = 0;
    std::string address;
    std::string post_code;
    std::string city;
    std::string country;

    std::string str();
};

struct Employment
{
    std::string position;
    std::string company;
    float annual_income = 0.0f;

    std::string str();
};

class PersonBuilder;

class Person
{
public:
    static PersonBuilder create();

    std::string str();

private:
    Address m_address;
    Employment m_employment;

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};

#endif // !PERSON_H
