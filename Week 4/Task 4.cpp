#include <iostream>
#include <map>
using namespace std;
struct Student
{
    int ID;
    string Name;
    string Class;
    Student(int n, string a, string b)
    {
        this->ID = n;
        this->Name = a;
        this->Class = b;
    }
};
class Students
{
public:
    map<int, Student> studentlist;

    void Insert(int n, string k, string m)
    {
        Student newstudent(n, k, m);
        studentlist.insert({newstudent.ID, newstudent});
    }
    void Del(int id)
    {
        auto i = studentlist.find(id);
        if (i != studentlist.end()) {
            studentlist.erase(i);
        }
    }
    string Info(int id)
    {
        auto i = studentlist.find(id);
        if (i != studentlist.end()) {
            return i->second.Name + "," + i->second.Class;
        }
        return "NA,NA";
    }
};
int main()
{
    string s;
    Students school;
    while (getline(cin, s) && s != "end")
    {
        int id;
        string first = "", ID = "", name = "", Class = "";
        int i = 0;
        while (s[i] != '(')
        {
            first += s[i];
            i++;
        }
        i++;
        if (first == "Insert")
        {
            while (s[i] != ',')
            {
                ID += s[i];
                i++;
            }
            id = stoi(ID);
            i++;
            while (s[i] != ',')
            {
                name += s[i];
                i++;
            }
            i++;
            while (s[i] != ')')
            {
                Class += s[i];
                i++;
            }
            school.Insert(id, name, Class);
        }
        else if (first == "Delete")
        {
            while (s[i] != ')')
            {
                ID += s[i];
                i++;
            }
            id = stoi(ID);
            school.Del(id);
        }
        else
        {
            while (s[i] != ')')
            {
                ID += s[i];
                i++;
            }
            id = stoi(ID);
            cout << school.Info(id);
        }
    }
}