#ifndef HASH_H_
#define HASH_H_

#include <string>
#include "Card.h"

using std::string;
using KanbanBoardCard::Card;
namespace UndavHashtable
{
	struct Hastable;
	struct List;
	struct Hashtable;

	int hashFunction(string key);
	void Add(Hastable* table, string key, Card* value);
	Card* Get(Hashtable* table, string key);
	void Remove(Hastable*, string key);
}
#endif