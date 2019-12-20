#pragma once
#include"Card_Stack.h"
#include"Card.h"
#include"PlayerCard.h"
class Game {
	CardStack<Card> Drw_pile;
	CardStack<Card>Disc_Pile;
	int playerno;
	//PlayerCard<Player>P;

public:
	void GenerateCards(CardStack<Card>&C);
	void Shuffle(CardStack<Card>&C);


};