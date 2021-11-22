#ifndef PERSON_ADDRESS_BUILDER_H
#define PERSON_ADDRESS_BUILDER_H

#include "PersonBuilderBase.h"

class PersonAddressBuilder : public Details::PersonBuilderBase
{
    using self = PersonAddressBuilder;

public:
    PersonAddressBuilder(Person& p)
    : Details::PersonBuilderBase(p)
    {
    }

    self& at(std::string street_address)
    {
        m_person.m_address.address = street_address;
        return *this;
    }

    self& in_number(int house_number)
    {
        m_person.m_address.number = house_number;
        return *this;
    }

    self& with_postcode(std::string post_code)
    {
        m_person.m_address.post_code = post_code;
        return *this;
    }

    self& in_city(std::string city)
    {
        m_person.m_address.city = city;
        return *this;
    }

    self& at_country(std::string country)
    {
        m_person.m_address.country = country;
        return *this;
    }
};

#endif // !PERSON_ADDRESS_BUILDER_H
