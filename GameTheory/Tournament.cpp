#include "Tournament.h"
#include <algorithm>

Tournament::~Tournament()
{
	for (auto strategy : Strategies)
	{
		delete strategy;
	}
}

void Tournament::PopulateStrategy()
{
	Strategies.push_back(new AlwaysCooperate("Always Cooperate"));
	Strategies.push_back(new AlwaysBetray("Always Betray"));
	Strategies.push_back(new TitForTat("Tit For Tat"));
	Strategies.push_back(new Resentful("Resentful"));
	Strategies.push_back(new RandomStrategy("Random"));
	Strategies.push_back(new Pavlov("Pavlov"));
	Strategies.push_back(new Prober("Prober"));

	for (auto strategy : Strategies)
	{
		Ranking newRanking = Ranking();
		newRanking.StrategyName = strategy->Name;
		ranking[strategy] = newRanking;
	}

}

void Tournament::Simulate()
{
	for (int i = 0; i < Strategies.size(); i++)
	{
		for (int j = i; j < Strategies.size(); j++)
		{
			if (i == j) continue; 
			IStrategy* p1 = Strategies[i];
			IStrategy* p2 = Strategies[j];

			currentMatchScore.clear();
			player1PreviousDecisions.clear();
			player2PreviousDecisions.clear();

			for (int round = 0; round < 50; round++) ManageMatch(p1, p2);

			int s1 = currentMatchScore[p1];
			int s2 = currentMatchScore[p2];
			ranking[p1].TotalPoint += s1;
			ranking[p2].TotalPoint += s2;

			if (s1 > s2) 
			{ 
				ranking[p1].Win++;  
				ranking[p2].Lose++;
			}
			else if (s2 > s1)
			{ 
				ranking[p2].Win++; 
				ranking[p1].Lose++; 
			}
			else 
			{
				ranking[p1].Draw++; 
				ranking[p2].Draw++; 
			}
		}
	}
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
	std::vector<Ranking> r = CollectRankings();

	std::sort(r.begin(), r.end(), [](const Ranking& r1, const Ranking& r2)
		{
			if (r1.TotalPoint != r2.TotalPoint) return r1.TotalPoint > r2.TotalPoint;
			if (r1.Win != r2.Win) return r1.Win > r2.Win;
			if (r1.Draw != r2.Draw) return r1.Draw > r2.Draw;
			return r1.Lose < r2.Lose;
		});

	return r;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
	std::vector<Ranking> r = CollectRankings();

	std::sort(r.begin(), r.end(), [](const Ranking& r1, const Ranking& r2)
		{
			if (r1.Win != r2.Win)  return r1.Win > r2.Win;
			if (r1.Draw != r2.Draw) return r1.Draw > r2.Draw;
			return r1.Lose < r2.Lose;
		});

	return r;
}

std::vector<Ranking> Tournament::CollectRankings() const
{
	std::vector<Ranking> result;

	for (const auto& pair : ranking) result.push_back(pair.second);

	return result;
}


void Tournament::ManageMatch(IStrategy* player1, IStrategy* player2)
{
	Choice P1Choice = player1->Decide(player1PreviousDecisions, player2PreviousDecisions);
	Choice P2Choice = player2->Decide(player2PreviousDecisions, player1PreviousDecisions);

	player1PreviousDecisions.push_back(P1Choice);
	player2PreviousDecisions.push_back(P2Choice);
	

	if (P1Choice == Choice::Betray)
	{
		if (P2Choice == Choice::Cooperate)
		{
			currentMatchScore[player1] += 5;
			currentMatchScore[player2] += 0;

		}
		else
		{
			currentMatchScore[player1] += 1;
			currentMatchScore[player2] += 1;
		}
	}
	else
	{
		if (P2Choice == Choice::Cooperate)
		{
			currentMatchScore[player1] += 3;
			currentMatchScore[player2] += 3;
		}
		else
		{
			currentMatchScore[player1] += 0;
			currentMatchScore[player2] += 5;
		}
	}

}





