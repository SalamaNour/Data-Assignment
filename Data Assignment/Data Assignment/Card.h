#pragma once
#include<string.h>
#include<string>
#include<iostream>
#include"Card_Stack.h"
using namespace std;
class Card {
	string type; //"Heart","Diamond","spade","Club"
	int rank; //the number
	bool special;//"1.king 2.Queen 3.Ace
public:
	Card();
	Card(string s);
	bool IsSpecial();
	/*void SetSpecial();*/
	
};