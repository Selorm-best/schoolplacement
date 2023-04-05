#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>>
using namespace std;

//This Function is a Global function that helps to return a status text for each status boolean code of the application choices in  csv file
string show_admission_status(int status){
    string admission_status  = status == 1 ? "Admitted": status == 0 ? "Pending" :"Invalid Status";
            return admission_status;
}

// Here is the main class model of the Application data
class Application{
private:
    int index_number;
    //All choices are an array of the school choice's id, course choice id and status of admission respectively
    int first_choice[3];
    int second_choice[3];
    int third_choice[3];
    int fourth_choice[3];

public:
    // This runs as soon as the object of application  is created. It sets the index_number attribute to the value the user provides when creating the object
    Application(int index_no)
                {index_number = index_no; }

    // This method helps to assign the values of the application choices' attrubutes
    void set_application(int firstchoice[],int secondchoice[], int thirdchoice[],int fourthchoice[]){
    first_choice[0] = *(firstchoice);
    first_choice[1] = *(firstchoice+1);
    first_choice[2] = *(firstchoice+2);

    second_choice[0]= secondchoice[0];
    second_choice[1]= secondchoice[1];
    second_choice[2]= secondchoice[2];

    third_choice[0] = thirdchoice[0];
    third_choice[1] = thirdchoice[1];
    third_choice[2] = thirdchoice[2];

    fourth_choice[0]=fourthchoice[0];
     fourth_choice[1]=fourthchoice[1];
      fourth_choice[2]=fourthchoice[2];
    }

    //Helps to View the Application of a Student
    void view_application(int index_no, Application*app){

        vector<Application> applications;
    ifstream file;
    file.open("application.csv",ios::out|ios::app); //We open the csv file containin the data

// This block of code gets the first line of the csv file which is the title.
    string line="";
    getline(file,line);
    line="";     //We do not want that to be viewed so we clear it from the input we are getting

    // This loop goes through the rest of the csv file line by line
    while(getline(file,line)){


        int indexnumber;
        int firstchoice[3];
        int secondchoice[3];
        int thirdchoice[3];
        int fourthchoice[3];

        string tempString ="";
        stringstream inputString(line);
        getline(inputString,tempString,',');
        indexnumber = atoi(tempString.c_str());

        getline(inputString,tempString,',');
        firstchoice[0]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        firstchoice[1]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        firstchoice[2]=atoi(tempString.c_str());
        if (indexnumber == index_no){


        getline(inputString,tempString,',');
        secondchoice[0]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
         secondchoice[1]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
         secondchoice[2]=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        thirdchoice[0]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        thirdchoice[1]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        thirdchoice[2]=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        fourthchoice[0]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        fourthchoice[1]=atoi(tempString.c_str());
        getline(inputString,tempString,',');
        fourthchoice[2]=atoi(tempString.c_str());


        app->set_application(firstchoice,secondchoice,thirdchoice,fourthchoice);
        applications.push_back(*(app));


        }
          line ="";
    }
file.close();
            if (applications.empty()==true){

                cout<<"The Application record of this index number where not found\n";
            }
            else{
            School *school = new School();
            Course *course = new Course();;
            for (auto application : applications){
            cout<< "Here is Your Application List for \n\n";
            cout<<"Student name: ("<<index_number<<")"<<endl;
            cout<<"Your raw Score of best Six subjects"<<endl;

            school->retrieve(school,application.first_choice[0]);
            course->retrieve_course(course,application.first_choice[0],first_choice[1]);
            School school1 = *school;
            Course course1 = *course;
            cout<<"First choice:\n============\nSchool Name:"<<school1.schoolName<<"\nCourse Name: "<<course1.course_name
            <<"\nCut off:"<<course1.basescore <<"\nAdmission Status: "<<show_admission_status(first_choice[2])<<"\n"<<endl;

            school->retrieve(school,application.second_choice[0]);
            course->retrieve_course(course,application.second_choice[0],second_choice[1]);
            School school2 = *school;
            Course course2 = *course;
            cout<<"Second choice:\n============\nSchool Name:"<<school2.schoolName<<"\nCourse Name: "<<course2.course_name
            <<"\nCut off:"<<course2.basescore <<"\nAdmission Status: "<<show_admission_status(second_choice[2])<<"\n"<<endl;

            school->retrieve(school,application.third_choice[0]);
            course->retrieve_course(course,application.third_choice[0],third_choice[1]);
            School school3 = *school;
            Course course3 = *course;
            cout<<"Third choice:\n============\nSchool Name:"<<school3.schoolName<<"\nCourse Name: "<<course3.course_name
            <<"\nCut off:"<<course3.basescore <<"\nAdmission Status: "<<show_admission_status(third_choice[2])<<"\n"<<endl;

            school->retrieve(school,application.fourth_choice[0]);
            course->retrieve_course(course,application.fourth_choice[0],fourth_choice[1]);
            School school4 = *school;
            Course course4 = *course;
            cout<<"Fourth choice:\n============\nSchool Name:"<<school4.schoolName<<"\nCourse Name: "<<course4.course_name
            <<"\nCut off:"<<course4.basescore <<"\nAdmission Status: "<<show_admission_status(fourth_choice[2])<<"\n"<<endl;
            }
            }
    }
    //View All Applications for a School
    view_application(int school_no)const{



    }
    update_admission_status(int school_id){

    }
};

#endif // APPLICATION_H_INCLUDED
