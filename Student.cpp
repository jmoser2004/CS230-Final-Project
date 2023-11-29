//placeholder student class writen by Joe Moser
#include <string>
using namespace std;
class Student
{
    private:
        string name;
    public:
        Student(string n)//constructor
        {
            name = n;
        }
        //setter method below
        string getName(){return name;}
        //getter method below
        void setName(string n){name = n;}
};