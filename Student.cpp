//placeholder student class writen by Joe Moser
#include <string>
using namespace std;
class Student
{
    private:
        string name;
        Student* next;
        Student* prev;
    public:
        Student(string n)//constructor
        {
            name = n;
            next = NULL;
            prev = NULL;
        }
        //getter methods below
        string getName(){return name;}
        Student* getNext(){return next;}
        Student* getPrev(){return prev;}
        //setter methods below
        void setName(string n){name = n;}
        void setNext(Student* n){next = n;}
        void setPrev(Student* p){prev = p;}
};