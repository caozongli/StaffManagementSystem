#pragma once
#include <iostream>
#include "boss.h"
using namespace std;

inline
Boss::Boss(const int& id, const char* name, const int& dsp):
Worker(id, name, dsp){}

inline
Boss::Boss(const Boss& another):
Worker(another){}

inline Boss& 
Boss::operator=(const Boss& another)
{
    if(this==&another) return *this;
    Worker::operator=(another);
}

inline void 
Boss::showInfo() const
{
    cout << "职工编号：" << getID()
        << "\t职工姓名：" << getName()
        << "\t岗位：" << getDeptName()
        << "\t岗位职责：管理公司所有事物" << endl;
}   

inline const char* 
Boss::getDeptName() const
{
    return "公司老板";
}
