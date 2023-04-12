#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include "list_func.h"


int main() {
	using namespace std;
	ListOfBook* head = nullptr;

	initializeList(head);

	char check;
	head->printList();
	while (true) {
		
		if (!head) {
			char endcheck = 0;
			while (!endcheck) {
				system("cls");
				cout << "Your list is empty. Do you want to create new list?" << endl <<
					"1. Yes" << endl <<
					"2. No" << endl << endl;
				cin >> check;
				
				switch (check) {
				case '2':
					exit(0);

				case '1':
					system("cls");
					initializeList(head);
					head->printList();
					endcheck++;
					break;

				default:
					system("cls");
					cout << "[Error. Try again]" << endl;
					Sleep(2500);
				}
			}
		}

		cout <<  endl << 
			"1. Sort by condition" << endl <<
			"2. Print by condition" << endl <<
			"3. Delete by condition" << endl <<
			"4. Add new element" << endl <<
			"5. Delete element" << endl <<
			"6. Print list to file" << endl <<
			"7. Exit program" << endl << endl;
		cin >> check;
		cout << endl;

		switch (check) {
		case '7':
			exit(0);

		case '1':
			sotrByCondition(head);
			system("cls");
			head->printList();
			break;

		case '2':
			system("cls");
			head->printList();
			head->printByCondition();
			break;

		case '3':
			deleteByCondition(head);
			system("cls");
			head->printList();
			break;

		case '4':
			system("cls");
			head->printList();
			addNewItem(head);
			system("cls");
			head->printList();
			break;

		case '5':
			system("cls");
			head->printList();
			deleteItem(head);
			system("cls");
			head->printList();
			break;

		case '6':
		{
			string fileName;
			system("cls");
			cout << "Enter file name to output (file name must ends with \".txt\")" << endl;
			cin >> fileName;

			/*перевірка, чи корректно користувач задав ім'я файлу*/
			if (fileName.find(".txt") == string::npos) {
				system("cls");
				std::cout << "[Error. File name must ends with (\".txt\")]" << std::endl;
			} else {
				head->fprintList(fileName);
				cout << endl <<
					"Output to file \"" << fileName <<
					"\" completed" << endl;
			}
			Sleep(2500);
			system("cls");
			head->printList();
			break;
			
		}

		default:
			system("cls");
			cout << "[Error. Try again]" << endl;
			Sleep(2500);
			system("cls");
			head->printList();
		}
	}
	return 0;
}