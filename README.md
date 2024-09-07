# Restaurant Management System

## Overview

This project is a Restaurant Management System developed in C++ using data structures and algorithms (DSA) such as LinkedLists and Dynamic Arrays. The system manages orders, customers, dishes, and employees.

## Project Structure

- **`headerfiles/`**: Contains header files for the project.

  - `order.h`: Header file for order-related functionalities.
  - `customer.h`: Header file for customer-related functionalities.
  - `dish.h`: Header file for dish-related functionalities.
  - `employee.h`: Header file for employee-related functionalities.

- **`sources/`**: Contains source files with the implementation of the functionalities.

  - Various `.cpp` files for the core functionality of the system.

- **`resources/`**: Contains CSV files used for data storage.
  - `orders.csv`: Data for orders.
  - `dishes.csv`: Data for dishes.
  - `employee.csv`: Data for employees.

## Setting Up the Project in Visual Studio

### 1. Create a New Project

1. Open Visual Studio.
2. Go to `File` > `New` > `Project`.
3. Choose `Empty Project` under `C++`, then click `Next`.
4. Enter a project name and location, then click `Create`.

### 2. Add Header Files

1. In the Solution Explorer, right-click on `Header Files`.
2. Select `Add` > `Existing Item`.
3. Navigate to the `headerfiles` directory.
4. Select all `.h` files (`order.h`, `customer.h`, `dish.h`, `employee.h`), and click `Add`.

### 3. Add Source Files

1. In the Solution Explorer, right-click on `Source Files`.
2. Select `Add` > `Existing Item`.
3. Navigate to the `sources` directory.
4. Select all `.cpp` files, and click `Add`.

### 4. Add CSV Files

1. In the Solution Explorer, right-click on the project name.
2. Select `Add` > `New Folder`, and name it `resources`.
3. Right-click on the `resources` folder.
4. Select `Add` > `Existing Item`.
5. Navigate to the `resources` directory.
6. Select all `.csv` files (`orders.csv`, `dishes.csv`, `employee.csv`), and click `Add`.

### 5. Configure Project Properties

1. Right-click on the project in the Solution Explorer and select `Properties`.
2. Under `Configuration Properties` > `VC++ Directories`, ensure that:
   - `Include Directories` includes the path to `headerfiles` folder.
   - `Library Directories` includes the path to `sources` folder, if necessary.

### 6. Build and Run the Project

1. Click on `Build` > `Build Solution` to compile the project.
2. Click on `Debug` > `Start Debugging` to run the project.

## Usage

- **Functionality**: The system provides functionality for managing orders, customers, dishes, and employees using linked lists and dynamic arrays.
- **Data Management**: Data is loaded from and saved to the CSV files located in the `resources` folder.
