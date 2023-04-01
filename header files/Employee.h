#ifndef DSA_EMPLOYEE_H
#define DSA_EMPLOYEE_H
#include<iostream>
#include"Customer.h"
namespace dsa {
	class Employee : public User {
	private:
		char* post;
	public:
		Employee();
		Employee(const Employee& e);
		Employee& operator=(const Employee& e);
		bool operator==(Employee& emp);
		virtual void add(const char* Name, const char* Address, unsigned long no, const char* P);
		bool updatePost(const char* Post);
		bool searchPost(const char* p);
		void setPost(const char* p);
		const char* getPost()const;
		virtual std::ostream& write(std::ostream& os)const;
		virtual std::istream& read(std::istream& is);
		friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
		friend std::istream& operator>>(std::istream& is, Employee& emp);
		virtual void display()const;
		~Employee();
	};
}

#endif // !DSA_EMPLOYEE_H

