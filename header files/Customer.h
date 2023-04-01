#ifndef DSA_CUSTOMER_H
#define DSA_CUSTOMER_H
#include<iostream>
namespace dsa {
	class User {
	protected:
		char* name;
		char* address;
		unsigned long phone;
		bool Csv;
	public:
		User();
		User(const User& us);
		bool isEmpty()const;
		void setEmpty();
		virtual void add(const char*Name, const char* Address,unsigned long no);
		bool searchName(const char* Name);
		bool searchPh(unsigned long n);
		bool searchAdd(const char* ad);
		bool updateName(const char* newname);
		bool updateAdd(const char* Add);
		bool updatePh(const unsigned long no);
		 bool operator==(User&);
		User& operator=(const User& us);
		void setCsv(bool flag);
		bool isCsv()const;
		unsigned long getNumber()const;
		const char* getName()const;
		const char* getAdd()const;
		void setName(const char* N);
		void setPhone(unsigned long n);
		void setAdd(const char* add);
		virtual std::ostream& write(std::ostream& os)const;
		virtual std::istream& read(std::istream& is);
		virtual void display()const;
		~User();
	};

	class Customer :public User {
	public:
		Customer();
		Customer(const Customer& cust);
		operator bool()const;
		virtual Customer& operator=(const Customer&);
		virtual std::ostream& write(std::ostream& os)const;
		virtual std::istream& read(std::istream& is);

	};

}
#endif // !DSA_CUSTOMER_H

