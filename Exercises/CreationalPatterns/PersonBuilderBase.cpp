#include "pch.h"

#include "PersonBuilderBase.h"

#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder Details::PersonBuilderBase::lives() const
{
    return PersonAddressBuilder(m_person);
}

PersonJobBuilder Details::PersonBuilderBase::works() const
{
    return PersonJobBuilder(m_person);
}
