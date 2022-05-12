#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tasks
{
public:
	string taskName;
	string taskDescription;
	string assigningDate;
	string endingDate;
	string assignedTo;
	int priorityValues;
	void readTasks();
	void displayTasks(); // for manager
	void displayDoneTasks();
	void deleteTask();
	void deleteDoneTasks(string name);
	void displayEmployeeTasks(string name);
	void editTasks();
	void defaultTasks();
	Tasks();
};