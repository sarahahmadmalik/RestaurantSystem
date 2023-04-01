#ifndef DSA_RESTAURANT_H
#define DSA_RESTAURANT_H
#include "Order.h"
namespace dsa {
	
	class Restaurant {
	private:
		char* dishFile;
		char* empFile;
		char* orderFile;
		order* Head;
		order* tail;
		Employee* emp;
		Dish* dishMenu;
		int totalOrders;
		int total_emp;
		bool isCsv;

	public:
		Restaurant();
		Restaurant(const char* file1, const char* file2, const char* file3);
		bool isEmpty()const;
		void setEmpty();
		int run();
		void mainMenu()const;
		void admin();
		void editEmployee();
		void searchEmployee();
		void addEmployee();
		void deleteEmployee();
		bool login();
		void customer();
		void editDish();
		void createOrder(std::istream& is);
		void editOrder();
		void addDish();
		void addOrder();
		void sortOrders();
		void deleteOrder();
		void printOrder()const;
		void printList(std::ostream& os)const;
		void load();
		bool save();
		bool closeRestaurant();
		~Restaurant();
	};



}


#endif // !DSA_RESTAURANT_H

