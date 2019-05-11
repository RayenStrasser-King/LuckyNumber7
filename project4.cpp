#include <iostream>
#include <vector>
#include "activity.h"
#include <algorithm>

using namespace std;

int main()
{

        int answer, cUnits, sId;
        string cName, sName;
        vector<Course *> list;

        do
        {
                cout<<endl;
                cout<<"Course Management System"<<endl;
                cout<<"1) Add a new course"<<endl;
                cout<<"2) Add a new student"<<endl;
                cout<<"3) Display all the courses"<<endl;
                cout<<"4) Display all the students within a course"<<endl;
                cout<<"5) Remove a course"<<endl;
                cout<<"6) Remove a student within a course"<<endl;
                cout<<"7) Exit"<<endl;
                cin>>answer;
                cin.ignore();

                if (answer == 1)
                {
                        cout<<"Enter course name."<<endl;
                        getline(cin, cName);
                        cout<<"Enter number of units."<<endl;
                        cin>>cUnits;
                        Course *temp = new Course(cName, cUnits);
                        list.push_back(temp);
                        cout<<"Adding Course."<<endl;
                }

                if (answer == 2)
                {
                        cout<<"Enter course that you want to add student to it."<<endl;
                        getline(cin, cName);
                        cout<<"Enter a student name."<<endl;
                        getline(cin, sName);
                        cout<<"Enter a student ID."<<endl;
                        cin>>sId;

                        for (int i=0; i<list.size(); i++)
                        {
                                if((*list[i]).getCName()==cName)
                                        (*list[i]).setSV(sName, sId);
                        }
                        //cout<<"Student was made."<<endl;
                }

                if (answer == 3)
                {
                        cout<<"Found "<<list.size()<<" course(s)"<<endl;
                        bool changed;
                        do
                        {
                                changed = false;
                                for(int i=1; i<list.size(); i++)
                                {
                                        if(list[i]->getCName() < list[i-1]->getCName())
                                        {
                                                Course * tmp = list[i];
                                                list[i] = list[i-1];
                                                list[i-1] = tmp;
                                                changed = true;
                                        }
                                }
                                if(!changed)
                                        changed = false;
                        
                        }while(changed);
                        for(int j=0; j<list.size(); j++)
                                cout<<"courseName = "<<list[j]->getCName()<<endl;
                }

                if (answer == 4)
                {
                        cout<<"Name of course."<<endl;
                        getline(cin, cName);
                        cout<<"Students in course "<<cName<<":"<<endl;
                        for (int i=0; i<list.size(); i++)
                        {
                                if ((*list[i]).getCName()==cName)
                                        (*list[i]).bubbleSortStudents();
                                (*list[i]).printStudents();
                        }
                }

                if (answer == 5)
                {
                        cout<<"Name the course that you would like to delete."<<endl;
                        getline(cin, cName);
                        for(int i = 0; i < list.size(); i++)
                        {
                                if(list[i]->getCName() == cName)
                                {
                                        list[i]->clearStudents();
                                        Course * tmp = list[i];
                                        list.erase(list.begin() + i);
                                        delete tmp;
                                        tmp = NULL;
                                }
                        }
                }

                if (answer == 6)
                {
                        cout<<"Enter course that you want to remove student from it."<<endl;
                        getline(cin, cName);
                        cout<<"Enter a student you want to remove from the course."<<endl;
                        getline(cin, sName);
                        for (int i = 0; i<list.size(); i++)
                        {
                                if (cName == list[i]->getCName())
                                {
                                        list[i]->deleteStudent(sName);
                                }

                        }
                }
        }while (answer != 7);
        cout<<"Come back again!"<<endl;

        return 0;
}

