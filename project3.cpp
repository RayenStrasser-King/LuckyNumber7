#include <iostream>
#include <vector>
#include "activity.h"

using namespace std;

int main()
{

        int answer, cUnits, sId;
        string cName, sName;
        vector<Course *> list;

        do
        {
                cout<<"Welcome! What would you like to do?"<<endl;
                cout<<"1) Add a new course."<<endl;
                cout<<"2) Add a new student"<<endl;
                cout<<"3) Display all the course."<<endl;
                cout<<"4) Display all the students within a course."<<endl;
                cin>>answer;
                cin.ignore();

                if (answer==1)
                {
                        cout<<"Please enter the name of course."<<endl;
                        getline(cin, cName);
                        cout<<"Please enter the number of units for this course."<<endl;
                        cin>>cUnits;
                        Course *temp = new Course(cName, cUnits);
                        list.push_back(temp);
                        cout<<"Course was made."<<endl;
                }

                if (answer==2)
                {
                        cout<<"Please enter the name of the course you would like to add student to."<<endl;
                        getline(cin, cName);
                        cout<<"Please enter the name of student."<<endl;
                        getline(cin, sName);
                        cout<<"Please enter the Student ID number."<<endl;
                        cin>>sId;

                        for (int i=0; i<list.size(); i++)
                        {
                                if((*list[i]).getCName()==cName)
                                        (*list[i]).setSV(sName, sId);
                        }
                        cout<<"Student was made."<<endl;
                }

                if (answer==3)
                {
                        cout<<"List of courses are:"<<endl;
                        for(int i=0; i<list.size(); i++)
                        {
                                string name;
                                name=(*list[i]).getCName();
                                cout<<name<<endl;
                        }
                }

                if (answer==4)
                {
                        cout<<"Name of course."<<endl;
                        getline(cin, cName);
                        cout<<"Students in course "<<cName<<":"<<endl;
                        for (int i=0; i<list.size(); i++)
                        {
                                if ((*list[i]).getCName()==cName)
                                        (*list[i]).printStudents();
                        }
                }
        }
        while (answer!=7);
        return 0;
}
