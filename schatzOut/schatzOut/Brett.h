#ifndef BRETT_H
#define BRETT_H

#include "Weg.h"
#include <array>
#include <iostream>

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

	void init(const std::pair<int, int>& schatzPos)
	{
		_schatzPosition = schatzPos;
		for (int zeile = 0; zeile < squareSize; zeile++)
		{
			for (int spalte = 0; spalte < squareSize; spalte++)
			{
				_brett[zeile][spalte] = 0;
			}
		}
	}

public:

	// willnot set a SchatzPos, not initialize the board with 0s
	Brett() = default;

	Brett(const std::pair<int, int>& schatzPos)
	{
		init(schatzPos);
	}

	void reset(const std::pair<int, int>& schatzPos)
	{
		init(schatzPos);
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
			_brett[0][1] = PossibleTreasure;
			_brett[1][0] = PossibleTreasure;
			return _brett[0][0] = Neighboring;
		}
		return _brett[0][0] = Empty;
	}

	int revealCornerUpperRight()
	{
		if (   (_schatzPosition.first == 0 && _schatzPosition.second == squareSize-1)
			|| (_schatzPosition.first == 1 && _schatzPosition.second == squareSize-2))
		{
			_brett[0][squareSize-1] = Neighboring;
			_brett[0][squareSize-1] = PossibleTreasure;
			_brett[1][squareSize-2] = PossibleTreasure;
			return Neighboring;
		}
		return _brett[0][5] = Empty;
	}

	int revealCornerLowerLeft()
	{
		if (   (_schatzPosition.first == squareSize-2 && _schatzPosition.second == 0)
			|| (_schatzPosition.first == squareSize-1  && _schatzPosition.second == 1) )
		{
			_brett[squareSize-2][0] = PossibleTreasure;
			_brett[squareSize-1][1] = PossibleTreasure;
			return _brett[squareSize-1][0] = Neighboring;
		}
		return _brett[squareSize][0] = Empty;
	}

	int revealCornerLowerRight()
	{
		if (   (_schatzPosition.first == squareSize-1 && _schatzPosition.second == squareSize-2)
			|| (_schatzPosition.first == squareSize-2 && _schatzPosition.second == squareSize-1) )
		{
			_brett[squareSize-1][squareSize-2] = PossibleTreasure;
			_brett[squareSize-2][squareSize-1] = PossibleTreasure;
			return _brett[squareSize-1][squareSize-1] = Neighboring;
		}
		return _brett[squareSize-1][squareSize-1] = Empty;
	}

	int revealBorderTop(int spalte)
	{
		if (   (_schatzPosition.first == 0 && _schatzPosition.second == spalte - 1) // left
			|| (_schatzPosition.first == 0 && _schatzPosition.second == spalte + 1) // right
			|| (_schatzPosition.first == 1 && _schatzPosition.second == spalte    ) ) // below
		{
			_brett[0][spalte - 1] = PossibleTreasure;
			_brett[0][spalte + 1] = PossibleTreasure;
			_brett[1][spalte    ] = PossibleTreasure;
			return _brett[0][spalte] = Neighboring;
		}

		return _brett[0][spalte] = Empty;
	}

	int revealBorderBottom(int spalte)
	{
		if (   (_schatzPosition.first == squareSize - 1 && _schatzPosition.second == spalte - 1) // left
			|| (_schatzPosition.first == squareSize - 1 && _schatzPosition.second == spalte + 1) // right
			|| (_schatzPosition.first == squareSize - 2 && _schatzPosition.second == spalte    ) ) // above
		{
			_brett[squareSize - 1][spalte - 1] = PossibleTreasure;
			_brett[squareSize - 1][spalte + 1] = PossibleTreasure;
			_brett[squareSize - 2][spalte    ] = PossibleTreasure;
			return _brett[squareSize - 1][spalte    ] = Neighboring;
		}

		return _brett[squareSize -1][spalte] = Empty;
	}

	int revealBorderLeft(int zeile)
	{
		if (   (_schatzPosition.first == zeile - 1 && _schatzPosition.second == 0) // above
			|| (_schatzPosition.first == zeile + 1 && _schatzPosition.second == 0) // below
			|| (_schatzPosition.first == zeile     && _schatzPosition.second == 1) ) // right
		{
			_brett[zeile - 1][0] = PossibleTreasure;
			_brett[zeile + 1][0] = PossibleTreasure;
			_brett[zeile    ][1] = PossibleTreasure;
			return _brett[zeile    ][0] = Neighboring;
		}

		return _brett[zeile][0] = Empty;
	}

	int revealBorderRight(int zeile)
	{
		if (   (_schatzPosition.first == zeile - 1 && _schatzPosition.second == squareSize - 1) // above
			|| (_schatzPosition.first == zeile + 1 && _schatzPosition.second == squareSize - 1) // below
			|| (_schatzPosition.first == zeile     && _schatzPosition.second == squareSize - 2) ) // left
		{
			_brett[zeile - 1][squareSize - 1] = PossibleTreasure;
			_brett[zeile + 1][squareSize - 1] = PossibleTreasure;
			_brett[zeile    ][squareSize - 2] = PossibleTreasure;
			return _brett[zeile    ][squareSize - 1] = Neighboring;
		}

		return _brett[zeile][squareSize - 1] = Empty;
	}

	int revealMiddle(int zeile, int spalte)
	{
		if (   (_schatzPosition.first == zeile - 1 && _schatzPosition.second == spalte    ) // above
		    || (_schatzPosition.first == zeile + 1 && _schatzPosition.second == spalte    ) // below
		    || (_schatzPosition.first == zeile     && _schatzPosition.second == spalte - 1) // left
		    || (_schatzPosition.first == zeile     && _schatzPosition.second == spalte + 1) ) // right
		{
			_brett[zeile - 1][spalte    ] = PossibleTreasure;
			_brett[zeile + 1][spalte    ] = PossibleTreasure;
			_brett[zeile    ][spalte - 1] = PossibleTreasure;
			_brett[zeile    ][spalte + 1] = PossibleTreasure;
			return _brett[zeile    ][spalte    ] = Neighboring;
		}
		return _brett[zeile][spalte] = Empty;
	}

	// change board state by revealing one position
	int reveal(std::pair<int, int> pos)
	{
		// schatz at pos to be revealed
		if (pos == _schatzPosition)
			return _brett[pos.first][pos.second] = Treasure;

		if (pos.first >= squareSize || pos.second >= squareSize)
			return InvalidPos;

		switch (pos.first)
		{
			case 0: // top
				switch (pos.second)
				{
					case 0:  return revealCornerUpperLeft();
					case 1:
					case 2:
					case 3:
					case 4:  return revealBorderTop(pos.second);
					case 5:  return revealCornerUpperRight();
					default: return InvalidPos;
				}
			case 1:
			case 2:
			case 3:
			case 4: // middle
				switch (pos.second)
				{
					case 0:  return revealBorderLeft(pos.first);
					case 1:
					case 2:
					case 3:
					case 4:  return revealMiddle(pos.first, pos.second);
					case 5:  return revealBorderRight(pos.first);
					default: return InvalidPos;
				}
			case 5: // bottom
				switch (pos.second)
				{
					case 0:  return revealCornerLowerLeft();
					case 1:
					case 2:
					case 3:
					case 4:  return revealBorderBottom(pos.second);
					case 5:  return revealCornerLowerRight();
					default: return InvalidPos;
				}
			default: return InvalidPos;
		}
		return InvalidPos;
	}

	// apply Weg, return tries
	int applyWeg(const Weg& w)
	{
		std::cout << "applying weg, schatz is at:" << "(" << _schatzPosition.first << ", " << _schatzPosition.second << ")" << std::endl;
		size_t versuche = 0;
		for (versuche = 0; versuche < w.size(); ++versuche)
		{
			std::pair<int, int> position = w.at(versuche);
			int feldWert = reveal(position);
			std::cout << std::endl << *this ;
			if (feldWert == InvalidPos)
				return InvalidPos;
			if (feldWert == Treasure)
				return versuche;
		}
		return versuche;
	}

	friend std::ostream& operator << (std::ostream& ostr, const Brett& b)
	{
		for (size_t zeile = 0; zeile < b._brett.size(); zeile++)
		{
			for (size_t spalte = 0; spalte < b._brett[0].size(); spalte++)
			{
				ostr << b._brett[zeile][spalte] << " ";
			}
			ostr << std::endl;
		}
		return ostr;
	}

	~Brett() = default;
};

#endif // BRETT_H