#ifndef PERSON_JOB_BUILDER_H
#define PERSON_JOB_BUILDER_H

#include "PersonBuilderBase.h"

class PersonJobBuilder : public Details::PersonBuilderBase
{
    using self = PersonJobBuilder;

public:
    PersonJobBuilder(Person& p)
    : Details::PersonBuilderBase(p)
    {
    }

    self& earning(float annual_income)
    {
        m_person.m_employment.annual_income = annual_income;
        return *this;
    }

    self& at(std::string company)
    {
        m_person.m_employment.company = company;
        return *this;
    }

    self& as_a(std::string position)
    {
        m_person.m_employment.position = position;
        return *this;
    }
};

#endif // !PERSON_JOB_BUILDER_H
