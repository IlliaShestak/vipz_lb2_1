#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include "list_func.h"


/*викликати т≥льки дл€ голови списку*/
ListOfBook* ListOfBook::pushBack() {
	ListOfBook* head = this;
	ListOfBook* newItem = new ListOfBook;
	while (head->m_next)
		head = head->m_next;
	head->m_next = newItem;
	return newItem;
}

ListOfBook* ListOfBook::pushMiddle() {
	ListOfBook* newItem = new ListOfBook;
	newItem->m_next = m_next;
	m_next = newItem;
	return newItem;
}

/*викликати т≥льки дл€ голови списку*/
void ListOfBook::popBack() {
	ListOfBook* head = this;
	if (!head->m_next) {
		delete head;
		head = nullptr;
		return;
	}
	while (head->m_next->m_next)
		head = head->m_next;
	delete head->m_next;
	head->m_next = nullptr;
}

void ListOfBook::popMiddle() {
	if (!m_next)
		return;
	ListOfBook* itemToDelete = m_next;
	m_next = itemToDelete->m_next;
	delete itemToDelete;
}

/*викликати дл€ попереднього елемента перед першим з тих, €к≥ треба пом≥н€ти м≥сц€ми*/
void ListOfBook::swapItems(ListOfBook*& firstToSwap, ListOfBook*& secondToSwap) {
	firstToSwap->m_next = secondToSwap->m_next;
	secondToSwap->m_next = firstToSwap;
	m_next = secondToSwap;

	ListOfBook* tmp = firstToSwap;
	firstToSwap = secondToSwap;
	secondToSwap = tmp;
}

/*виводить список починаючи з викликаного елемента*/
void ListOfBook::printList() {
	using namespace std;
	ListOfBook* tmp = this;
	linef();
	cout << "\t\t\tBooks" << endl;
	linef();
	while (tmp)
	{
		cout << "|| [The name of the book]\t|| " << tmp->m_bookName << endl <<
			"|| [The author]\t\t\t|| " << tmp->m_author << endl <<
			"|| [The year of releasing]\t|| " << tmp->m_year << endl <<
			"|| [Number of pages]\t\t|| " << tmp->m_pages << endl <<
			"|| [The cost]\t\t\t|| " << tmp->m_cost << endl;
		linef();
		tmp = tmp->m_next;
	}

}

void ListOfBook::fprintList(std::string fileName)
{
	std::ofstream fof(fileName);
	ListOfBook* tmp = this;
	
	for (int i = 0; i < 60; i++)
	{
		fof << "=";
	}
	fof << std::endl;

	fof << "\t\t\tBooks" << std::endl;

	for (int i = 0; i < 60; i++)
	{
		fof << "=";
	}
	fof << std::endl;
	
	while (tmp)
	{
		fof << "|| [The name of the book]\t|| " << tmp->m_bookName << std::endl <<
			"|| [The author]\t\t\t|| " << tmp->m_author << std::endl <<
			"|| [The year of releasing]\t|| " << tmp->m_year << std::endl <<
			"|| [Number of pages]\t\t|| " << tmp->m_pages << std::endl <<
			"|| [The cost]\t\t\t|| " << tmp->m_cost << std::endl;

		for (int i = 0; i < 60; i++)
		{
			fof << "=";
		}
		fof << std::endl;

		tmp = tmp->m_next;
	}

}

/*викликати т≥льки дл€ голови списку*/
void ListOfBook::printByCondition() {
	double count = 0, sum_cost = 0;
	ListOfBook* item = this;

	while (item)
	{
		sum_cost += item->getCost();
		count++;
		item = item->getNext();
	}

	double middle_cost = sum_cost / count;

	std::cout << "\t The middle cost of the books: " << middle_cost << std::endl;
	linef();
	std::cout << "\tBooks that cost lower than the middle cost" << std::endl;
	linef();

	item = this;
	while (item)
	{
		if (item->getCost() < middle_cost)
		{
			std::cout << "|| " << item->getBookName() <<
				" (" << item->getCost() << ")" << std::endl;
		}
		item = item->getNext();
	}
	linef();
}


void ReadFromFile(ListOfBook*& head) {
	using namespace std;
	head = new ListOfBook;
	ifstream fin("InfOfBooks.txt");
	ListOfBook* item = head;

	if (!fin) {
		cerr << "Error. Input file wasn`t found.";
		return;
	}

	while (fin) {
		string str;
		if (head->getNext())
			item = item->getNext();

		getline(fin, str);
		item->setAuthor(str);
		getline(fin, str);
		item->setBookName(str);
		getline(fin, str);
		item->setYear(stoi(str));
		getline(fin, str);
		item->setPages(stoi(str));
		getline(fin, str);
		item->setCost(stoi(str));
		getline(fin, str);				//м≥ж даними про р≥зн≥ книги у файл≥ Ї порожн≥й р€док

		head->pushBack();
	}
	head->popBack();
}

void initializeItem(ListOfBook*& item) {
	
	int tmpInt;
	std::string tmpStr;
	std::cout << "[Enter the name of the book]" << std::endl;
	std::cin >> tmpStr;
	item->setBookName(tmpStr);
	std::cout << "[Enter the name and surname of the author of the book]" << std::endl;
	std::cin >> tmpStr;
	item->setAuthor(tmpStr);
	std::cout << "[Enter the year of release of the book]" << std::endl;
	std::cin >> tmpInt;
	item->setYear(tmpInt);
	std::cout << "[Enter the number of pages of the book]" << std::endl;
	std::cin >> tmpInt;
	item->setPages(tmpInt);
	std::cout << "[Enter the cost of the book]" << std::endl;
	std::cin >> tmpInt;
	item->setCost(tmpInt);
}

