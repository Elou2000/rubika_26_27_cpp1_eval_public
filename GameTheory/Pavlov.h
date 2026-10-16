#pragma once
#include "IStrategy.h"

class Pavlov : public IStrategy
{
public:
	Pavlov(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions);


};

