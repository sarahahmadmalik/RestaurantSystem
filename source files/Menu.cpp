#define _CRT_SECURE_NO_WARNINGS
#include"Menu.h"
#include<iostream>
#include<iomanip>
using namespace std;

namespace dsa {

	Menu::Menu(const char* t)
	{
		if (t != nullptr) {
			strcpy(title, t);
			isValid = true;
		}

		else {
			setEmpty();
		}
		item_No = 0;
		indent = 0;
	}

	Menu::Menu(const char* t, int value)
	{
		if (t != nullptr) {
			strcpy(title, t);
			isValid = true;
		}
		else {

			setEmpty();
		}
		indent = value;
		item_No = 0;

	}

	Menu::operator bool() const
	{
		return isValid;
	}


	Menu::operator int() const {
		return run();
	}

	bool Menu::isEmpty() const
	{
		return !isValid;
	}

	void Menu::display() const
	{

		if (!isValid) {
			cout << "Invalid Menu!" << endl;
		}
		else if (item_No == 0) {
			for (int i = 0; i < indent; i++)
			{
				cout << "    ";
			}
			cout << title << std::endl;
			cout << "No Items to display!" << endl;
		}
		else {
			for (int i = 0; i < indent; i++)
			{
				cout << "    ";
			}
			
			cout << "--------------------------------------" << endl;
			cout <<"\t\t\t    "<<title << endl;
			for (int i = 0; i < indent; i++)
			{
				cout << "    ";
			}
			cout << "--------------------------------------" << endl;
			for (unsigned int i = 0; i < item_No; i++) {
				for (int i = 0; i < indent; i++)
				{
					cout << "    ";
				}
				cout << i + 1 << "- " << items_Lists[i].menuitems << endl;
			}
			for (int i = 0; i < indent; i++)
			{
				cout << "    ";
			}
			cout << "> ";
		}
	}

	int getIntInRange(int min, int max) {
		int i;
		cin >> i;
		if (cin.fail()) {
			cin.clear();

			cin.ignore(1000, '\n');
			cout << "Invalid Integer, try again: ";
			return getIntInRange(min, max);
		}
		else if (i<min || i>max) {
			cin.ignore(1000, '\n');
			cout << "Invalid selection, try again: ";
			return getIntInRange(min, max);
		}
		else {
			cin.ignore(1000, '\n');
			return i;
		}
	}

	Menu& Menu::operator=(const char* newtitle)
	{
		if (newtitle != nullptr) {
			strcpy(title, newtitle);
			isValid = true;
		}

		else
			setEmpty();

		return *this;
	}

	void Menu::add(const char* item)
	{
		if (item == nullptr)
			clear();

		else if (isValid) {
			if (item_No < MAX_NO_OF_ITEMS) {
				strcpy(items_Lists[item_No].menuitems, item);

				item_No++;
			}
		}
	}

	void Menu::clear() {
		strcpy(title, "");
		item_No = 0;
		isValid = false;
	}

	void Menu::setEmpty()
	{
		indent = 0;
		item_No = 0;
		isValid = false;
	}

	Menu& Menu::operator<<(const char* menuitem) {
		add(menuitem);
		return *this;
	}

	int Menu::run() const {
		display();
		if (item_No != 0) {
			return getIntInRange(1, item_No);
		}
		return 0;
	}

	void MenuItem::display() const
	{
		if (isValid) {
			cout << menuitems << endl;
		}

	}

	bool MenuItem::isEmpty() const
	{
		return !isValid;
	}

	MenuItem::MenuItem(const char* item) {
		if (item != nullptr) {
			isValid = true;
			strcpy(menuitems, item);
		}
		else {
			isValid = false;
		}
	}


}