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
	if (num > 6 || num < 0) {
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
	if (isFaceUp) {
		cout << number;
	}
	else
		cout << "*";
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
	cout << "Score: " << score << endl;
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
	cards = new Card[16];
}

Deck::Deck(Card* cards) {
	this->cards = cards;
}

Card Deck::getCards() {
	for (int i = 0; i < 16; i++) {
		return cards[i];
	}
}

void Deck::setCards(Card* cards) {
	this->cards = cards;
}

void Deck::shuffle() {}
void Deck::displayGrid() {
	for (int i = 0; i < 16; i++) {
		if ((i+1) % 4 == 0) {
			cards[i].display();
			cout << endl;
		}
		else {
			cards[i].display();
		}

	}
}

Deck::~Deck() {
	delete[] cards;
}

//Game
Game::Game() {
	p1 = Player();
	p2 = Player();
	d = Deck();
}

Game::Game(Player p, Player pp, Deck deck) {
	p1 = p;
	p2 = pp;
	d = deck;
}

Game::~Game(){}

void Game::initializeGame(Card c[]) {
	d = Deck(c);
	//d.shuffle();
	cout << "Game initialized!"<<endl;
}





int main() {
	
	return 0;

}
