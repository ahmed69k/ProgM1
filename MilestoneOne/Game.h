#include"Card.h"
#include"StandardCard.h"
#include"PenaltyCard.h"
#include"BonusCard.h"
#include"Deck.h"
#include"Player.h"

#include <iostream>

class Game {

	Player p1;
	Player p2;
	Deck d;

public:
	Game();
	Game(Player p, Player pp, Deck deck);
	~Game();
	void initializeGame(Card c[]);
};

