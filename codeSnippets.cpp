//findStudent() written by Joe Moser
Student* findStudent()//searches for a student in the table by name, returns a pointer to the student if it is found, or NULL if it is not found
{
    string search;

    cout << "Please enter the name of the student you would like to find: ";
    cin >> search;

    int hashResult = hashAlgorithm(search);

    if(table[hashResult] != NULL)
        if(table[hashResult]->getName() == search)
            return table[hashResult];
            
    cout << endl << endl << search << " not found!\n\n\n";

    return NULL;
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