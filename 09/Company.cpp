#include "Company.h"
Company Company::company;
Company& Company::getCompany(void)
{
    return company;
}
Company::Company(void)
{
    if(access("id.txt",F_OK)==-1)
    {
        FILE* fp=fopen("id.txt","w");
        fprintf(fp,"%d",10001);
        fclose(fp);
    }
    if(access("count.txt",F_OK)==-1)
    {
        FILE* fp2= fopen("count.txt","w");
        fprintf(fp2,"%d",0);
        fclose(fp2);
    }
    else{
        for(int i=0;i<size();i++){
            int id=10001+i;
            char filename[20];
            sprintf(filename,"%d",id);
            if(access(filename,F_OK)==-1)continue;
            else{
                empVector.push_back(loadInfo(filename)); 
            }
        }
    }

}
Employee* Company::loadInfo(const string& name)
{
    int level;
    FILE* f_info=fopen(name.c_str(),"r");
    fscanf(f_info,"%d",&level);
    Employee* tmp;
    switch(level){
        case 101:
            tmp=new Employee(name);
            break;
        case 201:
            tmp=new Technician(name);
            break;
        case 301:
            tmp=new Manager(name);
            break;
        case 401:
            tmp =new CTO(name);
            break;
    }
    fclose(f_info);
    return tmp;
}
int Company::size()const 
{
    return Employee::getCount();
}
Company::~Company(void){}
void Company::run(void)
{
    while(1){
        printMenu();
        int choose;
        cout << "choose:  ";
        cin >> choose;
        switch(choose){
            case 1:
                addEmployee();
                sleep(2);
                break;
            case 2:
                deleteEmployee();
                sleep(2);
                break;
            case 3:
                updateEmployee();
                sleep(2);
                break;
            case 4:
                queryEmployee();
                sleep(2);
                break;
            case 5:
                paySalary();
                break;
            case 0:
                sleep(1);
                cout << "exit......" << endl;
                exit(0);
            default:
                cout << "error num" << endl;
                sleep(1);
                break;
        }
    }
}
void Company::printMenu(void)
{
    cout << "*****************************" << endl;
    cout << "《欢迎进入企业员工管理系统》" << endl;
    printf("all count:%u\n",(uint32_t)empVector.size());
    cout << "<1> 添加员工" << endl;
    cout << "<2> 删除员工" << endl;
    cout << "<3> 修改员工信息" << endl;
    cout << "<4> 查询员工信息" << endl;
    cout << "<5> 结算工资" << endl;
    cout << "<0> 退出" << endl;
    cout << "*****************************" << endl;
}
void Company::addEmployee(void)
{
    string name;
    double salary;
    double allow;
    double bonus;
    cout << "name:";
    cin >> name;
    cout << "salary:";
    cin >> salary;

    cout << "选择职位:<1>/<2>/<3>/<4>:" << endl;;
    cout << "<1> 添加普通员工" << endl;
    cout << "<2> 添加技术员" << endl;
    cout << "<3> 添加经理" << endl;
    cout << "<4> 添加技术主管" << endl;
    int type;
    cin >> type;
    switch(type){
        case 1:
            empVector.push_back(new Employee(name,salary));
            break;
        case 2:
            cout << "allow:";
            cin >> allow;
            empVector.push_back(new Technician(name,salary,allow));
            break;
        case 3:
            cout << "bonus:";
            cin >> bonus;
            empVector.push_back(new Manager(name,salary,bonus));
            break;
        case 4:
            cout << "allow : ";
            cin >> allow;
            cout << "bonus";
            cin >> bonus;
            empVector.push_back(new CTO(name,salary,allow,bonus));
        default:
            cout << "error" << endl;
            break;

    }
    cout << "add success" << endl;
}
void Company::deleteEmployee(void)
{
    int id;
    char name[20];
    cout << "delete id :";
    cin >> id;
    sprintf(name,"%d",id);
    if(access(name,F_OK)==-1){
        cout << "no file" << endl;
        return;
    }
    else{
        int type;
        cout << "1:yes     2:no"<< endl;
        cin >> type;
        if(type==1){
            for(int i=0;i<empVector.size();i++){
                if(*empVector[i]==id){
                    delete empVector[i];
                    empVector[i]=NULL;
                    empVector.erase(empVector.begin()+i);
                    unlink(name);
                    cout << "success delete file" << endl;
                    break;
                }
            }
        }
    }
}
void Company::updateEmployee(void)
{
    int id;
    char name[20];
    cout << "update id :";
    cin >> id;
    sprintf(name,"%d",id);
    if(access(name,F_OK)==-1){
        cout << "no file" << endl;
        return;
    }
    else{
        for(int i=0;i<empVector.size();i++)
        {
            if(*empVector[i]==id){
                double salary;
                cout << "update salary:";
                cin >> salary;
                empVector[i]->setSalary(salary);
                empVector[i]->saveInfo();
                cout << "update success!" << endl;
                break;
            }
        }
    }
}
void Company::queryEmployee(void)
{
    int choose;
    cout << "1:queryall     2:queryone" << endl;
    cin >> choose;
    if(choose==1){
        queryAll();
    }
    else{
        queryOne();
    }
}
void Company::queryAll(void)
{
    for(int i=0;i<empVector.size();i++){
        empVector[i]->printInfo();
        cout << "=======================" << endl;
    }
}
void Company::queryOne(void)
{
    int id;
    cout << "query id: ";
    cin >> id;
    for(int i=0;i<empVector.size();i++){
        if(*empVector[i]==id){
            empVector[i]->printInfo();
            cout << "=======================" << endl;
        }
        else{
            cout << "no query !"<< endl;
        }
        break;
    }
}
void Company::paySalary(void)
{
    int id;
    cout << "pay id:";
    cin >> id;
    for(int i=0;i<empVector.size();i++){
        if(*empVector[i]==id){
            empVector[i]->calSalary();
            cout << "=======================" << endl;
        }
        else{
            cout << "no query " << endl;
        }
        break;
    }
}
