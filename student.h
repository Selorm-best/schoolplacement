#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Student{
    int index_no;
    string surName;
    string otherName;

//Constructor
public:
        Student(
                string surname,
                string othername,
                int indexNumber
                ) {index_no= indexNumber; surName = surname;otherName = othername;}

            void display(){
            cout<<"   Student Index No:" <<index_no<<endl;
            cout<<"                 Surname:" << surName<<endl;
            cout<<"           Other Names:" <<otherName<<endl;
            cout<<"\n";
            }

};

#endif // STUDENT_H_INCLUDED
