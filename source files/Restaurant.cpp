#define _CRT_SECURE_NO_WARNINGS
#include"Restaurant.h"
#include"Employee.h"
#include"Customer.h"
#include"Dish.h"
#include"Order.h"
#include<iostream>
#include<fstream>
#include<iomanip>

const char username[] = "admin123";
const char password[] = "sarah123";

using namespace std;
namespace dsa {
	Restaurant::Restaurant()
	{
		dishFile = nullptr;
		empFile = nullptr;
		orderFile = nullptr;
		Head = nullptr;
		tail = nullptr;
		emp = nullptr;
		dishMenu = nullptr;
		totalOrders = 0;
		isCsv = false;
	}
	Restaurant::Restaurant(const char* file1, const char* file2, const char* file3)
	{
		Head = nullptr;
		tail = nullptr;
		setEmpty();

		if (file1 && file2 && file3) {
			empFile = new char[strlen(file1) + 1];
			strcpy(empFile, file1);
			dishFile = new char[strlen(file2) + 1];
			strcpy(dishFile, file2);
			orderFile = new char[strlen(file3) + 1];
			strcpy(orderFile, file3);
			isCsv = false;
			load();
		}
		else {
			setEmpty();
		}
	}
	bool Restaurant::isEmpty() const
	{
		return Head == nullptr;
	}
	void Restaurant::setEmpty()
	{
		dishFile = nullptr;
		empFile = nullptr;
		orderFile = nullptr;
		Head = nullptr;
		tail = nullptr;
		emp = nullptr;
		dishMenu = nullptr;
		totalOrders = 0;
		isCsv = false;
	}
	int Restaurant::run()
	{
		bool end = false;
		while (!end) {
			system("cls");
			mainMenu();
			switch (getIntInRange(1, 3)) {

			case 1:
				if (login()) {
					for (int i = 0; i < 7; i++)
						cout << "    ";
					cout << "Login success!" << endl;
					admin();
					cout << "Press <ENTER> to continue...";
					cin.ignore();
				}
				else {
					for (int i = 0; i < 7; i++)
						cout << "    ";
					cout << "Incorrect username and Password! ACCESS DENIED!" << endl;
					cout << "\t\t\t\tPress <ENTER> to continue...";
					cin.ignore();
				}


				break;

			case 2:
				customer();
				break;
			case 3:
				end = true;
				break;
			}
		}
		return 0;
	}
	void Restaurant::mainMenu() const
	{

		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t       Venice Italian Cuisine       " << endl;
		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t1- Admin" << endl;
		cout << "\t\t\t2- Customer" << endl;
		cout << "\t\t\t3- Exit Application" << endl;
		cout << "\t\t\t> ";

	}

