#include"Card.h"
#include"StandardCard.h"
#include"PenaltyCard.h"
#include"BonusCard.h"
#include"Deck.h"
#include"Game.h"
#include"Player.h"

#include <iostream>
using namespace std;

//Card

Card::Card() {
	number = 0;
	isFaceUp = false;
}

Card::Card(int n) {
	setNumber(n);
	isFaceUp = false;
}

int Card::getNumber() {
	return number;
}

void Card::setNumber(int num) {
	if (num > 10 || num < 0) {
		cout << "Invalid number!" << endl;
	}
	else
		number = num;
}

bool Card::Face() {
	if (isFaceUp) {
		return true;
	}
	else
		return false;
}

void Card::setFace(bool f) {
	isFaceUp = f;
}

void Card::display() {
	if (!isFaceUp) {
		cout << "| * |";
	}
	else {
		cout << "| " << number << " |";
	}
}

Card::~Card() {
}
//RegularCard

StandardCard::StandardCard() :Card() {}
StandardCard::StandardCard(int number) :Card(number) {}
StandardCard::~StandardCard() {}

//BonusCard

BonusCard::BonusCard() :Card() {}
BonusCard::BonusCard(int number) :Card(number) {}
BonusCard::~BonusCard() {}

//PenaltyCard

PenaltyCard::PenaltyCard() :Card() {}
PenaltyCard::PenaltyCard(int number) :Card(number) {}
PenaltyCard::~PenaltyCard(){}


//Player

Player::Player() {
	name = "";
	score = 0;
}



Player::Player(string n) {
	name = n;
	score = 0;
}

void Player::displayScore() {
	cout << name <<"'s score: " << score << endl;
}

string Player::getName() {
	return name;
}

void Player::setName(string n) {
	name = n;
}

int Player::getScore() {
	return score;
}

void Player::setScore(int s) {
	score = s;
}

//Deck

Deck::Deck() {
	cards = new Card*[16];
	int num = 1;
	for (int i = 0; i < 12; i++) {
		if (num > 6) {
			num = 1;

		}
		cards[i] = new StandardCard(num);
		num++;
	}
	for (int i = 12; i < 14; i++) {

		cards[i] = new BonusCard(7);
	
	}
	for (int i = 14; i < 16; i++) {

		cards[i] = new PenaltyCard(8);
		
	}
	//for (int i = 0; i < 16; i++) {
	//	cards[i]->setFace(true);
	//}
}

Deck::Deck(Card** cards) {
	this->cards = cards;
}

Card Deck::getCards() {
	for (int i = 0; i < 16; i++) {
		return *cards[i];
	}
}

void Deck::setCards(Card** cards) {
	this->cards = cards;
}

void Deck::shuffle() {
	srand(time(0));
	for (int i = 16 - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(cards[i], cards[j]);
	}
}
void Deck::displayGrid() {
	for (int i = 0; i < 16; i++) {
		if ((i+1) % 4 == 0) {
			cards[i]->display();
			cout << endl;
		}
		else {
			if(cards[i]!= nullptr)
				cards[i]->display();
		}

	}
}

Deck::~Deck() {
	for (int i = 0; i < 16; i++) {
		delete cards[i]; 
	}
	delete[] cards; 
}

//Game
Game::Game() {
	p1 = new Player();
	p2 = new Player();
	d = new Deck();
}

Game::Game(string p1, string p2) {
	
	
	this->p1 = new Player(p1);
	this->p2 = new Player(p2);
	d = new Deck();

	
}

Game::~Game(){
	delete d, p1, p2;
}

void Game::initializeGame() {
	cout << "   CARD MATCHING"<<endl;
	d->shuffle();
	d->displayGrid();
	p1->displayScore();
	p2->displayScore();
	//cout << "Game initialized!"<<endl;
}





int main() {
	Game g("Ahmed", "Ahmed Tany");
	g.initializeGame();
	return 0;

}
