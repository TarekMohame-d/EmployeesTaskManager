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
		for (int i = 0; i < pos-1; i++)
		{
			temp = temp->next;
		}
		Node* d = temp->next;  // Point to the node that will be deleted
		temp->next = d->next;
		delete d;
		count--;
	}
};

LinkedList tasksList;
LinkedList doneTasksList;

//default task data
void Tasks::defaultTasks()
{
	Tasks task[11];
	task[0].taskName = "Task1";
	task[0].taskDescription = "1st";
	task[0].assigningDate = "7/2/2022";
	task[0].endingDate = "10/2/2022";
	task[0].assignedTo = "Tarek";
	task[0].priorityValues = 7;
	tasksList.insert(task[0]);

	task[1].taskName = "Task2";
	task[1].taskDescription = "2nd";
	task[1].assigningDate = "12/3/2022";
	task[1].endingDate = "17/3/2022";
	task[1].assignedTo = "Bibo";
	task[1].priorityValues = 9;
	tasksList.insert(task[1]);

	task[2].taskName = "Task3";
	task[2].taskDescription = "3rd";
	task[2].assigningDate = "3/4/2022";
	task[2].endingDate = "10/4/2022";
	task[2].assignedTo = "Mazen";
	task[2].priorityValues = 6;
	tasksList.insert(task[2]);

	task[3].taskName = "Task4";
	task[3].taskDescription = "4th";
	task[3].assigningDate = "8/6/2022";
	task[3].endingDate = "15/6/2022";
	task[3].assignedTo = "Tarek";
	task[3].priorityValues = 2;
	tasksList.insert(task[3]);

	task[4].taskName = "Task5";
	task[4].taskDescription = "5th";
	task[4].assigningDate = "7/9/2022";
	task[4].endingDate = "13/9/2022";
	task[4].assignedTo = "Bibo";
	task[4].priorityValues = 4;
	tasksList.insert(task[4]);

	task[5].taskName = "Task6";
	task[5].taskDescription = "6th";
	task[5].assigningDate = "6/11/2022";
	task[5].endingDate = "12/11/2022";
	task[5].assignedTo = "Bibo";
	task[5].priorityValues = 3;
	tasksList.insert(task[5]);

	task[6].taskName = "Task7";
	task[6].taskDescription = "7th";
	task[6].assigningDate = "25/4/2022";
	task[6].endingDate = "29/4/2022";
	task[6].assignedTo = "Mazen";
	task[6].priorityValues = 8;
	tasksList.insert(task[6]);

	task[7].taskName = "Task8";
	task[7].taskDescription = "8th";
	task[7].assigningDate = "18/7/2022";
	task[7].endingDate = "25/7/2022";
	task[7].assignedTo = "Tarek";
	task[7].priorityValues = 5;
	tasksList.insert(task[7]);

	task[8].taskName = "Task9";
	task[8].taskDescription = "9th";
	task[8].assigningDate = "14/8/2022";
	task[8].endingDate = "20/8/2022";
	task[8].assignedTo = "Osha";
	task[8].priorityValues = 9;
	tasksList.insert(task[8]);

	task[9].taskName = "Task10";
	task[9].taskDescription = "10th";
	task[9].assigningDate = "30/10/2022";
	task[9].endingDate = "5/11/2022";
	task[9].assignedTo = "Osha";
	task[9].priorityValues = 7;
	tasksList.insert(task[9]);

	task[10].taskName = "Task11";
	task[10].taskDescription = "11th";
	task[10].assigningDate = "9/1/2022";
	task[10].endingDate = "16/1/2022";
	task[10].assignedTo = "Mazen";
	task[10].priorityValues = 1;
	tasksList.insert(task[10]);
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
		cout << "Enter the assigning date : ";
		cin >> task.assigningDate;
		cout << "Enter the ending date : ";
		cin >> task.endingDate;
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
		cout << "\n\n" << "Number of tasks : ";
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
			cout << "Assigning date : ";
			cout << temp->value.assigningDate << endl;
			cout << "Ending date : ";
			cout << temp->value.endingDate << endl;
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
		cout << "\n\n" << "Number of tasks : ";
		cout << doneTasksList.Length() << "\n\n";
		int i = 1;
		Node* temp = doneTasksList.head;
		while (temp != 0)
		{
			cout << "Task finished number [" << i << "] --->>\n\n";
			cout << "Task name : ";
			cout << temp->value.taskName << endl;
			cout << "Task description : ";
			cout << temp->value.taskDescription << endl;
			cout << "Assigning date : ";
			cout << temp->value.assigningDate << endl;
			cout << "Ending date : ";
			cout << temp->value.endingDate << endl;
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
	cin.ignore();
	getline(cin, name);
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
	cin.ignore();
	getline(cin, taskName);
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
				cout << "Assigning date : ";
				cout << temp->value.assigningDate << endl;
				cout << "Ending date : ";
				cout << temp->value.endingDate << endl;
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
		cin.ignore();
		getline(cin, taskName);
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
			cout << "Enter the assigning date : ";
			cin >> task.assigningDate;
			cout << "Enter the ending date : ";
			cin >> task.endingDate;
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
}

