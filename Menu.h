#pragma once
#include "Manager.h"
#include "Employee.h"
#include "Tasks.h"
class Menu
{
public:
	int choice;
	bool out1; // out from employee login page
	bool out2; // out from employee Function page
	Tasks task;
	Menu();
	int mainMenu();
	bool ManagerPassword(Manager manger);
	int employeeLogin(Employee employee[]);
	void ManagerPageMenu();
	void employeePageMenu(Employee employee[]);
};