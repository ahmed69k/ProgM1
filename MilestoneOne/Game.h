#include"Card.h"
#include"StandardCard.h"
#include"PenaltyCard.h"
#include"BonusCard.h"
#include"Deck.h"
#include"Player.h"

#include <iostream>

class Game {

	Player *p1;
	Player *p2;
	Deck *d;

public:
	Game();
	Game(string p1, string p2);
	~Game();
	void initializeGame();
};

