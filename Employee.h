#pragma once
#include <iostream>
using namespace std;
class Employee
{
public:
	string employeeName;
	int employeeId;
	int empDepartmentNumber;
	void readEmployeeData(Employee employee[]);
};
