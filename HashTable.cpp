//HashTable.cpp written by Joe Moser
#include <iostream>
#include <cmath>
#include "Student.cpp"

const int TABLE_SIZE = 1000;

class HashTable
{
    private:
        string name;
        Student* table[TABLE_SIZE];
    public:
        HashTable(string n)//constructor
        {
            name = n;
            clearTable();
        }
        //hash functions below
        //clearTable() written by Joe Moser
        void clearTable()//sets all values in the table to NULL
        {
            for(int i = 0; i < TABLE_SIZE; i++)
                table[i] = NULL;
        }
        //hashAlgorithm() written by Joe Moser
        int hashAlgorithm(string hashMe)//hashes a string input, returns result of algorithm
        {
            int result = 0;
            //actual algorithm starts here
            for(int i = 0; i < (int)hashMe.length(); i++)
            {
                result += hashMe[i];
                result = pow(result, hashMe[i] % 2) + 1;
                result %= TABLE_SIZE;
            }
            //actual algorithm ends here
            return result;
        }
        //insertStudent() written by Joe Moser
        bool insertStudent(Student* insertMe)//inserts a pointer to a student object into the hash table, returns true if insertion is successful
        {
            int insertionPoint = hashAlgorithm(insertMe->getName());

            if(table[insertionPoint] == NULL)
            {
                table[insertionPoint] = insertMe;
                return true;
            }
            else//entire else block is used for linked list shenanigans
            {
                Student* temp = table[insertionPoint];

                while(temp->getNext() != NULL)
                    temp = temp->getNext();
                
                temp->setNext(insertMe);
                insertMe->setPrev(temp);

                return false;
            }

            return false;
        }
        //findStudent() written by Joe Moser
        Student* findStudent()//searches for a student in the table by name, returns a pointer to the student if it is found, or NULL if it is not found
        {
            string search;

            cout << "Please enter the name of the student you would like to find: ";
            cin >> search;

            int hashResult = hashAlgorithm(search);

            if(table[hashResult] != NULL)
            {
                if(table[hashResult]->getName() == search)
                    return table[hashResult];
                else//entire else block checks the linked list
                {
                    Student* temp = table[hashResult];

                    while(temp != NULL)
                    {
                        if(temp->getName() == search)
                            return temp;
                        temp = temp->getNext();
                    }
                }
            }
            cout << endl << endl << search << " not found!\n\n\n";

            return NULL;
        }
        //deleteStudent() written by Joe Moser
        bool deleteStudent()//attempts to delete a student, returns true if the deletion is successful or false if the deletion is unsuccessful
        {
            Student* deleteMe = findStudent();
  
            if(deleteMe == NULL)//returns false if the searched student is not in the hash table
                return false;

            Student* start = deleteMe;

            if(start->getPrev() != NULL)//if the student to be deleted is not the first item in the list, this links together the other items in the list; otherwise, it just sets the start of that position in the hash table to the next item in the list
            {
                start = start->getPrev();
                start->setNext(deleteMe->getNext());
                start->getNext()->setPrev(start);

                while(start->getPrev() != NULL)
                    start = start->getPrev();
            }
            else
                start = deleteMe->getNext();
            
            int deleteMePos = hashAlgorithm(deleteMe->getName());//sets a new int to the location of the student pointer searched for in the table

            table[deleteMePos] = start;

            delete deleteMe;

            return true;
        }
        //printStudent() written by Joe Moser
        void printStudent()
        {
            Student* printMe = findStudent();

            if(printMe == NULL)
                return;
            
            cout << "Student " << printMe->getName() << " stats:\n";
            cout << "------------------\n";
            cout << "------------------\n";
            cout << "------------------\n";
            cout << "------------------\n\n\n";
        }
};