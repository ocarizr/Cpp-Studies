#include "pch.h"

#ifndef BUILDERFACADE_H
#define BUILDERFACADE_H

#include "PersonBuilder.h"

void RunBuilderFacade()
{
    Person person = Person::create()
                        .lives()
                        .at("The Glade, Citywest Demesne")
                        .in_number(10)
                        .in_city("Dublin")
                        .at_country("Ireland")
                        .with_postcode("D24 R80H")
                        .works()
                        .at("Demonware")
                        .as_a("Senior Software Engineer")
                        .earning(98000.0f);

    std::cout << person.str() << std::endl;
};

#endif // !BUILDERFACADE_H
