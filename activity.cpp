#include <iostream>
#include <vector>
#include "activity.h"

string Course::getCName()
{
        return courseName;
}

void Course::printStudents()
{
        for(int i=0; i<vs.size(); i++)
        {
                string name = vs[i].getName();
                cout<<name<<endl;
        }
}

void Course::bubbleSortStudents()
{
        bool changed;
        do
        {
                changed = false;
                for(int i=1; i<vs.size(); i++)
                {
                        if(vs[i].getName() < vs[i-1].getName())
                        {
                                Student tmp = vs[i];
                                vs[i] = vs[i-1];
                                vs[i-1] = tmp;
                                changed = true;
                        }
                }
                if(!changed)
                        changed = false;

        }while(changed);
}
