#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct AssigningDate
{
	int assigningDay;
	int assigningMonth;
};
struct EndingDate
{
	int endingDay;
	int endingMonth;
};

class Tasks
{
public:
	string taskName;
	string taskDescription;
	string assignedTo;
	AssigningDate assiDate;
	EndingDate endDate;
	int priorityValues;
	void readTasks();
	void displayTasks(); // for manager
	void displayDoneTasks();
	void deleteTask();
	void deleteDoneTasks(string name);
	void displayEmployeeTasks(string name);
	void reminderTask(string name);
	void postponeTask(string name);
	void editTasks();
	void defaultTasks();
	Tasks();
};