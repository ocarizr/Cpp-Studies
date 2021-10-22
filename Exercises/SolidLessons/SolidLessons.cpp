// SolidLessons.cpp : Defines the functions for the static library.
//

#include "pch.h"

namespace SolidLessons
{
	// TODO: This is an example of a library function
	void SolidFunctions()
	{
		SRP srp;
		srp.Execute();

		OCP ocp;
		ocp.Execute();

		DIP dip;
		dip.Execute();
	}
}
