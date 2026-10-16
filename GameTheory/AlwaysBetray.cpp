#include "AlwaysBetray.h"

AlwaysBetray::AlwaysBetray(const std::string& name) : IStrategy(name)
{

}

Choice AlwaysBetray::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
	return Choice::Betray;
}
