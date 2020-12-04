#include "Employee.h"
int Employee::m_count=0;
ostream&  operator<<(ostream& os,const Employee& e)
{
    os << "name:" << e.m_name << endl;
    os << "id:" << e.m_id << endl;
    os << "salary" << e.m_salary << endl;
    return os;
}
bool Employee::operator==(int id)const
{
    if(m_id==id)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator!=(int id)const
{
   return !(*this == id);
}
Employee::Employee(void)
{
    m_id=0;
    m_name="error name";
    m_salary=0.0;
}
Employee::Employee(const string& name,double salary,LEVEL level):m_name(name),m_salary(salary),m_level(level)
{
    
    FILE* p_id=fopen("id.txt","r+");
    fscanf(p_id,"%d",&m_id);
    fseek(p_id,0,SEEK_SET);
    fprintf(p_id,"%d",m_id+1);
    fclose(p_id);

    char filename[20];
    sprintf(filename,"%d",m_id);
    m_file = fopen(filename,"w");
    if(m_file == NULL){
        perror("fopen");
    }
    else{
        saveInfo();
        m_count++;
        FILE* fp2 = fopen("count.txt","w");
        fprintf(fp2,"%d",m_count);
        fclose(fp2);
    }
}
Employee::Employee(const string& filename)
{
    int level;
    char name[20];
    m_file=fopen(filename.c_str(),"r+");
    fscanf(m_file,"%d %d %s %lg",&level,&m_id,name,&m_salary);
    m_name=name;
    switch(level){
        case 101:
            m_level=L1;
            break;
        case 201:
            m_level=L2;
            break;
        case 301:
            m_level=L3;
            break;
        case 401:
            m_level=L4;
            break;
    }
    
}
const int& Employee::getCount(void)
{
    FILE * fp2 = fopen("count.txt","r");
    fscanf(fp2,"%d",&m_count);
    fclose(fp2);
    return m_count;
}
Employee::~Employee(void){
    fclose(m_file);
    m_file = NULL;
}
void Employee::saveInfo(void)
{
    fseek(m_file, 0,SEEK_SET);
    fprintf(m_file,"%d %d %s %g ",m_level,m_id,m_name.c_str(),m_salary);
    fflush(m_file);
}
void Employee::printInfo(void)const
{
    printBasic();
    printExtra();
    cout << endl;
}
void Employee::printBasic(void)const
{
    cout << "name:"<< m_name << endl;
    cout << "id:" << m_id << endl;
    cout << "salary:" << m_salary << endl;
}
void Employee::printExtra(void)const
{
    cout << "work : Employee" << endl;
}
double Employee::calSalary(void)
{
    double salary=calBasic()+calMerit();
    cout << "salary all:" <<salary << endl;
}
double Employee::calBasic(void)
{
    int days;
    cout << "days:";
    cin >> days;
    m_attend = days/23.0;
    double basic = m_salary*m_attend;
    return basic;
}
double Employee::calMerit(void)
{
    return m_salary*m_attend/2;
}
void Employee::setId(int id)
{
    if(id<10000){
        cout << "error id" << endl;
    }
    else{
        m_id=id;
    }
}
void Employee::setName(const string& name)
{
    if(name.size()>20){
        cout << "error name" << endl;
    }
    else{
        m_name=name;
    }
}
void Employee::setSalary(double salary)
{
    if(salary<0){
        cout << "error salary" <<endl;
    }
    else{
        m_salary = salary;
    }
}
