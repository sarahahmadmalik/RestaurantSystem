#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iostream>
#include"Dish.h"
#include"Customer.h"
#include"Employee.h"
#include"Order.h"
#include"Restaurant.h"

using namespace std;
using namespace dsa;

int main() {
	Restaurant R("employees.csv", "dishes.csv", "Orders.csv");
	R.run();
	return 0;
	
}




