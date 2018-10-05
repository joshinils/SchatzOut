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
		Invalid = -1,
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
			return Invalid;
		return _brett[z][s];
	}	// get value of position
	
	int get(std::pair<int, int> pos) const
	{
		if (pos.first >= squareSize || pos.second >= squareSize)
			return Invalid;
		return _brett[pos.first][pos.second];
	}

	// change board state by revealing one position
	int reveal(std::pair<int, int> pos)
	{
		if (pos == _schatzPosition)
			_brett[pos.first][pos.second] = Treasure;
		if (pos.first >= squareSize || pos.second >= squareSize)
			return -1;
		switch (pos.first)
		{
		case 0:
			switch (pos.second)
			{
			case 0: // upper left corrner
			{
				// check neighbors
				if (   (_schatzPosition.first == 0 && _schatzPosition.second == 1) 
					|| (_schatzPosition.first == 1 && _schatzPosition.second == 0) )
				{
					_brett[0][0] = Neighboring;
					_brett[0][1] = PossibleTreasure;
					_brett[1][0] = PossibleTreasure;
					return Neighboring;
				}
			}
			break;
			case 1:
			case 2:
			case 3:
			case 4:
				//todo
				break;

			case 5:
				// todo
				break;

			default:
				return Invalid;
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
				//todo
				break;

			case 1:
			case 2:
			case 3:
			case 4:
				//todo
				break;

			case 5:
				// todo
				break;

			default:
				return Invalid;
				break;
			}
			break;

		case 5:
			switch (pos.second)
			{
			case 0:
				//todo
				break;

			case 1:
			case 2:
			case 3:
			case 4:
				//todo
				break;

			case 5:
				// todo
				break;

			default:
				return Invalid;
				break;
			}
			break;

		default:
			return Invalid;
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