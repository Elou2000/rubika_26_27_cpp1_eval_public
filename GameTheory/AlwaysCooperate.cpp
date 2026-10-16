#include "AlwaysCooperate.h"

AlwaysCooperate::AlwaysCooperate(const std::string& name) : IStrategy(name)
{
   
}

Choice AlwaysCooperate::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Cooperate;
}