	void Restaurant::admin()
	{
		cout << "\t\t\t    Press <ENTER> to continue...";
		cin.ignore();
		bool end = false;
		while (!end) {
			system("cls");
			cout << "\t\t\t----------------------------------" << endl;
			cout << "\t\t\t           WELCOME BACK          " << endl;
			cout << "\t\t\t----------------------------------" << endl;
			cout << "\t\t\t1- View Employees" << endl;
			cout << "\t\t\t2- Modify Employee" << endl;
			cout << "\t\t\t3- Search Employee" << endl;
			cout << "\t\t\t4- Add Employee" << endl;
			cout << "\t\t\t5- Delete Employee" << endl;
			cout << "\t\t\t6- View Menu" << endl;
			cout << "\t\t\t7- Add a Dish to Menu" << endl;
			cout << "\t\t\t8- Modify a Dish from Menu" << endl;
			cout << "\t\t\t9- Delete a Dish from Menu" << endl;
			cout << "\t\t\t10- View Total Orders" << endl;
			cout << "\t\t\t11- View recent Order" << endl;
			cout << "\t\t\t12- logout" << endl;
			cout << "\t\t\t> ";
			int choice = getIntInRange(1, 12);
			switch (choice) {
			case 1:
			{
				system("cls");
				cout << "\t\t\t\t ------------------------------------------------" << endl;
				cout << "\t\t\t\t           E M P L O Y E E S    D A T A         " << endl;
				cout << "\t\t\t\t ------------------------------------------------" << endl;
				cout << setw(25) << setfill(' ') << right << "S.No" << setw(16) << setfill(' ') << right << "Post"
					<< setw(18) << setfill(' ')
					<< right << "Name" << setw(22) << setfill(' ') << right << "Phone No."
					<< setw(18) << setfill(' ') << (std::right) << "Address" << endl;
				cout << "\t\t    ---------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < total_emp; i++) {
					emp[i].setCsv(0);
					cout << setw(22) << setfill(' ') << right << (i + 1) << "- ";
					emp[i].write(cout);
				}
				cout << "\n\t\t\t    Press <ENTER> to continue...";
				cin.ignore();

				break;
			}

			case 2:
			{
				if (this->emp != nullptr) {
					editEmployee();
					save();
				}
				else
					cout << "\t\t\tNo Employee Data found!" << endl;

				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();

				break;
			}
			case 3:
			{
				if (this->emp != nullptr) {
					searchEmployee();
				}
				else
					cout << "\t\t\tNo Employee Data found!" << endl;

				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 4:
			{
				addEmployee();
				save();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();

				break;
			}
			case 5:
			{
				if (emp != nullptr) {
					deleteEmployee();
					save();
				}
				else
					cout << "\t\t\tNo Employee Data exists!" << endl;

				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;

			}

			case 6:
			{
				system("cls");
				cout << "\t\t\t\t\t  ---------------------------- " << endl;
				cout << "\t\t\t\t\t             M E N U          " << endl;
				cout << "\t\t\t\t\t  ---------------------------- " << endl;
				dishMenu->setCsv(0);
				cout << *dishMenu << endl;
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 7:
			{
				addDish();
				save();
				cin.ignore();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}
			case 8:
			{
				editDish();
				save();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}
			case 9:
			{
				char n[20];
				cout << "\t\t\tEnter Dish Name: ";
				cin.getline(n, 20);
				cin.clear();
				if (dishMenu->deleteDish(n)) {
					cout << "\t\t\tDish Deleted!" << endl;

				}
				else
					cout << "\t\t\tError occurred while deleting Dish!" << endl;

				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 10:
			{
				if (!totalOrders)
					cout << "\t\t\tNo Orders right now!" << endl;
				else {
					this->isCsv = 0;
					printList(cout);
				}
					
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 11:
			{
				if (Head) {
					tail->setCsv(0);
					cout << *tail << endl;
				}
				else
					cout << "No order right now!" << endl;
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}
			case 12:
			{
				cout << "\t\t\tAre you sure? y(es)/n(o): ";
				string ch;
				cin >> ch;
				while (ch != "y" && ch != "n") {
					cout << "\t\t\tInvalid response! Only y/n acceptable, Try again: ";
					cin >> ch;
				}
				if (ch == "y")
					cout << "\t\t\tSaving Data....." << endl;
				if (save()) {
					cout << "\t\t\tData Saved!" << endl;
				}
				else {
					cout << "\t\t\tError Saving data!" << endl;
				}
				end = true;
				break;
			}
			}

		}
	}


	void Restaurant::editEmployee()
	{
		cout << "\t\t\t\tWhat do you want to update?" << endl;
		cout << "\t\t\t\t\t1- Name" << endl;
		cout << "\t\t\t\t\t2- Phone" << endl;
		cout << "\t\t\t\t\t3- Address" << endl;
		cout << "\t\t\t\t\t4- Post" << endl;
		cout << "\t\t\t\t\t5- All Info" << endl;
		cout << "\t\t\t\t\t> ";
		int choice = getIntInRange(1, 4);
		char name[30];
		cout << "\t\t\t\t\tEnter Name of the Employee you want to modify: ";
		cin.getline(name, 30);
		while ((getchar()) != '\n');
		bool check = false;
		switch (choice) {
		case 1:
		{
			cout << "\t\t\t\t\tEnter new Name:" << endl;
			char n[20];
			cin.getline(n, 20);
			for (int i = 0; i < total_emp; i++) {
				if (emp[i].searchName(name)) {
					if (emp[i].updateName(n)) {
						check = true;
						break;
					}
					else
						cout << "\t\t\t\t\tError modifying Data" << endl;

				}
			}
		}
		break;

		case 2:
		{
			cout << "\t\t\t\t\tEnter new Phone Number:" << endl;
			unsigned long n;
			cin >> n;
			cin.ignore();
			for (int i = 0; i < total_emp; i++) {
				if (emp[i].searchName(name)) {
					if (emp[i].updatePh(n)) {
						check = true;
						break;
					}
					else
						cout << "\t\t\t\t\tError modifying Data" << endl;

				}
			}
		}
		break;

		case 3:
		{
			char add[100];
			cout << "\t\t\t\t\tEnter new Address:" << endl;
			cin.getline(add, 100);
			for (int i = 0; i < total_emp; i++) {
				if (emp[i].searchName(name)) {
					if (emp[i].updateAdd(add)) {
						check = true;
						break;
					}
					else
						cout << "\t\t\t\t\tError modifying Data" << endl;

				}
			}

		}
		break;

		case 4:
		{
			char Post[20];
			cout << "\t\t\t\t\tEnter new Post:" << endl;
			cin.getline(Post, 100);
			for (int i = 0; i < total_emp; i++) {
				if (emp[i].searchName(name)) {
					if (emp[i].updatePost(Post)) {
						check = true;
						break;
					}
					else
						cout << "\t\t\t\t\tError modifying Data!" << endl;

				}
			}
		}
		break;

		case 5:
		{
			unsigned long n;
			cout << "\t\t\t\t\tEnter new Name:" << endl;
			cin.getline(name, 30);
			cout << "\t\t\t\t\tEnter new Phone Number:" << endl;
			cin >> n;
			char add[100];
			cout << "\t\t\t\t\tEnter new Address:" << endl;
			cin.getline(add, 100);
			char Post[20];
			cout << "\t\t\t\t\tEnter new Post:" << endl;
			cin.getline(Post, 100);
			for (int i = 0; i < total_emp; i++) {
				if (emp[i].searchName(name)) {
					if (emp[i].updatePost(Post)) {
						emp[i].updateName(name);
						emp[i].updatePh(n);
						emp[i].updateAdd(add);
						check = true;
						break;
					}
					else
						cout << "\t\t\t\t\tError modifying Data!" << endl;

				}
			}

		}
		break;

		}

		if (check) {
			cout << "\t\t\t\t\tData Modified!" << endl;

		}
			
		else
			cout << "\t\t\t\t\tNo Employee exists with this Name!" << endl;
	}

	void Restaurant::searchEmployee()
	{
		char n[20];
		bool check = false;
		cout << "\t\t\tEnter the name of the Employee to search: ";
		cin.getline(n, 20);
		cin.clear();
		for (int i = 0; i < total_emp; i++) {
			if (emp[i].searchName(n)) {
				cout << "\t\t\tFound!" << endl;
				emp[i].display();
				check = true;
			}
		}
		if (!check)
			cout << "\t\t\tNo Employee Found with this Name!" << endl;
	}

	void Restaurant::addEmployee()
	{
		Employee* temp = new Employee[total_emp + 1];
		/*for (int i = 0; i < total_emp; i++) {
			temp[i] = emp[i];
		}*/
		std::copy(emp, emp + total_emp, temp);
		temp[total_emp].read(cin);
		temp[total_emp].display();
		total_emp++;
		if (emp != nullptr) {
			delete[] emp;
		}
		emp = temp;

	}

	void Restaurant::deleteEmployee()
	{
		bool flag = false;
		int k = 0;
		char n[50];
		cout << "\t\t\tEnter Name of Employee: ";
		cin.getline(n, 50);
		cin.clear();
		int size = total_emp;
		for (k = 0; k < size-1; k++) {
			
			if (!strcmp(emp[k].getName(), n)) {
				Employee* newEmp = new Employee[total_emp - 1];
				std::copy(emp, emp + k, newEmp);
				std::copy(emp + k + 1, emp + total_emp, newEmp + k);
				delete[] emp;
				emp = newEmp;
				total_emp--;
				flag = true;
				break;
			}

		}
		if (flag) {
			cout << "\t\t\tEmployee Deleted!" << endl;
			return;
		}

		cout << "\t\t\tNo Employee found with this Name!" << endl;
	}


	bool Restaurant::login()
	{
		for (int i = 0; i < 7; i++) {
			cout << "    ";
		}
		cout << "Please Authorize yourself!" << endl;
		for (int i = 0; i < 7; i++) {
			cout << "    ";
		}
		cout << "1- Enter username: ";
		char user[20], pass[20];
		char c;
		cin.getline(user, 20);
		for (int i = 0; i < 7; i++) {
			cout << "    ";
		}
		cout << "2- Enter password: ";
		cin.getline(pass, 20);

		if (!strcmp(user, username) && !strcmp(pass, password)) {
			return true;
		}
		return false;
	}
	void Restaurant::customer()
	{
		bool end = false;
		while (!end) {
			system("cls");
			cout << "\t\t\t-------------------------------------------------------" << endl;
			cout << "\t\t\t           WELCOME TO VENICE ITALIAN CUISINE          " << endl;
			cout << "\t\t\t-------------------------------------------------------" << endl;
			cout << "\t\t\t1- View Menu" << endl;
			cout << "\t\t\t2- Place Order" << endl;
			cout << "\t\t\t3- View your Order" << endl;
			cout << "\t\t\t4- Delete Order" << endl;
			cout << "\t\t\t5- Modify Order" << endl;
			cout << "\t\t\t6- Go Back" << endl;
			cout << "\t\t\t> ";
			int choice = getIntInRange(1, 6);
			switch (choice) {
			case 1:
			{
				dishMenu->setCsv(0);
				cout << *dishMenu;
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "\t\t\t\t\t  ----------------------------" << endl;
				cout << "\t\t\t\t\t             M E N U          " << endl;
				cout << "\t\t\t\t\t  ----------------------------" << endl;
				dishMenu->setCsv(0);
				cout << *dishMenu << endl;
				addOrder();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}
			case 3:
			{
				printOrder();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 4:
			{
				deleteOrder();
				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
				break;
			}

			case 5:
			{
				string str;
				if (Head) {
					editOrder();
				}
				else
					cout << "\t\t\tYou have placed no orders!" << endl;

				cout << "\t\t\t    Press <ENTER> to continue...";
				cin.ignore();
			}
			break;
			case 6:
				end = true;
				break;
			}
		}

	}
	void Restaurant::editDish()
	{
		cout << "\t\t\t\tWhat do you want to update?" << endl;
		cout << "\t\t\t\t1- Name" << endl;
		cout << "\t\t\t\t2- Category" << endl;
		cout << "\t\t\t\t3- Price" << endl;
		cout << "\t\t\t\t> ";
		int choice = getIntInRange(1, 3);
		char name[20];
		cout << "\t\t\t\tEnter name of the Dish you want to modify: ";
		cin.getline(name, 20);

		switch (choice) {
		case 1:
			char n[20];
			cout << "\t\t\t\tEnter new name: ";
			cin.getline(n, 20);
			if (dishMenu->updateName(name, n)) {
				cout << "\t\t\t\tDish Modifed!" << endl;
			}
			else {
				cout << "\t\t\t\tError modifying Dish!" << endl;
			}
			break;

		case 2:
			char c[20];
			cout << "\t\t\t\tEnter new Category: ";
			cin.getline(c, 20);
			if (dishMenu->updateCateg(name, c)) {
				cout << "\t\t\t\tDish Modifed!" << endl;
			}
			else {
				cout << "\t\t\t\tError modifying Dish!" << endl;
			}
			break;

		case 3:
			int p;
			cout << "\t\t\t\tEnter new Price: ";
			cin >> p;
			if (dishMenu->updatePrice(name, p)) {
				cout << "\t\t\t\tDish Modifed!" << endl;
			}
			else {
				cout << "\t\t\t\tError modifying Dish!" << endl;
			}
			break;

		}
	}
	void Restaurant::createOrder(istream& is)
	{
		order *new_order = new order;
		new_order->Csv = 1;
		new_order->read(is);

		if (Head == nullptr) {

			Head = new_order;
			tail = new_order;
			
		}
		else {
			tail->Next = new_order;
			new_order->Next = Head;
			tail = new_order;
		}
	
	}
	void Restaurant::editOrder()
	{
		cout << "\t\t\t\tWhat do you want to update?" << endl;
		cout << "\t\t\t\t1- Your Name" << endl;
		cout << "\t\t\t\t2- Your Phone" << endl;
		cout << "\t\t\t\t3- Your Address" << endl;
		cout << "\t\t\t\t4- Dish Name" << endl;
		cout << "\t\t\t\t5- Add another Dish to order" << endl;

		cout << "\t\t\t\t> ";
		int choice = getIntInRange(1, 5);

		switch (choice) {
		case 1:
			char n[20];
			cout << "\t\t\t\tEnter new Name: ";
			cin.getline(n, 20);
			tail->cust->setName(n);
			cout << "\t\t\t\tOrder Modified!" << endl;

			break;

		case 2:
			unsigned long N;
			cout << "\t\t\tEnter new Phone: ";
			cin >> N;
			tail->cust->updatePh(N);
			cout << "\t\t\tOrder Modified!" << endl;
			break;

		case 3:
			char add[50];
			cout << "\t\t\tEnter new Address: ";
			cin.getline(add, 20);
			tail->cust->updateAdd(add);
			cout << "\t\t\tOrder Modified!" << endl;
			break;

		case 4:
		{
			cout << dishMenu << endl;
			cout << "\t\t\tEnter Dish number you want to order: ";
			int choice = getIntInRange(1, dishMenu->dish_No);
			tail->dishes[tail->totalDishes] = dishMenu->Dishes[choice];
			cout << "\t\t\tOrder Modified!" << endl;
			break;
		}

		case 5:
		{
			cout << dishMenu << endl;
			cout << "\t\t\tEnter Dish number you want to order: ";
			int choice = getIntInRange(1, dishMenu->dish_No);
			tail->dishes[tail->totalDishes] = dishMenu->Dishes[choice];
			tail->totalDishes++;
			cout << "\t\t\tOrder Modified!" << endl;
			break;
		}
		}


	}
	void Restaurant::addDish()
	{
		cout << "\t\t\tEnter the Dish Category: ";
		char name[20], categ[10];
		int price;
		cin.getline(categ, 20);
		cin.clear();
		cout << "\t\t\tEnter dish Name: ";
		cin.getline(name, 20);
		cin.clear();
		cout << "\t\t\tEnter price: ";
		cin >> price;


		if (dishMenu->add(name, categ, price)) {
			cout << "New Dish added to Menu! " << endl;
		}
		else
			cout << "Error occurred while adding Dish!" << endl;
	}
	void Restaurant::addOrder()
	{
		int size = 0;
		cout << "\t\t\tHow many dishes do you want to order: ";
		cin >> size;
		order* new_order = new order;
		new_order->dishes = new DishItem[size];
		new_order->totalDishes = size;

		int i = 0;
		cout << "\t\t\tEnter dish Number of the dish you want to order: ";
		while (i < size) {
			int dishNo = getIntInRange(1, dishMenu->getDishNo());
			for (int j = 0; j <= dishMenu->dish_No; j++) {
				if ((j + 1) == dishNo) {
					new_order->dishes[i] = dishMenu->Dishes[j];
				}
			}
			i++;
		}
		new_order->Csv = 0;
		new_order->read(cin);

		if (!cin.fail()) {
			if (this->isEmpty()) {

				Head = new_order;
				tail = new_order;

			}
			else {
				tail->Next = new_order;
				new_order->Next = Head;
				tail = new_order;
			}

		
			cout << "\t\t\tOrder Placed succcessfully!" << endl;
			ofstream ofptr;
			ofptr.open(orderFile, ios::app);
			new_order->setCsv(1);
			new_order->write(ofptr);
			ofptr.close();
			totalOrders++;
			cout << totalOrders;
			cout << endl;
		}
		else
			cout << "\t\t\tError reading the data!" << endl;


	}

	
	void Restaurant::deleteOrder()
	{
		order* temp = tail;
		if (!isEmpty()) {
			if (temp->Next == temp) {
				delete Head;
				this->Head = nullptr;
				this->tail = nullptr;
			}
			else {
				while (temp->Next != tail) {
					temp = temp->Next;
				}
				temp->Next = Head;
				delete tail;
				tail = temp;
			}


			cout << "\t\t\tOrder deleted!" << endl;
		}
		else
			cout << "You have placed no Order!" << endl;

	}
	void Restaurant::printOrder() const
	{
		order* temp = tail;
		if (!isEmpty()) {
			temp->Csv = 0;
			temp->write(cout);
			/*temp = temp->Next;*/
			while (temp->Next != tail && temp->Next!=nullptr) {
				temp = temp->Next;
			}
			/*if (!strcmp(tail->cust->getName(), temp->cust->getName())) {
				temp->write(cout);
			}*/
		}
		else
			cout << "You have placed no Orders!" << endl;
	}
	void Restaurant::printList(std::ostream& os) const
	{
		order* temp = Head;
		if (Head !=nullptr) {
			do {
				if (isCsv)
					temp->setCsv(1);
				else
					temp->setCsv(0);

				temp->write(os);
				temp = temp->Next;
				
			} while (temp != Head);
		}
		else
			cout << "No orders right now!" << endl;

	}
	void Restaurant::load()
	{
			ifstream ifptr1, ifptr2, ifptr3;
			ifptr1.open(dishFile);
			ifptr2.open(empFile);
			ifptr3.open(orderFile,ios::app);
			if (!ifptr1 && !ifptr2 && !ifptr3) {
				cout << "Error opening the file!" << endl;
			}
			else {
				dishMenu = new Dish(dishFile, fileSize(dishFile));
				int size = fileSize(empFile);
				emp = new Employee[size];
				total_emp = size;
				dishMenu->setCsv(1);
				dishMenu->isValid = true;
				dishMenu->read(ifptr1);
				for (int i = 0; i < size; i++) {
					emp[i].setCsv(1);
					emp[i].read(ifptr2);
				}

				if (!ifptr1.fail() && !ifptr2.fail()) {
					dishMenu->setCsv(0);
					for (int i = 0; i < size; i++) {
						emp[i].setCsv(0);
					}
				}

				int i = 0;
				size = orders(orderFile);
				
				while (i < size) {
					createOrder(ifptr3);
					i++;
					totalOrders++;
				}
			}

		
	}

	bool Restaurant::save()
	{
		ofstream ofptr1, ofptr2, ofptr3;
		ofptr1.open(empFile, ios::trunc);
		ofptr2.open(dishFile, ios::trunc);
		ofptr3.open(orderFile, ios::trunc);
		if (ofptr1.is_open() && ofptr2.is_open() && ofptr3.is_open()) {
			if (emp) {
				for (int i = 0; i < total_emp; i++) {
					emp[i].setCsv(1);
					emp[i].write(ofptr1);
				}
			}
			else
				cout << "\t\t\t\t\tNo Employee Data exists to be saved!" << endl;
			ofptr1.close();

			if (!dishMenu->isEmpty()) {
				dishMenu->setCsv(1);
				dishMenu->write(ofptr2);
			}
			else
				cout << "\t\t\t\t\tNo Dish data exists to be saved!" << endl;
			ofptr2.close();

			if (Head != nullptr) {
				this->isCsv = 1;
				this->printList(ofptr3);

			}

			return true;

		}
		return false;
	}

	bool Restaurant::closeRestaurant()
	{
		return false;
	}

	Restaurant::~Restaurant()
	{
		if (Head) {
			save();
			delete[] dishFile;
			delete[] orderFile;
			delete[] empFile;
			delete[] emp;
			delete dishMenu;
		}
	}






}