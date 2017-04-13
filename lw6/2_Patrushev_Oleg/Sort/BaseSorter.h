#include "ISorter.h"
#include <vector>

class CBaseSorter : public ISorter
{
public:
	CBaseSorter(const std::vector<int>& inVector);
	std::vector<int> GetData() const;

	void Sort() override;

protected:
	virtual void SortIteration() = 0;

	std::vector<int> m_vector;
	size_t m_startVectorSize;
};
