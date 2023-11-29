//HashTable.cpp written by Joe Moser
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
                result = pow(result, hashMe[i] % 5);
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

            return false;
        }

        //deletion function to be written by Aidan

        //view function to be written by Kevin
};