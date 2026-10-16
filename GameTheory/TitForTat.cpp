#include "TitForTat.h"


TitForTat::TitForTat(const std::string& name) : IStrategy(name)
{

}

Choice TitForTat::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (previousDecisions.empty()) return Choice::Cooperate;
    else return previousDecisions.back();
}
