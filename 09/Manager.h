#ifndef _MANAGE_H_
#define _MANAGE_H_
#include "Employee.h"
class Manager:virtual public Employee
{
public:
    Manager(const string&);
    Manager(const string& name,double salary,double bonus);
    void printInfo(void)const;
    
    double calSalary(void);
    
protected:
    void printExtra(void)const;
    double calMerit(void);
    double m_bonus;
private:
    
};
#endif
