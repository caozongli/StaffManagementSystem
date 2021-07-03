#pragma once
#include <iostream>
#include "worker.h"
#include <string.h>
inline
Worker::Worker(const int& id=0, const char* name="", const int& deptname=0):
m_Id(id), m_DeptId(deptname)
{
    m_Name = new char[strlen(name)+1];
    strcpy(m_Name, name);
}

inline
Worker::Worker(const Worker& another)
{
    delete []m_Name;
    m_Name = new char[strlen(another.m_Name+1)];
    strcpy(m_Name, another.m_Name);
    m_Id = another.m_Id;
    m_DeptId = another.m_DeptId;
}

inline Worker&
Worker::operator=(const Worker& another)
{
    if(this==&another)
        return *this;
    delete []m_Name;
    m_Name = new char[strlen(another.m_Name)+1];
    strcpy(m_Name, another.m_Name);
    m_Id = another.m_Id;
    m_DeptId = another.m_DeptId;
    return *this;
}

inline int 
Worker::getID() const
{
    return m_Id;
}

inline int 
Worker::getDeptID() const
{
    return m_DeptId;
}

inline char* 
Worker::getName() const
{
    return m_Name;
}

inline 
Worker::~Worker()
{
    delete []m_Name;
}