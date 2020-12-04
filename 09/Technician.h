#ifndef _TECHNICIAN_H_
#define _TECHNICIAN_H_
#include "Employee.h"
class Technician:virtual public Employee
{
private:
    
public:
    Technician(const string&);
    Technician(const string& name,double salary,double allow);
    void printInfo(void)const;
    double calSalary(void);
    
protected:
    void printExtra(void)const;
    double calMerit(void);
    double m_allow;
};
#endif