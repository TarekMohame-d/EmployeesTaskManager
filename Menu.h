#pragma once
#include "Manager.h"
#include "Employee.h"
class Menu
{
public:
	int choice;
	bool out;
	Menu();
	int firstMenu();
	bool ManagerPassword(Manager manger);
	int employeeLogin(Employee employee[]);
	int ManagerPageMenu();
};