#ifndef WEG_H
#define WEG_H
#include <vector>

class Weg : public std::vector< std::pair<int, int>>
{
public:
	Weg() = default;

	friend std::ostream operator << (std::ostream& ostr, const Weg& w)
	{
		int minZeile  = INT64_MAX;
		int maxZeile  = INT64_MIN;
		int minSpalte = INT64_MAX;
		int maxSpalte = INT64_MIN;
		for (size_t i = 0; i < w.size(); i++)
		{
			std::pair<int, int>& curr = w[i];
			if (curr.first > maxZeile)
				maxZeile = curr.first;
		}
	}

	~Weg() = default;
};

#endif //WEG_H