#pragma once
#include "IStrategy.h"

class TitForTat : public IStrategy
{
public:
	TitForTat(const std::string& name);

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

