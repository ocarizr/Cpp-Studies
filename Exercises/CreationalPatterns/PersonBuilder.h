#ifndef PERSON_BUILDER_H
#define PERSON_BUILDER_H

#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

class PersonBuilder : public Details::PersonBuilderBase
{
    Person person;

public:
    PersonBuilder()
    : Details::PersonBuilderBase(person)
    {
    }
};

#endif // !PERSON_BUILDER_H
