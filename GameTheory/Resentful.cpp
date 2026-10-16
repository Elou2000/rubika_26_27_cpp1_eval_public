#include "Resentful.h"

Resentful::Resentful(const std::string& name) : IStrategy(name)
{
}

Choice Resentful::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (previousDecisions.empty()) return Choice::Cooperate;
    if (betrayed) return Choice::Betray;
    if (previousDecisions.back() == Choice::Betray)
    {
        betrayed = true;
        return Choice::Betray;
    }
}
