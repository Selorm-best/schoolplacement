#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Student{
    //Student attributes
    int index_no;
    string surName;
    string otherName;
    string password;

//Constructor(runs on create an object of the class)
public:
        Student() {
            index_no=0; surName = "";otherName = ""; password = "";

            }
 // Sets the values of attributes of the object created
        void set_student(string surname,string firstname,int indexNumber){
        surName = surname;
        otherName = firstname;
        index_no = indexNumber;
        }


        void display(Student* studentrecord, int index_id){

        vector<Student> students ;
        ifstream inputfile;
        inputfile.open("Students.csv", ios::out | ios::app);

        string line = "";
        getline(inputfile, line);
        line = "";
        while(getline(inputfile,line)){
        int indexNumber;
        string surname;
        string firstname;
        string  tempString =" ";
        stringstream inputString(line);

    //Pick each Cell value on the line and store in a variable
        getline(inputString,surname,',');
        getline(inputString,firstname,',');
        getline(inputString,tempString,',');
        indexNumber =atoi(tempString.c_str());

        if(indexNumber ==index_id){

        //After every record of students, construct student object and add to vector
        studentrecord->set_student(surname,firstname,indexNumber);
        students.push_back(*(studentrecord));

        }
        line = "";
    }
    for (auto student : students){
            //Loop through the vector and pick the objects individually for display of the attribute values specified
            cout<<"   Student Index No:" << student.index_no<<endl;
            cout<<"                 Surname:" << student.surName<<endl;
            cout<<"           Other Names:" <<student.otherName<<endl;
            cout<<"\n";

    }

    }

    bool verify_student(int index_number, string password, Student* currentstudent){
    bool userverified = false;
     ifstream inputfile;
        inputfile.open("Students.csv", ios::out | ios::app);

        string line = "";
        getline(inputfile, line);
        line = "";
        while(getline(inputfile,line)){
        int indexNumber;
        string surname;
        string firstname;
        string passcode;
        string  tempString =" ";
        stringstream inputString(line);

    //Pick each Cell value on the line and store in a variable
        getline(inputString,surname,',');
        getline(inputString,firstname,',');
        getline(inputString,tempString,',');
        indexNumber =atoi(tempString.c_str());
        getline(inputString,passcode,',');
        if(index_number ==indexNumber && password == passcode){
                currentstudent->set_student(surname,firstname,indexNumber);
                userverified = true;
    }
}
        return userverified;
}
};

#endif // STUDENT_H_INCLUDED
