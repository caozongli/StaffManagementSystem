// 经理
#ifndef __MANAGER__
#define __MANAGER__
#include <iostream>
#include "worker.h"
#include "worker.cpp"

class Manager: public Worker
{
public:
Manager(const int&, const char*, const int&);
Manager(const Manager&);
Manager& operator=(const Manager&);
virtual void showInfo() const;
virtual const char* getDeptName() const;

private:
};


#endif