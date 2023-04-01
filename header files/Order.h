#ifndef DSA_ORDER_H
#define DSA_ORDER_H
#include<iostream>
#include"Dish.h"
#include"Customer.h"
#include"Employee.h"

namespace dsa {
	int getIntInRange(int min, int max);
	int fileSize(const char* file);
	int orders(const char* file);
	class order {
	public:
		char id[11];
		DishItem* dishes;
		Customer* cust;
		order* Next;
		int totalDishes;
		int bill;
		bool Csv;
		friend class Restaurant;
		order();
		/*order(int size,DishItem* dt, Customer* cu);*/
		bool isEmpty()const;
		void setEmpty();
		void setId(const char i[]);
		void setBill(int b);
		int getBill()const;
		const char* getId()const;
		bool isCsv()const;
		void setCsv(bool flag);
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		friend std::ostream& operator<<(std::ostream& os,const order& Order);
		friend std::istream& operator>>(std::istream& is, order& Order);
		~order();

	};

}
#endif // !DSA_ORDER_H

