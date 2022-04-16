#include "Menu.h"

Menu::Menu()
{
	out = true;
	choice = 0;
}

int Menu::firstMenu()
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
	while (flag)
	{
		cout << "Enter Manager password : ";
		cin >> pass;
		if (manager.managerPw == pass)
		{
			cout << " \n\n-------------------- Login successfully welcome back BOSS! --------------------\n\n";
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
	int userInControl = -1; // To know which employee are currently logged in
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
				out = false;
				break;
			}
			else if (answer == 'n')
			{
				flag = false;
				out = true;
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

int Menu::ManagerPageMenu()
{
	int choice;
	while (true)
	{
		cout << "[1] to add new Task\n[2] to display tasks\n[3] to edit existing task\n";
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
	return choice;
}
