// CreationalPatterns.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "functions.h"

#include "Builder.h"
#include "BuilderFacade.h"
#include "GroovyBuilder.h"

namespace CreationalPatterns
{
void Run()
{
    RunBuilder();
    RunGroovyBuilder();
    RunBuilderFacade();
}
} // CreationalPatterns
