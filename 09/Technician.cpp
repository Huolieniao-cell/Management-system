#include "Technician.h"
Technician::Technician(const string&filename):Employee(filename)
{
    fscanf(m_file,"%lg",&m_allow);
}
Technician::Technician(const string& name,double salary,double allow):Employee(name,salary,L2),m_allow(allow)
{
    fprintf(m_file,"%g ",m_allow);
}
void Technician::printInfo(void)const
{
    printBasic();
    printExtra();
    cout << endl;
}
void Technician::printExtra(void)const
{
    cout << "work:  Technician" << endl; 
}
double Technician::calSalary(void)
{
    double salary=calBasic()+ calMerit();
    cout << "all salary:  " << salary << endl;
    return salary;
}
double Technician::calMerit(void)
{
    double factor;
    cout << "factor:";
    cin >> factor;
    return m_allow* factor;
}