#include "Prober.h"

Prober::Prober(const std::string& name) : IStrategy(name)
{

}

Choice Prober::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (previousDecisions.empty()) return Choice::Betray;
    else if (previousDecisions.size() < 3)
    {
        return Choice::Cooperate;
    }
    else if (std::find(opponentPreviousDecisions.begin(), opponentPreviousDecisions.end(), Choice::Betray) != opponentPreviousDecisions.end()) {
        return Choice::Betray;
    }
    else {
        return opponentPreviousDecisions.back();
    }
}