#include "Manager.h"
Manager::Manager(const string& filename):Employee(filename)
{
    fscanf(m_file,"%lg",&m_bonus);
}
Manager::Manager(const string& name,double salary,double bonus):Employee(name ,salary,L3),m_bonus(bonus){
    fprintf(m_file,"%lg ",m_bonus);
}
void Manager::printInfo(void)const
{
    printBasic();
    printExtra();
    cout << endl;
}
void Manager::printExtra(void)const
{
    cout  << "work: Manager" << endl;
}
double Manager::calSalary(void)
{
    double salary=calBasic()+calMerit();
    cout << "all salary:" << salary<< endl;
    return salary;
}
double Manager::calMerit(void)
{
    cout << "factor:";
    double factor;
    cin >> factor;
    return m_bonus*factor;
}
