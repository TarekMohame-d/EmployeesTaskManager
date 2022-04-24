#include "Menu.h"
#include <windows.h>
void program()
{
	Manager manager;
	Employee employee[5];
	employee->employeeData(employee);
	Menu menu;
	int userInControl; // To catch employee number in the array of employees that log in
	while (true)
	{
		while (true)
		{
			cout << "\n\n\n\t\t\t\t ******** Welcome to Employees Task Manager system ********\t\t\t\n\n\n\n";
			int choice = menu.mainMenu();
			if (choice == 1) // Manager page
			{
				if (menu.ManagerPassword(manager))
				{
					menu.ManagerPageMenu();
				}
				else continue;
			}
			else // Employee page
			{
				userInControl = menu.employeeLogin(employee);
				if (menu.out1 == true)
				{
					continue;
				}
				else
				{
					menu.employeePageMenu(employee);
				}
			}
		}
	}
}

int main()
{
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
	program();

	return 0;
}