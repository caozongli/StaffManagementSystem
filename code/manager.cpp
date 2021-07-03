#pragma once
#include <iostream>
#include "manager.h"

inline
Manager::Manager(const int& id, const char* name, const int& dsp):
Worker(id, name, dsp){}

inline
Manager::Manager(const Manager& another):
Worker(another){}

inline Manager& 
Manager::operator=(const Manager& another)
{
    if(this==&another) return *this;
    Worker::operator=(another);
}

inline void 
Manager::showInfo() const
{
    std::cout << "职工编号：" << getID()
        << "\t职工姓名：" << getName()
        << "\t岗位：" << getDeptName()
        << "\t岗位职责：完成老板任务，下发给普通员工" << std::endl;
}   

inline const char* 
Manager::getDeptName() const
{
    return "公司经理";
}
