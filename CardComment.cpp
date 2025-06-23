#include<iostream>
#include "CardComment.h"
#include<string>
#include<ctime>

using namespace std;
using namespace KanbandBoardCardComment;

struct KanbandBoardCardComment::CardComment
{
	string author;
	string text;
	string creationDate;
	CardComment* next;
};

CardComment* KanbandBoardCardComment::CreateCardComment(string author, string text)
{
	CardComment* comment = new CardComment;
	comment->author = author;
	comment->text = text;
	comment->next = NULL;

	return comment;
}

string KanbandBoardCardComment::GetAuthor(CardComment* comment)
{
	return comment->author;
}

string KanbandBoardCardComment::GetText(CardComment* comment)
{
	return comment->text;
}

void KanbandBoardCardComment::SetText(CardComment* comment, string author, string text)
{
	if (comment->author== author)
	{
		comment->text = text;
	}
	
}

string KanbandBoardCardComment::GetCreationDate(CardComment* comment)
{
	return comment->creationDate;
}

void KanbandBoardCardComment::DestroyComment(CardComment* comment)
{
	delete comment;
}