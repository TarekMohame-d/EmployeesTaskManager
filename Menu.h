#pragma once
#include "Manager.h"
#include "Employee.h"
#include "Tasks.h"
class Menu
{
public:
	int choice;
	bool out;
	Tasks task;
	Menu();
	int mainMenu();
	bool ManagerPassword(Manager manger);
	int employeeLogin(Employee employee[]);
	void ManagerPageMenu();
};