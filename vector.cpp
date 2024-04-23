#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
class Student 
{
    public:
           int rollNo;
           int age;
           char sex;
           const char* name;
    map<string, int> marks;
    Student(int a, int b, char c, const char* d, map<string,
    int> m) : rollNo(a), age(b), sex(c),name(d), marks(m) 
     {
     }
 };
bool f1(Student s1,  Student s2)
{
    return strcmp(s1.name, s2.name)<0 ;
}
int main() 
{
    map<string, int> marks1 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks2 = {{"English", 70}, {"Maths", 95}, {"Science", 89}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks3 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 79}, {"Geography", 88}};
    map<string, int> marks4 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 85}, {"Geography", 88}};
    map<string, int> marks5 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks6 = {{"English", 90}, {"Maths", 90}, {"Science", 85}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks7 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 75}, {"Geography", 89}};
    map<string, int> marks8 = {{"English", 80}, {"Maths", 90}, {"Science", 87}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks9 = {{"English", 80}, {"Maths", 90}, {"Science", 85}, {"History", 75}, {"Geography", 88}};
    map<string, int> marks10 = {{"English", 87}, {"Maths", 95}, {"Science", 86}, {"History", 79}, {"Geography", 88}};
    vector<Student>s;
    s.push_back(Student(101,22, 'F',"Ankita",marks1));
    s.push_back(Student(102,25, 'M',"Akash",marks2));
    s.push_back(Student(103,25, 'F',"Pranjali",marks3));
    s.push_back(Student(104,25, 'F',"Mohini",marks4));
    s.push_back(Student(105,25, 'F',"Tanuja",marks5));
    s.push_back(Student(106,25, 'M',"Rohit",marks6));
    s.push_back(Student(107,25, 'M',"Shree",marks7));
    s.push_back(Student(108,25, 'F',"Sakshi",marks8));
    s.push_back(Student(109,25, 'F',"Vedika",marks9));
    s.push_back(Student(110,25, 'M',"Rohan",marks10));
   sort(s.begin(), s.end(), f1);
   for ( auto it : s) 
   {
        cout << it.rollNo << " " << it.age << " " << it.sex << " " << it.name << " ";
        for (auto marks : it.marks) 
        {
            cout << marks.first << ": " << marks.second << " ";
        }
            cout << endl;
   }
    return 0;
}  