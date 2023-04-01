#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Employee.h"
#include<iomanip>
using namespace std;
namespace dsa {
	Employee::Employee():User(){
		post = nullptr;
	}

	Employee::Employee(const Employee& e):User(e)
	{
		post = nullptr;

		if (!e.isEmpty()) {
			this->post = new char[strlen(e.post) + 1];
			strcpy(this->post, e.post);
		}
	}

	Employee& Employee::operator=(const Employee& e)
	{
		if (!e.isEmpty()) {
			this->post = new char[strlen(e.post) + 1];
			strcpy(this->post, e.post);
			User::operator=(e);
		}
		return *this;
	}

	bool Employee::operator==(Employee& emp)
	{
		if (User::operator==(emp))
			return !strcmp(this->post, emp.post);

			return false;
		
	}

	void Employee::add(const char* Name, const char* Address, unsigned long no,const char* P)
	{
		if (!strcmp(this->name, Name)) {
			User::add(Name, Address, no);
			this->post = new char[strlen(P + 1)];
			strcpy(this->post, P);
		}
		else
			cout << "\t\t\tEnter valid Information" << endl;
		
	}


	bool Employee::updatePost(const char* Post)
	{
		if (Post != nullptr) {
			post = new char[strlen(Post) + 1];
			strcpy(post, Post);
			return true;
		}
		return false;
	}

	bool Employee::searchPost(const char* p)
	{
		return !strcmp(this->post, p);
	}

	void Employee::setPost(const char* P)

	{
		post = new char[strlen(P) + 1];
		strcpy(this->post, P);
	}

	const char* Employee::getPost() const
	{
		return this->post;
	}

	/*bool Employee::searchName(const char* p)
	{
		return !strcmp(this->name)
	}*/


	std::ostream& Employee::write(std::ostream& os) const
	{
		if (post) {
			if (this->isCsv()) {
				os << this->post << ",";
				User::write(os);
			}
			else {
				
				os << setw(17) << setfill(' ') << right<< post;
				User::write(os);
			}
		}
		else
			cout << "Writing Data failed!" << endl;
		
		return os;
	}

	std::istream& Employee::read(std::istream& is)
	{
			if (this->isCsv()) {
				char p[20];
				is.getline(p, 20, ',');
				post = new char[strlen(p) + 1];
				strcpy(post, p);
				User::read(is);
			}
			else {
				User::read(is);
				char p[25];
				cout << "\t\t\tEnter Post: ";
				is.getline(p, 25);
				post = new char[strlen(p) + 1];
				strcpy(post, p);
				
			}
		
		return is;
	}

	void Employee::display() const
	{
		if (!isEmpty()) {
			User::display();
			cout << "\t\t\tPost: " << post << endl;
		}
		
	}

	Employee::~Employee()
	{
		if (post)
			delete[] post;
	}
	
	ostream& operator<<(ostream& os, const Employee& emp)
	{
		return emp.write(os);
	
	}

	std::istream& operator>>(std::istream& is, Employee& emp)
	{
		return emp.read(is);
	}

}
