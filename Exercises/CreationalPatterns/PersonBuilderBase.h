#ifndef PERSON_BUILDER_BASE_H
#define PERSON_BUILDER_BASE_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

namespace Details
{
class PersonBuilderBase
{
protected:
    Person& m_person;

public:
    PersonBuilderBase(Person& p)
    : m_person(p)
    {
    }

    PersonAddressBuilder lives() const;

    PersonJobBuilder works() const;

    operator Person() const { return std::move(m_person); }
};
} // Details

#endif // !PERSON_BUILDER_BASE_H
