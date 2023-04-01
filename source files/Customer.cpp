#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include<iostream>
#include<iomanip>
using namespace std;
namespace dsa {
	User::User()
	{
		name = nullptr;
		address = nullptr;
		phone = 0;
		Csv = false;
	}
	User::User(const User& us)
	{
		this->operator=(us);
	}
	bool User::isEmpty() const
	{
		return name == nullptr;
	}
	void User::setEmpty()
	{
		name = nullptr;
		address = nullptr;
		phone = 0;
		Csv = false;
	}
	void User::add(const char*	Name, const char* Address,unsigned long no)
	{
		if (Name && Address && no) {
			name = new char[strlen(Name)+1];
			address = new char[strlen(Address)+1];
			strcpy(name, Name);
			strcpy(address, Address);
			this->phone = no;
			
		}
	}
	bool User::searchName(const char* Name)
	{
		return !strcmp(this->name, Name);
	}
	bool User::searchPh(unsigned long n)
	{
		return this->phone == n;
	}

	bool User::searchAdd(const char* ad)
	{
		return !strcmp(this->address, ad);
	}

	bool User::updateName(const char* newname)
	{
		if (newname != nullptr) {
			name = new char[strlen(newname) + 1];
				strcpy(this->name, newname);
				return true;
		}
		return false;
	}
	bool User::updateAdd(const char* Add)
	{
		if (Add != nullptr) {
				strcpy(this->address, Add);
				return true;
		}
		return false;
		
	}
	bool User::updatePh(const unsigned long no)
	{
		if (no>0) {
				this->phone = no;
				return true;
		}
		return false;
	}

	bool User::operator==(User& user)
	{
		if(this->phone == user.phone && !strcmp(this->name,user.name ) && !strcmp(this->address,user.address))
			return true;
		return false;
	}

	User& User::operator=(const User& us)
	{
		if (!us.isEmpty()) {
			this->name = new char[strlen(us.name)+1];
			strcpy(this->name, us.name);
			this->address = new char[strlen(us.name)+1];
			strcpy(this->address, us.address);
			this->phone = us.phone;
			this->Csv = us.Csv;
		}
		return *this;
	}
	void User::setCsv(bool flag)
	{
		Csv = flag;
	}
	bool User::isCsv() const
	{
		return Csv;
	}
	unsigned long User::getNumber() const
	{
		return this->phone;
	}
	const char* User::getName() const
	{
		return this->name;
	}
	const char* User::getAdd() const
	{
		return this->address;
	}
	void User::setName(const char* N)
	{
		strcpy(this->name, N);
	}

	void User::setPhone(unsigned long n)
	{
		this->phone = n;
	}


	void User::setAdd(const char* add)
	{
		strcpy(this->address, add);
	}

	std::ostream& User::write(std::ostream& os) const
	{
		if (!isEmpty()) {
			if (isCsv()) {
				os << this->name << "," << this->phone << "," << this->address << endl;
			}
			else {
				os << setw(22) << setfill(' ') << right << this->name << setw(10) << setfill(' ') << right <<"03" << this->phone
					<< setw(18) << setfill(' ') << right << this->address << endl;
			}
		}
		return os;
	}
	std::istream& User::read(std::istream& is)
	{
		if (this->isCsv()) {
			char Name[50];
			char ad[50];
			is.getline(Name, 50, ',');
			is >> phone;
			char c;
			is.get(c);
			is.getline(ad, 50, '\n');
			this->name = new char[strlen(Name) + 1];
			this->address = new char[strlen(ad) + 1];
			strcpy(this->name, Name);
			strcpy(address, ad);

			
		}
		else {
			cout << "\t\t\tEnter Name: ";
			char n[50];
			cin.getline(n, 50);
			name = new char[strlen(n) + 1];
			strcpy(name, n);

			char a[100];
			cout << "\t\t\tEnter Phone: ";
			cin >> phone;
			while ((getchar()) != '\n');

			cout << "\t\t\tEnter Address: ";
			cin.getline(a, 100);
			address = new char[strlen(a) + 1];
			strcpy(address, a);
			while ((getchar()) != '\n');
		}
		return is;
	}
	void User::display() const
	{
		if (!isEmpty()) {
			cout << "\t\t\tName: " << name << endl;
			cout << "\t\t\tPhone: " << phone << endl;
			cout << "\t\t\tAddress: " << address << endl;
		}
		else
			cout << "\t\t\tEmpty Object!" << endl;
	}
	User::~User()
	{
		if (!isEmpty()) {
			delete[] name;
			delete[] address;
		}
	}

	Customer& Customer::operator=(const Customer& cust)
	{
		if (!cust.isEmpty()) {
			User::operator=(cust);
		}
		return *this;
	}

	std::ostream& Customer::write(std::ostream& os) const
	{
		if (!isEmpty()) {
			User::write(os);
		}
			
		else
			cout << "\t\t\tInvalid Data!" << endl;
		return os;
	}
	std::istream& Customer::read(std::istream& is)
	{
		User::read(is);
		return is;
	}
	Customer::Customer() :User() { }
	Customer::Customer(const Customer& cust):User(cust){}

	Customer::operator bool() const
	{
		return name != nullptr;
	}
	
}

