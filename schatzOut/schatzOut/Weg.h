#ifndef WEG_H
#define WEG_H
#include <vector>

class Weg : public std::vector< std::pair<int, int>>
{
public:
	Weg() = default;

	~Weg() = default;
};

#endif //WEG_H