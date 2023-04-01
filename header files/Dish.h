#ifndef DSA_DISH_H
#define DSA_DISH_H
#include<iostream>
const unsigned int MAX_DISHES = 20;
namespace dsa {

	class DishItem {
	protected:
		char dish_name[31];
		char category[20];
		int dish_price;
		bool isValid;
		bool CsvMode;
	public:
		friend class Dish;
		friend class order;
		DishItem();
		DishItem(const char* name , int price);
		operator bool()const;
		bool isEmpty();
		void setEmpty();
		bool isCsvMode()const;
		void setCsvMode(bool flag);
		const char* getName()const;
		const char* getCateg()const;
		int getPrice()const;
		void display()const;
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		friend std::ostream& operator<<(std::ostream&, const DishItem&);
		friend std::istream& operator>>(std::istream& is, const DishItem& d);

	};

	class Dish {
	protected:
		char* filename;
		DishItem Dishes[MAX_DISHES];
		int dish_No;
		bool isValid;
		bool csv;
	public:
		friend class Restaurant;
		Dish();
		Dish(const char* file,int size);
		Dish(const Dish& d);
		void setCsv(bool);
		bool isCsv()const;
		bool isEmpty();
		operator bool();
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream&, const Dish&);
		bool operator ==(const char*dish);
		Dish& operator=(const Dish& d);
		int search(const char* dishname);
		bool add(const char* dish, const char* categ, int price);
		bool updatePrice(const char* name, int price);
		bool updateCateg(const char* name, const char* categ);
		bool updateName(const char* name, const char* newname);
		bool deleteDish(const char* name);
		int getDishNo()const;
		void setEmpty();
		~Dish();
	};

}


#endif // !DSA_DISH_H



