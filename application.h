#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Application{
private:
    int index_number;
    //All choices are an array of the school choice's id, course choice id and status of admission
    int first_choice[3];
    int second_choice[3];
    int third_choice[3];
    int fourth_choice[3];

public:
    Application(int index_no)
                {index_number = index_no; }
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

    //View All Applications for a Student
    void view_application(int index_no, Application*app){
        vector<Application> applications;
        ifstream file;
    file.open("application.csv",ios::out|ios::app);

    string line="";
    getline(file,line);
    line="";

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
            Course course;
            for (auto application : applications){
            cout<< "Here is Your Application List for \n\n";
            cout<<"Student name: ("<<index_number<<")"<<endl;
            cout<<"Your raw Score of best Six subjects"<<endl;
            school->retrieve(school,application.first_choice[0]);
            cout<<"First choice:\n School Name:"<<school->schoolName<<"\nCourse Name: "<<first_choice[1]<<"\nCut off:\nAdmission Status: "<<application.first_choice[2]<<endl;
            /*cout<<"Second choice:\n School Name:"<<second_choice[0]<<"\nCourse Name: "<<second_choice[1]<<"\nCut off:"<<basescore<<"\nAdmission Status: "<<second_choice[2]<<endl;
            cout<<"Third choice:\n School Name:"<<third_choice[0]<<"\nCourse Name: "<<third_choice[1]<<"\nCut off:"<<basescore<<"\nAdmission Status: "<<third_choice[2]<<endl;
            cout<<"Fourth choice:\n School Name:"<<fourth_choice[0]<<"\nCourse Name: "<<fourth_choice[1]<<"\nCut off:"<<basescore<<"\nAdmission Status: "<<fourth_choice[2]<<endl;
    */
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
