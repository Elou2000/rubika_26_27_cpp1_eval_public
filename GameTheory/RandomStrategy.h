#pragma once
#include "IStrategy.h"

class RandomStrategy : public IStrategy
{
public:
	RandomStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions);
};

