#include "Employee.h"

void Employee::employeeData(Employee employee[])
{
	employee[0].employeeName = "Tarek";
	employee[0].employeeId = 100;
	employee[0].empDepartmentNumber = 10;

	employee[1].employeeName = "Bibo";
	employee[1].employeeId = 101;
	employee[1].empDepartmentNumber = 20;

	employee[2].employeeName = "Osha";
	employee[2].employeeId = 102;
	employee[2].empDepartmentNumber = 30;

	employee[3].employeeName = "Mazen";
	employee[3].employeeId = 103;
	employee[3].empDepartmentNumber = 40;

	employee[4].employeeName = "Ahmed";
	employee[4].employeeId = 104;
	employee[4].empDepartmentNumber = 50;
}

Employee::Employee()
{
	employeeName = "";
	employeeId = 0;
	empDepartmentNumber = 0;
}
