#pragma once
#include <iostream>
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
	void displayTasks();
	void defaultTasks();
	Tasks();
};