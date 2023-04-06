#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class School{
    //School attributes

    public:
        int school_id;
        string schoolName;
    string schoolPrefix;
    string password;

//Constructor(runs on create an object of the class)
public:

 // Sets the values of attributes of the object created
        void set_school(int schoolId,string schoolname,string schoolprefix){
        school_id = schoolId;
        schoolName = schoolname;
        schoolPrefix = schoolprefix;
        }


       vector<School>  display(School* schoolrecord,string type){

        vector<School> schools ;
        ifstream inputfile;
        inputfile.open("schools.csv", ios::out | ios::app);

        string line = "";
        getline(inputfile, line);
        line = "";
        while(getline(inputfile,line)){
        int schoolNumber;
        string school_name;
        string school_prefix;
        string  tempString =" ";
        stringstream inputString(line);

    //Pick each Cell value on the line and store in a variable
        getline(inputString,tempString,',');
        schoolNumber =atoi(tempString.c_str());
        getline(inputString,school_name,',');
        getline(inputString,school_prefix,',');




        //After every record of school, construct school object and add to vector

        schoolrecord->set_school(schoolNumber,school_name,school_prefix);
        schools.push_back(*(schoolrecord));


        line = "";
    }
     if (type=="print"){
    for (auto school : schools){

            //Loop through the vector and pick the objects individually for display of the attribute values specified
            cout<<"   High School No:" << school.school_id<<endl;
            cout<<"        School name:" << school.schoolName<<endl;
            cout<<"        Name prefix:" <<school.schoolPrefix<<endl;
            cout<<"\n";
            }

    }


    return schools;
    }

     void  retrieve(School* school, int schoolcode){

        ifstream inputfile;
        inputfile.open("schools.csv", ios::out | ios::app);

        string line = "";
        getline(inputfile, line);
        line = "";
        while(getline(inputfile,line)){
        int schoolNumber;
        string school_name;
        string school_prefix;
        string  tempString =" ";
        stringstream inputString(line);

    //Pick each Cell value on the line and store in a variable
        getline(inputString,tempString,',');
        schoolNumber =atoi(tempString.c_str());
        getline(inputString,school_name,',');
        getline(inputString,school_prefix,',');

        if (schoolcode == schoolNumber){


        //After every record of school, construct school object and add to vector
        school->set_school(schoolNumber,school_name,school_prefix);


        }
        line = "";
    }


    }


    bool verify_school(int school_number, string passkey, School* currentschool){
    bool userverified = false;
     ifstream inputfile;
        inputfile.open("schools.csv", ios::out | ios::app);

        string line = "";
        getline(inputfile, line);
        line = "";
        while(getline(inputfile,line)){
        int schoolNumber;
        string school_name;
        string school_prefix;
        string passcode;
        string  tempString =" ";
        stringstream inputString(line);

    //Pick each Cell value on the line and store in a variable
        getline(inputString,tempString,',');
        schoolNumber =atoi(tempString.c_str());
        getline(inputString,school_name,',');
        getline(inputString,school_prefix,',');
        getline(inputString,passcode,',');
        if(school_number == schoolNumber && passkey == passcode){
                currentschool->set_school(schoolNumber,school_name,school_prefix);
                userverified = true;
    }
}
        inputfile.close();
        return userverified;
}
};

#endif // SCHOOL_H_INCLUDED
