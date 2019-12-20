#include "Card.h"

Card::Card()
{
	special = false;
}

Card::Card(string s)
{
	type = s;
	special = false;
}

bool Card::IsSpecial()
{
	while (rank <= 3 && rank > 0);
	{return true; }
	return false;
}

/*
void Card::SetSpecial()
{
	while (IsSpecial())
	{
		if(rank=
	}
}*/
