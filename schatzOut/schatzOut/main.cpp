#include <iostream>
#include "Weg.h"
#include	 "Brett.h"
#include <array>

#include <cstdlib> // fuer rand()
const size_t ANZ_WEGE = 1;
const size_t ANZ_SCHRITTE = 10;

int koord(int max)
{
	return rand() % max;
}

void resetBretter(std::array<Brett, Brett::squareSize * Brett::squareSize>& bretter)
{
	for (size_t i = 0; i < bretter.size(); i++)
	{
		bretter[i].reset(std::make_pair(i / Brett::squareSize, i % Brett::squareSize));
	}
}

int main()
{
	std::array<Weg, ANZ_WEGE> wege;
	std::array<Brett, Brett::squareSize * Brett::squareSize> bretter;
	resetBretter(bretter);
	for (size_t i = 0; i < ANZ_WEGE; i++)
	{
		for (size_t j = 0; j < ANZ_SCHRITTE; j++)
		{
			wege[i].push_back(std::make_pair(koord(Brett::squareSize), koord(Brett::squareSize)));
		}
	}

	for (size_t i = 0; i < bretter.size(); i++)
	{
		int tries = 	bretter[i].applyWeg(wege[0]);
		std::cout << "tries:" << tries << std::endl;
		bretter[i].reset(std::make_pair(i / Brett::squareSize, i % Brett::squareSize));
	}

	return 0;
}
