#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <vector>

using namespace std;

class Student
{
        private:
                int studentId;
                string studentName;
        public:
                Student(int i1, string s1)
                {
                        studentId = i1;
                        studentName = s1;
                }
                string getName()
                {
                        return studentName;
                }
};

class Course
{
        private:
                string courseName;
                int numUnits;
                vector<Student> vs;
        public:
                Course(string s1, int i1)
                {
                        courseName = s1;
                        numUnits = i1;
                }

                int getUnits()
                {
                        return numUnits;
                }

                string getCName();

                void clearStudents()
                {
                        vs.clear();
                        return;
                }

                void setSV (string x, int y)
                {
                        Student c(y,x);
                        vs.push_back(c);
                        cout<<"Student added"<<endl;
                        return;
                }

                void printStudents();

                void bubbleSortStudents();
                void deleteStudent(string n)
                {
                        for (int i = 0; i < vs.size(); i++)
                        {
                                if (vs[i].getName() == n)
                                {
                                        vs.erase(vs.begin() + i);
                                }
                        }
                        return;
                }
};
#endif
