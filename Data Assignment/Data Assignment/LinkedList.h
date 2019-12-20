#pragma once
#include"Node.h"
template<class T>
class LinkedList
{
public:
	Node<T>* Head;
	Node<T>* Tail;
	int itemcount;
	Node<T>*getNodeAt(int position)const;
	LinkedList<T>() {
		Head = NULL;
		Tail = NULL;
		itemcount = 0;
	}
	bool isEmpty() {
		while (!Head) { return false; }
		return true;
	}
	Node<T>*getNodeAt(int position)const {

		assert((position >= 1) && (position <= itemcount));
		Node<T>*cur = Head;
		for (int skip = 1; skip < position; skip++)
		{
			cur = cur->getNext();
		}
		return cur;
	}
	bool insertat(int position, const T&newEntry)
	{
		bool abletoinsert = (position >= 1) && (position <= itemcount + 1);
		if (abletoinsert)
		{
			Node<T>*ptr = new Node<T>(newEntry);
			if (position == 1)
			{
				ptr->setNext(Head);
				Head = ptr;
			}
			else {
				Node<T>*prev = getNodeAt(position - 1);
				ptr->setNext(prev->getNext());
				prev->setNext(ptr);
			}
			itemcount++;
		}
		return abletoinsert;
	}
	bool remove(int posiion)
	{
		bool abletoremove = (position >= 1) && (position <= itemcount);
		if (abletoremove)
		{
			Node<T>*cur = nullptr;
			if (posiion == 1)
			{
				cur = Head;
				Head = Head->getNext();
			}
			else {
				Node<T>prev = getNodeAt(posiion - 1);
				cur = prev->getNext();
				prev->setNext(cur->getNext());
			}
			cur->setNext(nullptr);
			delete cur;
			cur = nullptr;
			itemcount--;
		}return abletoremove;
	}


	void insert(T data) {
		if (!Head) {
			// The list is empty
			Head = new Node<T>;
			Head->data = data;
			Head->next = NULL;
			Tail = Head;
		}
		else {
			// The list isn't empty
			if (Tail == Head) {
				// The list has one element
				Tail = new Node<T>;
				Tail->data = data;
				Tail->next = NULL;
				Head->next = Tail;
			}
			else {
				// The list has more than one element
				Node<T>* insdata = new Node<T>;
				insdata->data = data;
				insdata->next = NULL;
				Tail->next = insdata;
				Tail = insdata;
			}
		}
	}

	T get(int index) {
		if (index == 0) {
			// Get the Head element
			return this->Head->data;
		}
		else {
			// Get the index'th element
			Node<T>* curr = this->Head;
			for (int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
	}

	T operator[](int index) {
		return get(index);
	}

	T getEntry(int position) const
	{
		bool abletoget = (position >= 1) && (position <= itemcount);
		if (abletoget)
		{
			Node<T>*Nodeptr = getNodeAt(position);
			return Nodeptr->getitem();
		}
	}
	void clear() {
		while (!isEmpty())
		{
			remove(1);
		}
	}
	~LinkedList<T>() {
		clear();
	}
};
