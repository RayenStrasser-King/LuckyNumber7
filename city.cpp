#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "city.h"
vector<City> store_data(string file)
{
        City c;
        vector<City> vc;
        char comma = ',';
        ifstream input(file);
        string line;
        while(getline(input, line))
        {
                istringstream ss (line);
                ss>>c.index>>comma;
                getline(ss,c.name,'\n');
                vc.push_back(c);
        }
        input.close();
        return vc;
}
void print_index(vector<City> *ptr)
{
        int num;
        int cha;

        for (int i = 0; i < (*ptr).size(); i ++)
        {
                if ( (*ptr)[i].index > (*ptr)[i].name.size())
                {
                        cout<<"?"<<endl;
                }
                else
                {
                        cout<<(*ptr)[i].name[(*ptr)[i].index]<<endl;

                }
               // num =(*ptr)[i].index;
               // cha = (*ptr)[i].name[num];
               // cout<<(*ptr)[i].name<<endl;
        }
}
