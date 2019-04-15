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
