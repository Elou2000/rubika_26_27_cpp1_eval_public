#include "Pavlov.h"

Pavlov::Pavlov(const std::string& name) : IStrategy(name) {}

Choice Pavlov::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
	if (previousDecisions.empty()) return Choice::Cooperate;
	else
	{
		if (opponentPreviousDecisions.back() == Choice::Cooperate)
		{
			return previousDecisions.back();
		}

		if (previousDecisions.back() == Choice::Cooperate)
		{
			return Choice::Betray;
		}
		else
		{
			return Choice::Cooperate;
		}
	}
}