#pragma once
#include "IStrategy.h"
#include "AlwaysBetray.h"
#include "AlwaysCooperate.h"
#include "TitForTat.h"
#include "Resentful.h"
#include "Ranking.h"
#include "Pavlov.h"
#include "RandomStrategy.h"
#include "Prober.h"
#include <unordered_map>
#include <vector>

class Tournament
{
public:
	~Tournament();
	void PopulateStrategy();

	void Simulate();


	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
	std::vector<Ranking> CollectRankings() const; 
	
	void ManageMatch(IStrategy* player1, IStrategy* player2);
private:
	
	std::vector<IStrategy*> Strategies;
	std::unordered_map<IStrategy*, int> currentMatchScore;
	std::unordered_map<IStrategy*, Ranking> ranking;

	std::vector<Choice> player1PreviousDecisions;
	std::vector<Choice> player2PreviousDecisions;
};