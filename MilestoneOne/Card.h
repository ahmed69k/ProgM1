#pragma once
class Card {

	int number;
	bool isFaceUp;

public:
		Card();
		Card(int n);
		int getNumber();
		void setNumber(int num);
		bool Face();
		void setFace(bool f);
		void display();
		~Card();

};
