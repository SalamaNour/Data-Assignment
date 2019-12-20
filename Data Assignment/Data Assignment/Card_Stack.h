#pragma once
#include"Node.h"
#include"StackADT.h"


template <typename T>
class CardStack
{
	Node<T> * Head;
	int count;
public:
	CardStack(int c = 0) : count(c)
	{
		Head = nullptr;
	}

	bool push(const T&data)
	{

		Node<T> *R = new Node<T>(data);
		if (!R) return false;
		R->setNext(Head);
		Head = R;
		count++;
		return true;

	}

	bool isEmpty() const
	{
		if (Head)
			return false;
		return true;
	}  // end isEmpty

	bool pop(T & TopEntry)
	{
		Node<T>* p = Head;
		if (!Head || count == 0) return false;
		if (Head)
		{
			Head = Head->getNext();
			count--;
			p->setNext(nullptr);
		}
		T T = p->getItem();
		TopEntry = T;
		return true;

	}

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = Head->getItem();
		return true;
	}  // end peek

	T * toArray(int & c) const
	{
		/* T ** retArr = new  T * [count];
		 Node<T>* curPtr = Head;
		int i = 0;
		while (curPtr)
		{
		retArr[i++] = curPtr->getItem();
		curPtr = curPtr->getNext();
		} // end while
		size = count;
		return retArr;
		*/

		c = 0;

		if (!Head)
			return nullptr;
		//counting the no. of items in the Queue
		Node<T>* p = Head;
		while (p)
		{
			c++;
			p = p->getNext();
		}


		T* Arr = new T[c];
		p = Head;
		for (int i = 0; i < c; i++)
		{
			Arr[i] = p->getItem();
			p = p->getNext();
		}
		return Arr;
	}
	~CardStack()
	{
	}
};


