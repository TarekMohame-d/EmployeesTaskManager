#include "Menu.h"
#include "Tasks.h"
#include <windows.h>
void program()
{
	Employee employee[5];
	Manager manager;
	Tasks task;
	task.defaultTasks();
	employee->readEmployeeData(employee);
	Menu menu;
	int userInControl; // To catch employee number in the array of employees that log in
	while (true)
	{
		while (true)
		{
			cout << "\n\n\n\t\t\t\t ******** Welcome to Employees Task Manager system ********\t\t\t\n\n\n\n";
			int choice = menu.firstMenu();
			if (choice == 1)
			{
				if (menu.ManagerPassword(manager))
				{
					int choice = menu.ManagerPageMenu();
					switch (choice)
					{
					case 1:
						task.readTasks();
						break;
					case 2:
						task.displayTasks();
						break;
					case 3:
						// edit existing task
						break;
					}
				}
				else continue;
			}
			else
			{
				userInControl = menu.employeeLogin(employee);
				if (menu.out == true)
				{
					continue;
				}
				else
				{
					// employee page
				}
			}
		}
	}
}

int main()
{
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 3);
	program();

	return 0;
}