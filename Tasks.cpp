#include "Tasks.h"
class Node
{
public:
	Node* next;
	Tasks value;
	Node()
	{
		next = 0;
	}
	Node(Tasks task)
	{
		value = task;
		next = 0;
	}
};

class LinkedList
{
public:
	int count;
	Node* head;
	Node* tail;

	LinkedList()
	{
		count = 0;
		head = 0;
		tail = 0;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	int Length()
	{
		return count;
	}

	void insert(Tasks task)
	{
		Node* newNode = new Node(task);
		Node* temp = head;
		if (count == 0)
		{
			head = tail = newNode;
		}
		else if (newNode->value.priorityValues >= head->value.priorityValues)
		{
			newNode->next = head;
			head = newNode;
		}
		else if (newNode->value.priorityValues <= tail->value.priorityValues)
		{
			tail->next = newNode;
			tail = newNode;
			newNode->next = 0;
		}
		else
		{
			while (temp->next != 0)
			{
				if (newNode->value.priorityValues <= temp->value.priorityValues && newNode->value.priorityValues >= temp->next->value.priorityValues)
				{
					newNode->next = temp->next;
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}
		}
		count++;
	}

	void deleteAt(int pos)
	{
		Node* temp = head;
		if (pos == 0) // if the deleted node was the first node "Head"
		{
			head = head->next;
			delete temp;
			count--;
		}
		else
		{
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			if (pos == (count-1)) // if the deleted node was the last node "Tail"
			{
				Node* ptr = tail;
				tail = temp;
				tail->next = 0;
				delete ptr;
				count--;
			}
			else
			{
				Node* d = temp->next;  // Point to the node that will be deleted
				temp->next = d->next;
				delete d;
				count--;
			}
		}
	}
};

LinkedList tasksList;
LinkedList doneTasksList;

//default task data
void Tasks::defaultTasks()
{
	Tasks task[15];
	task[0].taskName = "Task1";
	task[0].taskDescription = "1st";
	task[0].assiDate.assigningDay = 27;
	task[0].assiDate.assigningMonth = 5;
	task[0].endDate.endingDay = 1;
	task[0].endDate.endingMonth = 6;
	task[0].assignedTo = "Tarek";
	task[0].priorityValues = 7;
	tasksList.insert(task[0]);

	task[1].taskName = "Task2";
	task[1].taskDescription = "2nd";
	task[1].assiDate.assigningDay = 27;
	task[1].assiDate.assigningMonth = 5;
	task[1].endDate.endingDay = 2;
	task[1].endDate.endingMonth = 6;
	task[1].assignedTo = "Bibo";
	task[1].priorityValues = 9;
	tasksList.insert(task[1]);

	task[2].taskName = "Task3";
	task[2].taskDescription = "3rd";
	task[2].assiDate.assigningDay = 30;
	task[2].assiDate.assigningMonth = 5;
	task[2].endDate.endingDay = 4;
	task[2].endDate.endingMonth = 6;
	task[2].assignedTo = "Mazen";
	task[2].priorityValues = 6;
	tasksList.insert(task[2]);

	task[3].taskName = "Task4";
	task[3].taskDescription = "4th";
	task[3].assiDate.assigningDay = 26;
	task[3].assiDate.assigningMonth = 5;
	task[3].endDate.endingDay = 2;
	task[3].endDate.endingMonth = 6;
	task[3].assignedTo = "Tarek";
	task[3].priorityValues = 2;
	tasksList.insert(task[3]);

	task[4].taskName = "Task5";
	task[4].taskDescription = "5th";
	task[4].assiDate.assigningDay = 29;
	task[4].assiDate.assigningMonth = 5;
	task[4].endDate.endingDay = 4;
	task[4].endDate.endingMonth = 6;
	task[4].assignedTo = "Bibo";
	task[4].priorityValues = 4;
	tasksList.insert(task[4]);

	task[5].taskName = "Task6";
	task[5].taskDescription = "6th";
	task[5].assiDate.assigningDay = 28;
	task[5].assiDate.assigningMonth = 5;
	task[5].endDate.endingDay = 2;
	task[5].endDate.endingMonth = 6;
	task[5].assignedTo = "Bibo";
	task[5].priorityValues = 6;
	tasksList.insert(task[5]);

	task[6].taskName = "Task7";
	task[6].taskDescription = "7th";
	task[6].assiDate.assigningDay = 24;
	task[6].assiDate.assigningMonth = 5;
	task[6].endDate.endingDay = 30;
	task[6].endDate.endingMonth = 5;
	task[6].assignedTo = "Mazen";
	task[6].priorityValues = 8;
	tasksList.insert(task[6]);

	task[7].taskName = "Task8";
	task[7].taskDescription = "8th";
	task[7].assiDate.assigningDay = 25;
	task[7].assiDate.assigningMonth = 5;
	task[7].endDate.endingDay = 6;
	task[7].endDate.endingMonth = 6;
	task[7].assignedTo = "Tarek";
	task[7].priorityValues = 5;
	tasksList.insert(task[7]);

	task[8].taskName = "Task9";
	task[8].taskDescription = "9th";
	task[8].assiDate.assigningDay = 26;
	task[8].assiDate.assigningMonth = 5;
	task[8].endDate.endingDay = 31;
	task[8].endDate.endingMonth = 5;
	task[8].assignedTo = "Osha";
	task[8].priorityValues = 9;
	tasksList.insert(task[8]);

	task[9].taskName = "Task10";
	task[9].taskDescription = "10th";
	task[9].assiDate.assigningDay = 27;
	task[9].assiDate.assigningMonth = 5;
	task[9].endDate.endingDay = 3;
	task[9].endDate.endingMonth = 6;
	task[9].assignedTo = "Osha";
	task[9].priorityValues = 7;
	tasksList.insert(task[9]);

	task[10].taskName = "Task11";
	task[10].taskDescription = "11th";
	task[10].assiDate.assigningDay = 28;
	task[10].assiDate.assigningMonth = 5;
	task[10].endDate.endingDay = 5;
	task[10].endDate.endingMonth = 6;
	task[10].assignedTo = "Mazen";
	task[10].priorityValues = 1;
	tasksList.insert(task[10]);

	task[11].taskName = "Task12";
	task[11].taskDescription = "12th";
	task[11].assiDate.assigningDay = 31;
	task[11].assiDate.assigningMonth = 5;
	task[11].endDate.endingDay = 7;
	task[11].endDate.endingMonth = 6;
	task[11].assignedTo = "Osha";
	task[11].priorityValues = 2;
	tasksList.insert(task[11]);

	task[12].taskName = "Task13";
	task[12].taskDescription = "13th";
	task[12].assiDate.assigningDay = 28;
	task[12].assiDate.assigningMonth = 5;
	task[12].endDate.endingDay = 5;
	task[12].endDate.endingMonth = 6;
	task[12].assignedTo = "Ahmed";
	task[12].priorityValues = 3;
	tasksList.insert(task[12]);

	task[13].taskName = "Task14";
	task[13].taskDescription = "14th";
	task[13].assiDate.assigningDay = 26;
	task[13].assiDate.assigningMonth = 5;
	task[13].endDate.endingDay = 1;
	task[13].endDate.endingMonth = 6;
	task[13].assignedTo = "Ahmed";
	task[13].priorityValues = 8;
	tasksList.insert(task[13]);

	task[14].taskName = "Task15";
	task[14].taskDescription = "15th";
	task[14].assiDate.assigningDay = 29;
	task[14].assiDate.assigningMonth = 5;
	task[14].endDate.endingDay = 4;
	task[14].endDate.endingMonth = 6;
	task[14].assignedTo = "Ahmed";
	task[14].priorityValues = 5;
	tasksList.insert(task[14]);
}

void Tasks::readTasks()
{
	bool flag = true; // To know if the user want to add another Task or not
	while (flag == true)
	{
		char choice;
		Tasks task;
		cout << "Enter task name : ";
		cin >> task.taskName;
		cout << "Enter task description : ";
		cin >> task.taskDescription;
		cout << "Enter the assigning date day : ";
		cin >> task.assiDate.assigningDay;
		cout << "Enter the assigning date month : ";
		cin >> task.assiDate.assigningMonth;
		cout << "Enter the ending date day : ";
		cin >> task.endDate.endingDay;
		cout << "Enter the ending date month : ";
		cin >> task.endDate.endingMonth;
		cout << "Task assigned to : ";
		cin >> task.assignedTo;
		while (true)
		{
			cout << "Priority value from [ 1 - 9 ] : ";
			cin >> task.priorityValues;
			if (task.priorityValues > 0 && task.priorityValues < 10)
			{
				break;
			}
			else
			{
				cout << "\n\nPriority value must be greater than 0 and less than 10!\n\n";
			}
		}
		tasksList.insert(task);
		cout << "\n\nDo you want to add another task ? [Y/N]\n";
		while (true)
		{
			cout << "Your answer [Y/N] : ";
			cin >> choice;
			choice = tolower(choice);
			if (choice == 'y')
			{
				cout << endl;
				break;
			}
			else if (choice == 'n')
			{
				flag = false; // out from the readTasks function
				break;
			}
			else
			{
				cout << "\nInvalid choice, Please try again...\n\n";
			}
		}
	}
}


void Tasks::displayTasks()
{
	if (tasksList.isEmpty())
	{
		cout << "\n\nThere is no tasks yet...\n\n";
	}
	else
	{
		cout << "\n\nNumber of tasks : ";
		cout << tasksList.Length() << "\n\n";
		int i = 1;
		Node* temp = tasksList.head;
		while (temp != 0)
		{
			cout << "Task number [" << i << "] --->>\n\n";
			cout << "Task name : ";
			cout << temp->value.taskName << endl;
			cout << "Task description : ";
			cout << temp->value.taskDescription << endl;
			cout << "Assigning date day : ";
			cout << temp->value.assiDate.assigningDay << endl;
			cout << "Assigning date month : ";
			cout << temp->value.assiDate.assigningMonth << endl;
			cout << "Ending date day : ";
			cout << temp->value.endDate.endingDay << endl;
			cout << "Ending date month : ";
			cout << temp->value.endDate.endingMonth << endl;
			cout << "Task assigned to : ";
			cout << temp->value.assignedTo << endl;
			cout << "Priority values : ";
			cout << temp->value.priorityValues << endl;
			cout << "\n\n##############################################################\n\n";
			temp = temp->next;
			i++;
		}
	}
}

void Tasks::displayDoneTasks()
{
	if (doneTasksList.isEmpty())
	{
		cout << "\n\nThere is no finished tasks yet...\n\n";
	}
	else
	{
		cout << "\n\nNumber of done tasks : ";
		cout << doneTasksList.Length() << "\n\n";
		int i = 1;
		Node* temp = doneTasksList.head;
		while (temp != 0)
		{
			cout << "Task number [" << i << "] --->>\n\n";
			cout << "Task name : ";
			cout << temp->value.taskName << endl;
			cout << "Task description : ";
			cout << temp->value.taskDescription << endl;
			cout << "Assigning date day : ";
			cout << temp->value.assiDate.assigningDay << endl;
			cout << "Assigning date month : ";
			cout << temp->value.assiDate.assigningMonth << endl;
			cout << "Ending date day : ";
			cout << temp->value.endDate.endingDay << endl;
			cout << "Ending date month : ";
			cout << temp->value.endDate.endingMonth << endl;
			cout << "Task assigned to : ";
			cout << temp->value.assignedTo << endl;
			cout << "Priority values : ";
			cout << temp->value.priorityValues << endl;
			cout << "\n\n##############################################################\n\n";
			temp = temp->next;
			i++;
		}
	}
}

void Tasks::deleteTask()
{
	string name;
	int pos = 0;
	bool found = false;
	Node* temp = tasksList.head;

	cout << "Enter task name you want to delete : ";
	cin >> name;
	while (temp != 0)
	{
		if (name != temp->value.taskName)
		{
			pos++;
			temp = temp->next;
		}
		else
		{
			found = true;
			break;
		}
	}
	if (found == false)
	{
		cout << "Not found\n";
	}
	else
	{
		tasksList.deleteAt(pos);
		cout << "\n\nTask deleted successfully\n\n";
	}
}

void Tasks::deleteDoneTasks(string name)
{
	string taskName;
	int pos = 0;
	bool found = false;
	Node* temp = tasksList.head;

	cout << "Enter task name you want to delete : ";
	cin >> taskName;
	while (temp != 0)
	{
		if (taskName != temp->value.taskName)
		{
			pos++;
			temp = temp->next;
		}
		else
		{
			if (temp->value.assignedTo == name)
			{
				found = true;
				break;
			}
			else
			{
				pos++;
				temp = temp->next;
				continue;
			}
		}
	}
	if (found == false)
	{
		cout << "\nThere is no task with this name...";
	}
	else
	{
		doneTasksList.insert(temp->value);
		tasksList.deleteAt(pos);
		cout << "\n\nTask deleted successfully\n\n";
	}
}

void Tasks::displayEmployeeTasks(string name)
{
	if (tasksList.isEmpty())
	{
		cout << "\n\nThere is no task...\n\n";
	}
	else
	{
		int counter = 0;
		int i = 1;
		Node* temp = tasksList.head;
		while (temp != 0)
		{
			if (name == temp->value.assignedTo)
			{
				cout << "Task number [" << i << "] --->>\n\n";
				cout << "Task name : ";
				cout << temp->value.taskName << endl;
				cout << "Task description : ";
				cout << temp->value.taskDescription << endl;
				cout << "Assigning date day : ";
				cout << temp->value.assiDate.assigningDay << endl;
				cout << "Assigning date month : ";
				cout << temp->value.assiDate.assigningMonth << endl;
				cout << "Ending date day : ";
				cout << temp->value.endDate.endingDay << endl;
				cout << "Ending date month : ";
				cout << temp->value.endDate.endingMonth << endl;
				cout << "Task assigned to : ";
				cout << temp->value.assignedTo << endl;
				cout << "Priority values : ";
				cout << temp->value.priorityValues << endl;
				cout << "\n\n##############################################################\n\n";
				i++;
				counter++;
			}
			temp = temp->next;
		}
		if (counter == 0)
		{
			cout << "\n\nThere are no tasks to display, Keep doing that good work\n";
			cout << "Good job\n";
		}
	}
}

void Tasks::reminderTask(string name)
{
	time_t now = time(0);
	#pragma warning(suppress : 4996)
	tm* date_time = localtime(&now);
	if (tasksList.isEmpty())
	{
		return;
	}
	else
	{
		cout << "\nReminder with the next task to be done : \n\n";
		Node* temp = tasksList.head;
		int tempDate;
		int result;
		bool found = false;
		while (temp != 0)
		{
			tempDate = 0;
			result = 0;
			if (name == temp->value.assignedTo)
			{
				if (temp->value.endDate.endingMonth > date_time->tm_mon+1)
				{
					tempDate = temp->value.endDate.endingDay + 30;
					result = tempDate - date_time->tm_mday;
					if (result >= 0 && result <= 2)
					{
						cout << "Task name : ";
						cout << temp->value.taskName << endl;
						cout << "Task description : ";
						cout << temp->value.taskDescription << endl;
						cout << "Assigning date day : ";
						cout << temp->value.assiDate.assigningDay << endl;
						cout << "Assigning date month : ";
						cout << temp->value.assiDate.assigningMonth << endl;
						cout << "Ending date day : ";
						cout << temp->value.endDate.endingDay << endl;
						cout << "Ending date month : ";
						cout << temp->value.endDate.endingMonth << endl;
						cout << "Task assigned to : ";
						cout << temp->value.assignedTo << endl;
						cout << "Priority values : ";
						cout << temp->value.priorityValues << endl << endl;
						found = true;
						break;
					}
				}
				else if(temp->value.endDate.endingMonth == date_time->tm_mon + 1)
				{
					result = temp->value.endDate.endingDay - date_time->tm_mday;
					if (result >=0 && result <= 2 )
					{
						cout << "Task name : ";
						cout << temp->value.taskName << endl;
						cout << "Task description : ";
						cout << temp->value.taskDescription << endl;
						cout << "Assigning date day : ";
						cout << temp->value.assiDate.assigningDay << endl;
						cout << "Assigning date month : ";
						cout << temp->value.assiDate.assigningMonth << endl;
						cout << "Ending date day : ";
						cout << temp->value.endDate.endingDay << endl;
						cout << "Ending date month : ";
						cout << temp->value.endDate.endingMonth << endl;
						cout << "Task assigned to : ";
						cout << temp->value.assignedTo << endl;
						cout << "Priority values : ";
						cout << temp->value.priorityValues << endl << endl;
						found = true;
						break;
					}
				}
			}
			temp = temp->next;
		}
		if (found == false)
		{
			cout << "There are no tasks its ending date reached 2 days before the deadline.\n\n";
		}
	}
}

void Tasks::postponeTask(string name)
{
	string taskName;
	int newDateDay;
	int newDateMonth;
	bool found = false;
	Node* temp = tasksList.head;
	cout << "\nEnter the task name you want to postpone : ";
	cin >> taskName;
	while (temp !=0 && found == false)
	{
		if (temp->value.assignedTo == name && temp->value.taskName == taskName)
		{
			found = true;
			while (true)
			{
				cout << "\n\nThe new date 'Must be before the task deadline!' : " << temp->value.endDate.endingDay << " / " << temp->value.endDate.endingMonth << " ";
				cout << "and after the task 'assigning data!' : " << temp->value.assiDate.assigningDay << " / " << temp->value.assiDate.assigningMonth << "\n\n";
				cout << "\nEnter the new date --> day : ";
				cin >> newDateDay;
				cout << "\nEnter the new Date --> Month : ";
				cin >> newDateMonth;
				if (temp->value.assiDate.assigningMonth == temp->value.endDate.endingMonth)
				{
					if (newDateMonth == temp->value.assiDate.assigningMonth)
					{
						if (newDateDay >= temp->value.assiDate.assigningDay && newDateDay <= temp->value.endDate.endingDay)
						{
							temp->value.assiDate.assigningDay = newDateDay;
							cout << "\n\nThe task postponed successfully...\n";
							break;
						}
					}
				}
				else if (temp->value.assiDate.assigningMonth < temp->value.endDate.endingMonth)
				{
					if (newDateMonth == temp->value.assiDate.assigningMonth)
					{
						if (newDateDay >= temp->value.assiDate.assigningDay && newDateDay <= 30)
						{
							temp->value.assiDate.assigningDay = newDateDay;
							temp->value.assiDate.assigningMonth = newDateMonth;
							cout << "\n\nThe task postponed successfully...\n";
							break;
						}
					}
					else if (newDateMonth == temp->value.endDate.endingMonth)
					{
						if (newDateDay <= temp->value.endDate.endingDay && newDateDay > 0)
						{
							temp->value.assiDate.assigningDay = newDateDay;
							temp->value.assiDate.assigningMonth = newDateMonth;
							cout << "\n\nThe task postponed successfully...\n";
							break;
						}
					}
				}
				else
				{
					cout << "\n\nPlease enter a date that Must be before the task deadline and after the task 'assigning data!'\n";
				}
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	if (found == false)
	{
		cout << "\nThere is no task with this name...\n";
	}
}

void Tasks::editTasks()
{
	string taskName;
	Node* ptr;
	bool found = false, flag = true;
	int choice;
	while (flag == true)
	{
		int pos = 0;
		ptr = tasksList.head;
		cout << "Enter the name of the task you want to edit : ";
		cin >> taskName;
		while (ptr != 0)
		{
			if (taskName != ptr->value.taskName)
			{
				pos++;
				ptr = ptr->next;
			}
			else
			{
				found = true;
				break;
			}
		}
		if (found == true)
		{
			tasksList.deleteAt(pos);
			Tasks task;
			cout << "\n\nEdit the task data ===>>\n\n";
			cout << "Enter task name : ";
			cin >> task.taskName;
			cout << "Enter task description : ";
			cin >> task.taskDescription;
			cout << "Enter the assigning date day : ";
			cin >> task.assiDate.assigningDay;
			cout << "Enter the assigning date month : ";
			cin >> task.assiDate.assigningMonth;
			cout << "Enter the ending date day : ";
			cin >> task.endDate.endingDay;
			cout << "Enter the ending date month : ";
			cin >> task.endDate.endingMonth;
			cout << "Task assigned to : ";
			cin >> task.assignedTo;
			while (true)
			{
				cout << "Priority value from [ 1 - 9 ] : ";
				cin >> task.priorityValues;
				if (task.priorityValues > 0 && task.priorityValues < 10)
				{
					break;
				}
				else
				{
					cout << "\n\nPriority value must be greater than 0 and less than 10!\n\n";
				}
			}
			tasksList.insert(task);
			flag = false;
		}
		else
		{
			cout << "\nThere is no task with this name...\n";
			cout << "Press [1] to try again or [2] to continue\n\n";
			while (true)
			{
				cout << "Your choice : ";
				cin >> choice;
				if (choice == 1)
				{
					break;
				}
				else if (choice == 2)
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
}


Tasks::Tasks()
{
	priorityValues = 0;
	assiDate.assigningDay = 0;
	assiDate.assigningMonth = 0;
	endDate.endingDay = 0;
	endDate.endingMonth = 0;
}

