#include "Card.h"
#pragma once


class Deck {

	Card* cards;

public:
	Deck();
	Deck(Card* cards);
	void shuffle();
	void displayGrid();
	Card getCards();
	void setCards(Card* cards);
	~Deck();



};