void initializeList(ListOfBook*& head) {
	using namespace std;
	ListOfBook* item;
	while (true) {
		char check;
		cout << "Choose how to initialize list" << endl <<
			"1. Read list from file" << endl <<
			"2. Initialize by console" << endl <<
			"3. Exit program" << endl << endl;

		cin >> check;
		cout << endl;

		switch (check) {
		case '1':
			ReadFromFile(head);
			break;

		case '2':
			system("cls");
			if (!head) {
				head = new ListOfBook;
				initializeItem(head);
			}
			while (true) {
				char endcheck = 0;
				
				system("cls");
				head->printList();
				cout << endl << endl;

				cout << "Do you want to add one more?" << endl <<
					"1. Yes" << endl <<
					"2. No" << endl << endl;
				cin >> check;

				switch (check) {
				case '1':
					system("cls");
					head->printList();
					cout << endl;
					item = head->pushBack();
					initializeItem(item);
					break;

				case '2':
					endcheck++;
					break;

				default:
					system("cls");
					cout << "[Error. Try again]" << endl;
					Sleep(2500);
					system("cls");
					head->printList();
					continue;
				}
				if (endcheck)
					break;
			}
			break;

		case '3':
			exit(0);

		default:
			system("cls");
			cout << "[Error. Try again]" << endl;
			Sleep(2500);
			system("cls");
			continue;
		}
		break;
	}
	system("cls");
}

/*функц≥€ сортуЇ список за зростанн€м за к≥льк≥стю стор≥нок*/
void sotrByCondition(ListOfBook*& head) {
	ListOfBook *prevItem, *item, *nextItem;
	prevItem = nullptr;
	bool isSorted = true;

	do
	{
		item = head;
		nextItem = item->getNext();
		isSorted = true;
		while (item->getNext())
		{
			int pages1 = item->getPages();
			int pages2 = nextItem->getPages();

			if (pages1 > pages2) {

				isSorted = false;
				if (item == head)
					swapHead(head);
				else
					prevItem->swapItems(item, nextItem);
			}
			prevItem = item;
			item = nextItem;
			nextItem = nextItem->getNext();
		};
	} while (!isSorted);
}

void pushHead(ListOfBook*& head) {
	ListOfBook* newItem = new ListOfBook;
	newItem->setNext(head);
	head = newItem;
}

void popHead(ListOfBook*& head) {
	ListOfBook* tmp = head;
	head = head->getNext();
	delete tmp;
}

void swapHead(ListOfBook*& head) {
	ListOfBook* tmp = head->getNext();
	head->setNext(tmp->getNext());
	tmp->setNext(head);
	head = tmp;
}

void linef() {
	for (int i = 0; i < 60; i++)
	{
		std::cout << "=";
	}
	std::cout << std::endl;
}

void addNewItem(ListOfBook*& head) {
	ListOfBook* item = head;
	int position;

	std::cout << std::endl << "Choose the position for the new element" << std::endl <<
		"(Enter number of position or 0 to add to the end)" << std::endl;

	std::cin >> position;
	std::cout << std::endl;

	if (!position)
		item = head->pushBack();
	else if (position == 1) {
		pushHead(head);
		item = head;
	}
	else {
		for (int i = 0; i < position - 2; i++)
		{
			if (!item->getNext()) {
				system("cls");
				std::cout << "[Error. Your list is shorter]" << std::endl;
				Sleep(2500);
				system("cls");
				head->printList();
				return;
			}
				item = item->getNext();
		}
		item = item->pushMiddle();
	}

	initializeItem(item);
}

void deleteItem(ListOfBook*& head) {
	ListOfBook* item = head;
	int position, check = 0;

	std::cout << std::endl << "Choose an element to delete" << std::endl <<
		"(Enter number of position or 0 to delete the last element)" << std::endl;
	std::cin >> position;
	std::cout << std::endl;

	if (!position)
		head->popBack();
	else if (position == 1) {
		popHead(head);
		item = head;
	}
	else {
		for (int i = 0; i < position - 2; i++)
		{
			if (!item->getNext()) {
				system("cls");
				std::cout << "[Error. Your list is shorter. Choose correct position]" << std::endl;
				Sleep(2500);
				system("cls");
				head->printList();
				return;
			}
			else
				item = item->getNext();
		}
		if (!item->getNext()){
			system("cls");
			std::cout << "[Error. Your list is shorter. Choose correct position]" << std::endl;
			Sleep(2500);
			system("cls");
			head->printList();
			return;
		}
		item->popMiddle();
	}
}

void deleteByCondition(ListOfBook*& head) {
	ListOfBook* item = head;
	ListOfBook* prevItem = nullptr;

	while (item) {
		if (item->getYear() < 1980 && item->getPages() < 90) {
			item = item->getNext();
			if (item == head)
				popHead(head);	
			else 
				prevItem->popMiddle();
		} else {
			prevItem = item;
			item = item->getNext();
		}
	}
}