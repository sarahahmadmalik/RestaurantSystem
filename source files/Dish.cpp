#define _CRT_SECURE_NO_WARNINGS
#include "Dish.h"
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

namespace dsa {
	DishItem::DishItem()
	{
		category[0] = 0;
		dish_price = 0;
		dish_name[0] = 0;
		CsvMode = 0;
		isValid = false;
	}

	DishItem::DishItem(const char* name, int price)
	{
		category[0] = 0;
		dish_name[0] = 0;
		dish_price = 0;
		CsvMode = false;
		if (name != nullptr && price > 0) {
			strcpy(dish_name, name);
			dish_price = price;
			isValid = true;
		}
		else {
			setEmpty();
		}
	}

	DishItem::operator bool() const
	{
		return isValid;
	}

	bool DishItem::isEmpty()
	{
		return !isValid;
	}

	void DishItem::setEmpty()
	{
		dish_price = 0;
		dish_name[0] = 0;
		isValid = false;
		CsvMode = false;
	}

	bool DishItem::isCsvMode() const
	{
		return CsvMode;
	}

	void DishItem::setCsvMode(bool flag)
	{
		CsvMode = flag;
	}

	const char* DishItem::getName() const
	{
		return dish_name;
	}


	std::istream& DishItem::read(std::istream& is)
	{
		if (isCsvMode()) {
			is.getline(this->category, 20, ',');
			is.getline(this->dish_name, 31, ',');

			is >> this->dish_price;
			char c;
			is.get(c);
			if (is.fail())
				is.clear();
		}
		else {
			char name[20], categ[20];
			int price;
			cout << "Enter Dish name: ";
			cin.getline(name, 20);
			cout << "Enter dish Category: ";
			cin.getline(categ, 20);
			cout << "Enter dish price: ";
			cin >> price;
			strcpy(this->dish_name, name);
			strcpy(this->category, categ);
			dish_price = price;
		}
		return is;
	}

	std::ostream& DishItem::write(std::ostream& os) const
	{
		if(!isCsvMode())
		os << setw(18) << setfill(' ') << right << dish_name << setw(33) << setfill(' ') << (std::right) << dish_price << endl;
		else {
			os << category << "," << dish_name << "," << dish_price << endl;
		}
		return os;
	}


	const char* DishItem::getCateg()const
	{
		return category;
	}

	int DishItem::getPrice() const
	{
		return dish_price;
	}

	void DishItem::display() const
	{
		cout << "Dish: " << dish_name << endl;
		cout << "Price: " << dish_price << endl;
	}


	Dish::Dish()
	{
		filename = nullptr;
		dish_No = 0;
		isValid = false;
		csv = false;
	}

	Dish::Dish(const char* file, int size)
	{
		csv = false;
		filename = nullptr;
		if (file != nullptr) {
			filename = new char[strlen(file) + 1];
			strcpy(filename, file);
			dish_No = size;
			isValid = true;
		}
		else {
			filename = nullptr;
			isValid = false;
			dish_No = 0;
			csv = false;
		}
	}

	Dish::Dish(const Dish& d)
	{
		*this = d;
	}

	void Dish::setCsv(bool flag)
	{
		csv = flag;
		for (int i = 0; i < dish_No; i++)
			Dishes[i].setCsvMode(flag);
	}

	bool Dish::isCsv()const
	{
		return csv;
	}

	bool Dish::isEmpty()
	{
		return !isValid;
	}

	Dish::operator bool()
	{
		if (isValid)
			return true;
		return false;
	}

	std::istream& Dish::read(std::istream& is)
	{
			for (int i = 0; i <this->dish_No; i++)
				Dishes[i].read(is);
		
		return is;

	}

	std::ostream& Dish::write(std::ostream& os) const
	{
		if (isValid) {
			if (isCsv()) {
				for (int i = 0; i <dish_No; i++) {
					Dishes[i].write(os);
				}
			}
			else {
				for (int i = 0; i <dish_No; i++) {
					if (strcmp(Dishes[i].getCateg(), Dishes[i - 1].getCateg()) != 0) 
						os << "\t\t\t\t-------------------------" << Dishes[i].getCateg() << "------------------------" << endl;
					os << setw(33) << setfill(' ') << right << (i + 1)<<"- " << Dishes[i];
					/*Dishes[i].write(os);*/
				}
			}
			return os;
		}
	}


	bool Dish::operator==(const char* dish)
	{
		for (int i = 0; i < dish_No; i++) {
			if (strcmp(this->Dishes[i].dish_name, dish) == 0)
				return true;
		}
		return false;
	}

