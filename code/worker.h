#ifndef __WORKER__
#define __WORKER__
#include <iostream>
//职工抽象类
class Worker
{
public:
    Worker(const int&, const char*, const int&);
    Worker(const Worker&);
    Worker& operator=(const Worker&);
    int getID() const;
    int getDeptID()const;
    char* getName() const; 

    virtual void showInfo() const = 0; // 显示个人信息
    virtual const char* getDeptName() const = 0; // 获取岗位信息
    virtual ~Worker();

private:
    // 职工编号
    int m_Id;
    // 职工姓名
    char* m_Name;
    // 部门编号
    int m_DeptId;
};

#endif