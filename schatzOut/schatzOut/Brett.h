#ifndef BRETT_H
#define BRETT_H

#include "Weg.h"
#include <array>

class Brett
{
public:
	static const int squareSize = 6;

	enum BitField
	{
		InvalidPos = -1,
		Unexplored = 0,
		Empty = 1,
		Neighboring = 2,
		Treasure = 4,
		PossibleTreasure = 8
	};

private:
	std::array<std::array<int, squareSize>, squareSize> _brett;
	std::pair<int, int> _schatzPosition;

public:
	Brett()
	{
		for (int zeile = 0; zeile < squareSize; zeile++)
		{
			for (int spalte = 0; spalte < squareSize; spalte++)
			{
				_brett[zeile][spalte] = 0;
			}
		}
	}

	// get value of position
	int get(size_t z, size_t s) const
	{
		if (z >= squareSize || s >= squareSize)
			return InvalidPos;
		return _brett[z][s];
	}	// get value of position
	
	int get(std::pair<int, int> pos) const
	{
		if (pos.first >= squareSize || pos.second >= squareSize)
			return InvalidPos;
		return _brett[pos.first][pos.second];
	}

	int revealCornerUpperLeft()
	{
		if (   (_schatzPosition.first == 0 && _schatzPosition.second == 1)
			|| (_schatzPosition.first == 1 && _schatzPosition.second == 0) )
		{
			_brett[0][0] = Neighboring;
			_brett[0][1] = PossibleTreasure;
			_brett[1][0] = PossibleTreasure;
			return Neighboring;
		}
		return _brett[0][0] = Empty;
	}

	int revealCornerUpperRight()
	{
		if (   (_schatzPosition.first == 0 && _schatzPosition.second == 5)
			|| (_schatzPosition.first == 1 && _schatzPosition.second == 4))
		{
			_brett[0][5] = Neighboring;
			_brett[0][5] = PossibleTreasure;
			_brett[1][4] = PossibleTreasure;
			return Neighboring;
		}
		return _brett[0][5] = Empty;
	}

	int revealCornerLowerLeft()
	{
		if (   (_schatzPosition.first == 4 && _schatzPosition.second == 0)
			|| (_schatzPosition.first == 5 && _schatzPosition.second == 1) )
		{
			_brett[5][0] = Neighboring;
			_brett[4][0] = PossibleTreasure;
			_brett[5][1] = PossibleTreasure;
			return Neighboring;
		}
		return _brett[5][0] = Empty;
	}

	int revealCornerLowerRight()
	{
		if (   (_schatzPosition.first == 5 && _schatzPosition.second == 4)
			|| (_schatzPosition.first == 4 && _schatzPosition.second == 5) )
		{
			_brett[5][5] = Neighboring;
			_brett[5][4] = PossibleTreasure;
			_brett[4][5] = PossibleTreasure;
			return Neighboring;
		}
		return _brett[5][5] = Empty;
	}

	// change board state by revealing one position
	int reveal(std::pair<int, int> pos)
	{
		if (pos == _schatzPosition)
			return _brett[pos.first][pos.second] = Treasure;
		if (pos.first >= squareSize || pos.second >= squareSize)
			return InvalidPos;
		switch (pos.first)
		{
		case 0:
			switch (pos.second)
			{
			case 0:
				return revealCornerUpperLeft();
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				//upper middle
				break;

			case 5:
				return revealCornerUpperRight();
				break;

			default:
				return InvalidPos;
				break;
			}
			break;

		case 1:
		case 2:
		case 3:
		case 4:
			switch (pos.second)
			{
			case 0:
				// left middle
				break;

			case 1:
			case 2:
			case 3:
			case 4:
				//middle middle
				break;

			case 5:
				// middle right
				break;

			default:
				return InvalidPos;
				break;
			}
			break;

		case 5:
			switch (pos.second)
			{
			case 0:
				// bottom left corner
				break;

			case 1:
			case 2:
			case 3:
			case 4:
				//bottomm middle
				break;

			case 5:
				// bottom right corner
				break;

			default:
				return InvalidPos;
				break;
			}
			break;

		default:
			return InvalidPos;
			break;
		}
	}

	//apply Weg, return tries
	int applyWeg(const Weg& w) const
	{
		int versuche = 0;
		for (versuche = 0; versuche < w.size(); versuche++)
		{
			std::pair<int, int> position = w.at(versuche);

		}
	}

	~Brett() = default;
};

#endif //BRETT_H