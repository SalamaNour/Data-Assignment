#include "Game.h"
 
void Game::GenerateCards(CardStack<Card>& C)
{
	for (int i = 0; i < 13; i++)
	{
		Card heart("Heart");
		C.push(heart);
	}

	for (int i = 0; i < 13; i++)
	{
		Card diamond("Diamond");
		C.push(diamond);
	}
	for (int i = 0; i < 13; i++) {
		Card spade("Spade");
		C.push(spade);
	}
	for (int i = 0; i < 13; i++) {
		Card club("Club");
		C.push(club);
	}
}
void Game::Shuffle(CardStack<Card>&C) //fill and random drw pile
{
	int size = 52;
	Card *rnd_cards = C.toArray(size);
	CardStack<Card> play;

	for (int i = 0; i <52;i++)
	{
		// Random for remaining positions. 
		int r = i + (rand() % (52 - i));
		swap(rnd_cards[i], rnd_cards[r]);
	}
	for (int i = 0; i < size; i++)
	{
		Card tmp;
		play.push(rnd_cards[i]);
		C.pop(tmp);
	}
	Drw_pile = play;
}