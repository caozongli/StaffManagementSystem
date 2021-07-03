// 公司老板
#ifndef __BOSS__
#define __BOSS__
#include <iostream>
#include "worker.h"
#include "worker.cpp"

class Boss: public Worker
{
public:
Boss(const int&, const char*, const int&);
Boss(const Boss&);
Boss& operator=(const Boss&);
virtual void showInfo() const;
virtual const char* getDeptName() const;

private:
};


#endif