	Dish& Dish::operator=(const Dish& d)
	{
		if (d.isValid) {
			this->dish_No = d.dish_No;
			for (int i = 0; i < dish_No; i++) {
				strcpy(this->Dishes[i].dish_name, d.Dishes[i].dish_name);
				strcpy(this->Dishes[i].category, d.Dishes[i].category);
				this->Dishes[i].isValid = d.Dishes[i].isValid;
				this->filename = new char[strlen(d.filename) + 1];
				strcpy(this->filename, d.filename);
				this->isValid = d.isValid;
			}
		}
		return *this;
	}

	int Dish::search(const char* dishname)
	{
		if (dishname) {
			for (int i = 0; i < dish_No; i++) {
				if (strcmp(this->Dishes[i].dish_name, dishname) == 0)
					return i;
			}
		}
		return 0;
	}


	bool Dish::add(const char* dish, const char* categ,int price)
	{
		bool check = false;
		int index = 0;
		if (dish_No < MAX_DISHES) {
			for (int i = 0; i < dish_No; i++) {
				if (strcmp(Dishes[i].category, categ) == 0) {
					index = i;
					for (int i = dish_No-1; i > index; i--) {
						strcpy(Dishes[i+1].dish_name, Dishes[i].dish_name);
						strcpy(Dishes[i+1].category, Dishes[i].category);
						Dishes[i+1].dish_price = Dishes[i].dish_price;
					}
					strcpy(this->Dishes[index].dish_name, dish);
					strcpy(this->Dishes[index].category, categ);
					this->Dishes[index].dish_price = price;
					check = true;
					dish_No++;
					break;
				}
			}
			if (!check) {
						strcpy(this->Dishes[dish_No].dish_name, dish);
						strcpy(this->Dishes[dish_No].category, categ);
						this->Dishes[dish_No].dish_price = price;
						check = true;
						dish_No++;
				}
			}
		return check;
			
	}
		
	

	bool Dish::updateCateg(const char* name, const char* categ)
	{
		if (name != nullptr && categ!=nullptr) {
			for (int i = 0; i < dish_No; i++) {
				if (strcmp(this->Dishes[i].dish_name, name) == 0) {
					strcpy(this->Dishes[i].category, categ);
					return true;
				}
			}
		}
		return false;
	}

	bool Dish::updateName(const char* name, const char* newname)
	{
		if (name && newname) {
			for (int i = 0; i < dish_No; i++) {
				if (strcmp(this->Dishes[i].dish_name, name) == 0) {
					strcpy(this->Dishes[i].dish_name, newname);
					return true;
				}
			}
		}
		return false;
	}

	//bool Dish::updateName(const char* name, const char* newname)
	//{
	//	if (name != nullptr) {
	//		for (int i = 0; i < dish_No; i++) {
	//			/*if (strcmp(Dishes[i].dish_name, name) == 0) {
	//				strcmp(Dish)
	//				return true;*/
	//			}
	//		}
	//	}
	//	return false;
	//}

	bool Dish::deleteDish(const char* name)
	{
		bool flag = false;
		int i = 0, j = 0, size = dish_No;
		for (i = 0; i <size; i++) {
			if (strcmp(Dishes[i].dish_name, name)==0) {
				for (j = i; j <=(dish_No - 1); j++) {
					strcpy(Dishes[j].dish_name, Dishes[j + 1].dish_name);
					Dishes[j].dish_price = this->Dishes[j + 1].dish_price;
					strcpy(Dishes[j].category, Dishes[j + 1].category);
					flag = true;
					i--;
					size--;
				}
			}
		}
		if (flag) {
			dish_No--;
			}

		return flag;
	}

	int Dish::getDishNo() const
	{
		return dish_No;
	}

	bool Dish::updatePrice(const char* name, int price) {
		if (name != nullptr) {
			for (int i = 0; i < dish_No; i++) {
				if (strcmp(Dishes[i].dish_name, name) == 0) {
					Dishes[i].dish_price = price;
					return true;
				}
			}
		}
		return false;
	}

	void Dish::setEmpty()
	{
		filename = nullptr;
		dish_No = 0;
		isValid = false;
	}

	Dish::~Dish()
	{
		if (filename)
			delete[] filename;
	}

	std::ostream& operator<<(std::ostream& os, const DishItem& dt)
	{
		dt.write(os);
		/*os << setw(50) << setfill(' ') << right << dt.dish_name << setw(33) << setfill(' ') << (std::right) << dt.dish_price << endl;*/
		return os;
	}

	std::istream& operator>>(std::istream& is, DishItem& d)
	{
		d.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Dish& d)
	{
		d.write(os);
		return os;
	}

}
