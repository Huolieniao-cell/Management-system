#include "CTO.h"
CTO::CTO(const string& name,double salary,double bonus,double allow):Employee(name,salary,L4),Manager(name,salary,bonus),Technician(name,salary,allow)
{
    
}
CTO::CTO(const string& filename):Employee(filename),Technician(filename),Manager(filename){}
void CTO::printInfo(void)const
{
    printBasic();
    printExtra();
    cout << endl;
}
void CTO::printExtra(void)const
{
    cout << "work: CTO"<< endl;
}
double CTO::calSalary(void)
{
    double salary=calBasic()+calMerit();
    cout << "all salary: " << salary << endl;
    return salary;
}
double CTO::calMerit(void)
{
    return (Manager::calMerit()+Technician::calMerit())/2;
}