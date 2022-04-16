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
	int count;
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		count = 0;
		head = 0;
		tail = 0;
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
		else if (newNode->value.priorityValues >= temp->value.priorityValues)
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
	void displayData()
	{
		cout << "\n\n" << Length() << "\n\n";
		int x = Length();
		int i = 1;
		Node* temp = head;
		while (x > 0)
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
			x--;
		}
	}
	void deleteAt()
	{

	}
};

LinkedList myList;

//default task data
void Tasks::defaultTasks()
{
	Tasks task[11];
	task[0].taskName = "First task";
	task[0].taskDescription = "1st";
	task[0].assigningDate = "7/2/2022";
	task[0].endingDate = "10/2/2022";
	task[0].assignedTo = "Tarek";
	task[0].priorityValues = 7;
	myList.insert(task[0]);

	task[1].taskName = "Second task";
	task[1].taskDescription = "2nd";
	task[1].assigningDate = "12/3/2022";
	task[1].endingDate = "17/3/2022";
	task[1].assignedTo = "Bibo";
	task[1].priorityValues = 9;
	myList.insert(task[1]);

	task[2].taskName = "Third task";
	task[2].taskDescription = "3rd";
	task[2].assigningDate = "3/4/2022";
	task[2].endingDate = "10/4/2022";
	task[2].assignedTo = "Mazen";
	task[2].priorityValues = 6;
	myList.insert(task[2]);

	task[3].taskName = "Fourth task";
	task[3].taskDescription = "4th";
	task[3].assigningDate = "8/6/2022";
	task[3].endingDate = "15/6/2022";
	task[3].assignedTo = "Tarek";
	task[3].priorityValues = 2;
	myList.insert(task[3]);

	task[4].taskName = "Fifth task";
	task[4].taskDescription = "5th";
	task[4].assigningDate = "7/9/2022";
	task[4].endingDate = "13/9/2022";
	task[4].assignedTo = "Mostafa";
	task[4].priorityValues = 4;
	myList.insert(task[4]);

	task[5].taskName = "Sixth task";
	task[5].taskDescription = "6th";
	task[5].assigningDate = "6/11/2022";
	task[5].endingDate = "12/11/2022";
	task[5].assignedTo = "Bibo";
	task[5].priorityValues = 3;
	myList.insert(task[5]);

	task[6].taskName = "Seventh task";
	task[6].taskDescription = "7th";
	task[6].assigningDate = "25/4/2022";
	task[6].endingDate = "29/4/2022";
	task[6].assignedTo = "Mazen";
	task[6].priorityValues = 7;
	myList.insert(task[6]);

	task[7].taskName = "Eighth task";
	task[7].taskDescription = "8th";
	task[7].assigningDate = "18/7/2022";
	task[7].endingDate = "25/7/2022";
	task[7].assignedTo = "Ahmed";
	task[7].priorityValues = 5;
	myList.insert(task[7]);

	task[8].taskName = "Ninth task";
	task[8].taskDescription = "9th";
	task[8].assigningDate = "14/8/2022";
	task[8].endingDate = "20/8/2022";
	task[8].assignedTo = "Osha";
	task[8].priorityValues = 9;
	myList.insert(task[8]);

	task[9].taskName = "Tenth task";
	task[9].taskDescription = "10th";
	task[9].assigningDate = "30/10/2022";
	task[9].endingDate = "5/11/2022";
	task[9].assignedTo = "Ahmed";
	task[9].priorityValues = 7;
	myList.insert(task[9]);

	task[10].taskName = "Eleventh task";
	task[10].taskDescription = "11th";
	task[10].assigningDate = "9/1/2022";
	task[10].endingDate = "16/1/2022";
	task[10].assignedTo = "Osha";
	task[10].priorityValues = 1;
	myList.insert(task[10]);
}

void Tasks::readTasks()
{
	char choice;
	
	cout << "\n\nDo you want to add another task ? [Y/N]\n";
	while (true)
	{
		cout << "Your answer [Y/N] : ";
		cin >> choice;
		choice = tolower(choice);
		if (choice == 'y')
		{
			cout << endl;
			readTasks();
			break;
		}
		else if (choice == 'n')
		{
			break;
		}
		else
		{
			cout << "\nInvalid choice, Please try again...\n\n";
		}
	}
}


void Tasks::displayTasks()
{
	myList.displayData();
}


Tasks::Tasks()
{
	priorityValues = 0;
}

