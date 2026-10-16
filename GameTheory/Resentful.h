#pragma once
#include "IStrategy.h"

class Resentful : public IStrategy
{
public:
	Resentful(const std::string& name);

	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;

	bool betrayed = false;
};

