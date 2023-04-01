#define _CRT_SECURE_NO_WARNINGS
#include"Order.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
char order_ID[] = "ABC4F23G81";

namespace dsa {
	int orders(const char* file) {
		int size = 1;
			char str[11];
			char c[100];
			char str2[11];
			ifstream ifptr;
			ifptr.open("Orders.csv", ios::in);
		while (ifptr.getline(c, 100)) {
						for (int i = 0; i < 11; i++)
							str[i] = c[i];
						ifptr.getline(c, 100);
						for (int i = 0; i < 11; i++)
							str2[i] = c[i];
			
						if (strcmp(str, str2))
							size++;
					}
		return size;
	}

	int fileSize(const char* file) {

		FILE* fptr = fopen(file, "r");
		int categ = 1;
		char str = 0;
		for (char c = getc(fptr); c != EOF; c = getc(fptr)) {
			if (c == '\n')
				categ++;

		}

		return categ;
	}

	std::ostream& operator<<(std::ostream& os, const order& Order)
	{
		Order.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, order& Order)
	{
		Order.read(is);
		return is;
	}

	int getIntInRange(int min, int max) {
		int i;
		cin >> i;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\t\t\tInvalid Integer, try again: ";
			return getIntInRange(min, max);
		}
		else if (i < min || i > max) {
			cin.ignore(1000, '\n');
			cout << "Invalid selection, try again: ";
			return getIntInRange(min, max);
		}
		else {
			cin.ignore(1000, '\n');
			return i;
		}
	}
	

	order::order()
	{
		totalDishes = 0;
		Next = this;
		dishes = nullptr;
		cust = nullptr;
		order_ID[11] = order_ID[11] + 1;
		strcpy(id, order_ID);
		bill = 0;
		Csv = 0;
	}

	//order::order(int size, DishItem* dt, Customer* cu)
	//{
	//	Next = this;
	//	dishes = nullptr;
	//	cust = nullptr;
	//	id = 0;;
	//	bill = 0;
	//	totalDishes = 0;

	//	if (dt && cu) {
	//		totalDishes = size;
	//		for (int i = 0; i < totalDishes; i++) {
	//			dishes[i] = &dt[i];
	//			strcpy(dishes[i]->dish_name, dt[i].dish_name);
	//			strcpy(dishes[i]->category, dt[i].category);
	//			dishes[i]->dish_price = dt[i].dish_price;
	//		/*	dishes[totalDishes]->isValid = dt[i].isValid;*/

	//			bill += this->dishes[i]->dish_price;
	//		}

	//		cust = new Customer;
	//		cust = cu;
	//		
	//	}
	//	Next = this;
	//}

	bool order::isEmpty() const
	{
		if (dishes == nullptr)
			return true;
		return false;
	}
	void order::setEmpty()
	{
		Next = this;
		dishes = nullptr;
		cust = nullptr;
		id[0] = 0;
		bill = 0;
		totalDishes = 0;
	}
	void order::setId(const char i[])
	{
		strcpy(id, i);
	}
	void order::setBill(int b)
	{
		bill = b;
	}
	int order::getBill() const
	{
		return bill;
	}
	const char* order::getId() const
	{
		return id;
	}

	bool order::isCsv() const
	{
		return Csv;
	}

	void order::setCsv(bool flag)
	{
		Csv = flag;
	}

	
	
	std::istream& order::read(std::istream& is)
	{
		
			if (isCsv()) {
				is.getline(this->id, 11, ',');
			is >> this->totalDishes;
				char c;
				int n;
				is >> c;

				char s[11];
				this->dishes = new DishItem[this->totalDishes];
				this->cust = new Customer;
				this->cust->setCsv(1);
				is.getline(this->dishes[0].dish_name, 31, ',');
				is >> this->dishes[0].dish_price;
				this->bill += this->dishes[0].dish_price;
				is >> c;
				this->cust->read(is);

				for (int i = 1; i < totalDishes; i++) {
					is.getline(this->id, 11, ',');
					is >> this->totalDishes;
					is >> c;
					is.getline(this->dishes[i].dish_name,31, ',');
					is >> this->dishes[i].dish_price;
					this->bill += this->dishes[i].dish_price;
					is >> c;
					this->cust->read(is);
				}
				this->cust->setCsv(0);
			}
				
			else {
				this->cust = new Customer;
				this->cust->setCsv(0);
				this->cust->read(is);
				for (int i = 0; i < totalDishes; i++) {
					bill += this->dishes[i].dish_price;
				}

			}

		return is;
	}
	std::ostream& order::write(std::ostream& os)const
	{
		if (!isEmpty()) {
			if (isCsv()) {
				for (int i = 0; i < totalDishes; i++) {
					os << this->id << ",";
					os << this->totalDishes;
					os << "," << this->dishes[i].dish_name << "," << this->dishes[i].dish_price << ",";
					this->cust->setCsv(1);
					this->cust->write(os);
				}
			}
			else {
				cout << "\t\t\t-------------- ORDER ID# " << this->id << "---------------" << endl;
				cout << "\t\t\tDish Info: " << endl;
				for (int i = 0; i < totalDishes; i++) {
					cout << "\t\t\t" << i + 1 << "- " << "Dish: " << this->dishes[i].dish_name << endl;
					cout << "\t\t\tPrice: " << this->dishes[i].dish_price << endl;
				}
				cout << "\n\t\t\tCustomer Info: " << endl;
				this->cust->setCsv(0);
				cout << "\t\t\tName: " << this->cust->getName() << endl;
				cout << "\t\t\tPhone Number: " << this->cust->getNumber() << endl;
				cout << "\t\t\tAddress: " << this->cust->getAdd() << endl << endl;

				cout << "\t\t\tTotal Bill: Rs " << bill << endl << endl;
				cout << "\t\t\t---------------------------------------------" << endl;
			}
		}
		else
			cout << "aaaa";


		return os;
	}
	order::~order()
	{
		if (dishes) {
			delete[] dishes;
			delete cust;
		}
	}
	
}


	