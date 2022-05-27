#include "Menu.h"
int userInControl = -1; // To know which employee are currently logged in
Menu::Menu()
{
	out1 = true;
	out2 = false;
	choice = 0;
	task.defaultTasks();
}

int Menu::mainMenu()
{
	while (true)
	{
		cout << "Press [1] for Manager page or [2] for employee page\n";
		cout << "Choice : ";
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			break;
		}
		else
		{
			cout << "\nInvalid choice, Please try again...\n\n";
		}
	}
	return choice;
}

bool Menu::ManagerPassword(Manager manager)
{
	int pass; 
	char c; // user choice
	bool flag = true;
	while (flag == true)
	{
		cout << "Enter Manager password : ";
		cin >> pass;
		if (manager.managerPw == pass)
		{
			cout << " \n\n-------------------- Login successfully welcome back BOSS! --------------------\n\n";
			flag = true;
			break;
		}
		else
		{
			cout << "\nWrong password, Do you want to try again ? [Y/N]\n\n";
			while (true)
			{
				cout << "Your answer [Y/N] : ";
				cin >> c;
				c = tolower(c);
				if (c == 'y')
				{
					cout << endl;
					break;
				}
				else if (c == 'n')
				{
					flag = false;
					break;
				}
				else
				{
					cout << "\nInvalid choice, Please try again...\n\n";
				}
			}
		}
	}
	return flag;
}

int Menu::employeeLogin(Employee employee[])
{
	int id;
	char answer;
	bool flag = true;
	while (flag)
	{
		cout << "Enter your ID : ";
		cin >> id;
		for (int i = 0; i < 5; i++)
		{
			if (employee[i].employeeId == id)
			{
				cout << " \n\n-------------------- Login successfully, Welecome " << employee[i].employeeName << " --------------------\n\n";
				userInControl = i;
				flag = false;
				out1 = false;
				break;
			}
		}
		if (flag == true)
		{
			cout << "\nWrong id...\n\n";
			cout << "Do you want to re-enter your id [Y/N]\n\n";
		}
		while (flag)
		{
			cout << "Your answer [Y/N] : ";
			cin >> answer;
			answer = tolower(answer);
			if (answer == 'y')
			{
				cout << endl;
				out1 = false; // out from employee login menu
				break;
			}
			else if (answer == 'n')
			{
				flag = false;
				out1 = true;  // out from employee login menu
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
	}
	return userInControl;
}

void Menu::ManagerPageMenu()
{
	int choice;
	bool flag = true;
	while (flag == true)
	{
		while (true)
		{
			cout << "[1] to add new Task\n[2] to display tasks\n[3] to display finished tasks\n[4] to edit existing task\n[5] to delete task\n";
			cout << "Your choice : ";
			cin >> choice;
			cout << endl;
			if (choice > 0 && choice <=5)
			{
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
		switch (choice)
		{
		case 1:
			task.readTasks();
			break;
		case 2:
			task.displayTasks();
			break;
		case 3:
			task.displayDoneTasks();
			break;
		case 4:
			task.editTasks();
			break;
		case 5:
			task.deleteTask();
			break;
		}
		cout << "\n\nIf you want to make another operation please\n";
		cout << "Press [1] to go to Manager menu or [*] to go to Main menu\n\n";
		string c;
		while (true)
		{
			cout << "Your choice : ";
			cin >> c;
			if (c == "1")
			{
				flag = true;
				break;
			}
			else if (c == "*")
			{
				flag = false;
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
	}
}

void Menu::employeePageMenu(Employee employee[])
{
	int choice;
	bool flag = true;
	task.reminderTask(employee[userInControl].employeeName);
	while (flag == true)
	{
		while (true)
		{
			cout << "[1] to display your tasks\n[2] to remove finished task\n[3] postpone a task to another day\n";
			cout << "Your choice : ";
			cin >> choice;
			cout << endl;
			if (choice == 1 || choice == 2 || choice == 3)
			{
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
		switch (choice)
		{
		case 1:
			// Display Employee Tasks
			task.displayEmployeeTasks(employee[userInControl].employeeName);
			break;
		case 2:
			// To remove finished task
			task.deleteDoneTasks(employee[userInControl].employeeName);
			break;
		case 3:
			// Postpone a task to another day
			task.postponeTask(employee[userInControl].employeeName);
			break;
		}
		cout << "\n\nIf you want to make another operation please\n";
		cout << "Press [1] to go to Employee menu or [*] to go to Main menu\n\n";
		string c;
		while (true)
		{
			cout << "Your choice : ";
			cin >> c;
			if (c == "1")
			{
				flag = true;
				break;
			}
			else if (c == "*")
			{
				flag = false;
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
	}
}
