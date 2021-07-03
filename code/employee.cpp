#pragma once
#include <iostream>
#include "employee.h"

inline
Employee::Employee(const int& id, const char* name, const int& dsp):
Worker(id, name, dsp){}

inline
Employee::Employee(const Employee& another):
Worker(another){}

inline Employee& 
Employee::operator=(const Employee& another)
{
    if(this==&another) return *this;
    Worker::operator=(another);
}

inline void 
Employee::showInfo() const
{
    std::cout << "职工编号：" << getID()
        << "\t职工姓名：" << getName()
        << "\t岗位：" << getDeptName()
        << "\t岗位职责：完成经理交给的任务" << std::endl;
}   

inline const char* 
Employee::getDeptName() const
{
    return "普通职工";
}
