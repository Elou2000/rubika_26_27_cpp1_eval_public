#include "RandomStrategy.h"

RandomStrategy::RandomStrategy(const std::string& name) : IStrategy(name) {}

Choice RandomStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
	if ((rand() % 2) + 1 == 2)
	{
		return Choice::Cooperate;
	}
	else
	{
		return Choice::Betray;
	}
}