// 普通员工
#ifndef __EMPLOYEE__
#define __EMPLOYEE__
#include <iostream>
#include "worker.h"
#include "worker.cpp"

class Employee: public Worker
{
public:
Employee(const int&, const char*, const int&);
Employee(const Employee&);
Employee& operator=(const Employee&);
virtual void showInfo() const;
virtual const char* getDeptName() const;

private:
};


#endif