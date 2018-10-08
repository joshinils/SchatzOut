#include <iostream>
#include "Weg.h"
#include	 "Brett.h"
#include <array>

#include <cstdlib> // fuer rand()
const size_t ANZ_WEGE = 10;
const size_t ANZ_SCHRITTE = 10;

int koord(int max)
{
	return rand() % max;
}

int main()
{
	std::array<Weg, ANZ_WEGE> wege;
	std::array<Brett, Brett::squareSize * Brett::squareSize > Bretter;
	for (size_t i = 0; i < Bretter.size(); i++)
	{

	}

	for (size_t i = 0; i < ANZ_WEGE; i++)
	{
		for (size_t j = 0; j < ANZ_SCHRITTE; j++)
		{
			wege[i].push_back(std::make_pair(koord(Brett::squareSize), koord(Brett::squareSize)));
		}
	}

	return 0;
}