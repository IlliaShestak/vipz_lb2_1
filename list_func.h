#pragma once
#include <string>

class ListOfBook {

	std::string m_author;
	std::string m_bookName;
	int m_year;
	int m_pages;
	int m_cost;
	ListOfBook* m_next;

public:

	ListOfBook(ListOfBook* ptr = nullptr) {
		m_next = ptr;
	}

	std::string getBookName() { return m_bookName; }
	std::string getAuthor() { return m_author; }
	int getYear() { return m_year; }
	int getPages() { return m_pages; }
	int getCost() { return m_cost; }
	ListOfBook* getNext() { return m_next; }

	void setBookName(std::string bookName) { m_bookName = bookName; }
	void setAuthor(std::string author) { m_author = author; }
	void setYear(int year) { m_year = year; }
	void setPages(int pages) { m_pages = pages; }
	void setCost(int price) { m_cost = price; }
	void setNext(ListOfBook* next) { m_next = next; }

	void swapItems(ListOfBook*& firstToSwap, ListOfBook*& secondToSwap);
	ListOfBook* pushBack();
	ListOfBook* pushMiddle();
	void popBack();
	void popMiddle();
	void printList();
	void printByCondition();
	void fprintList(std::string fileName);
};

void sotrByCondition(ListOfBook*& head);
void pushHead(ListOfBook*& head);
void popHead(ListOfBook*& head);
void swapHead(ListOfBook*& head);
void deleteItem(ListOfBook*& head);
void addNewItem(ListOfBook*& head);
void linef();
void deleteByCondition(ListOfBook*& head);
void initializeItem(ListOfBook*& head);
void ReadFromFile(ListOfBook*& head);
void initializeList(ListOfBook*& head);