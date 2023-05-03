#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
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

    // This method helps to assign the values of the application choices' attrubutes
    void set_application(int index_no,int firstchoice[],int secondchoice[], int thirdchoice[],int fourthchoice[]){
    index_number = index_no;
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

//This methods aids students users to create application for themselves to school in the list and the courses they offer
void create_application(int index_no){
School*schoolrecord = new School();
 vector<School> schools = schoolrecord->display(schoolrecord,"data");
Course*courserecord = new Course();
int first_choice[3];
int second_choice[3];
int third_choice[3];
int four_choice[3];
fstream file;

file.open("application.csv", ios::out | ios::app );



cout<<"Here are the High Schools You can enroll for and the details of the courses they offer \n\n"<<endl;
for(auto school: schools){
    cout<<"School id - "<<school.school_id<<":"<<school.schoolName<<endl;
    courserecord->view_courses(courserecord,school.school_id);
}
cout<<"Enter your first choice school and course respectively"<<endl;
cout<<"School id:\n";
cin >>first_choice[0];
cout<<"Course id:\n";
cin >>first_choice[1];

cout<<"Enter your second choice school and course respectively"<<endl;
cout<<"School id:\n";
cin >>second_choice[0];
cout<<"Course id:\n";
cin >>second_choice[1];

cout<<"Enter your third choice school and course respectively"<<endl;
cout<<"School id:\n";
cin >>third_choice[0];
cout<<"Course id:\n";
cin >>third_choice[1];

cout<<"Enter your fourth choice school and course respectively"<<endl;
cout<<"School id:\n";
cin >>fourth_choice[0];
cout<<"Course id:\n";
cin >>fourth_choice[1];

file<<index_no<<","
    <<first_choice[0]<<","<<first_choice[1]<<","<<0<<","
     <<second_choice[0]<<","<<second_choice[1]<<","<<0<<","
    <<third_choice[0]<<","<<third_choice[1]<< "," <<0<<","
    <<fourth_choice[0]<<","<<fourth_choice[1]<< "," <<0<<",\n";

file.close();
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


        app->set_application(indexnumber,firstchoice,secondchoice,thirdchoice,fourthchoice);
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
            Course *course = new Course();

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
    void view_applications(int school_no, Application*app){

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

     if (school_no == firstchoice[0] )
        app->set_application(indexnumber,firstchoice,second_choice,third_choice,fourth_choice);
    if (school_no == secondchoice[0])
        app->set_application(indexnumber,first_choice,secondchoice,third_choice,fourth_choice);
    if (school_no == thirdchoice[0] )
        app->set_application(indexnumber,first_choice,second_choice,thirdchoice,fourth_choice);
    if(school_no == fourthchoice[0] )
        app->set_application(indexnumber,first_choice,second_choice,third_choice,fourthchoice);
    if  (school_no == firstchoice[0] || school_no == secondchoice[0]  || school_no == thirdchoice[0]  || school_no == fourthchoice[0] )
            applications.push_back(*(app));



          line ="";
    }
file.close();
            if (applications.empty()==true){

                cout<<"The Application record for this school where not found\n";
            }
            else{
            Student *student = new Student();
            Course *course = new Course();
            Result * result = new Result();

            cout<< "Here are Applications List to your school \n\n";
            cout<<"Student Surname   Index Number      Course Choice             Total score       CutOff Score     Status"<<endl;
            cout<<"============      ===========     =================          =============      ============    =========="<<endl;
            for (auto application : applications){

        if (application.first_choice[0] == school_no){
            student->retrieve(student,application.index_number);
            course->retrieve_course(course,application.first_choice[0],application.first_choice[1]);
            result ->retrieve_result(application.index_number, result);
           Student studentdata = *student;
            Course coursedata = *course;
            Result  resultdata = *result;
            cout<<studentdata.surName<<"         "<<application.index_number<<"      "<<coursedata.course_name
            <<"     "<<resultdata.total_score<<"            "<<coursedata.basescore<<"              "<<show_admission_status(application.first_choice[2])<<endl;

        }

         if (application.second_choice[0]==school_no){
            student->retrieve(student,application.index_number);
            course->retrieve_course(course,application.second_choice[0],application.second_choice[1]);
            result ->retrieve_result(application.index_number, result);
           Student studentdata = *student;
            Course coursedata = *course;
            Result  resultdata = *result;
            cout<<studentdata.surName<<"         "<<application.index_number<<"      "<<coursedata.course_name
            <<"     "<<resultdata.total_score<<"            "<<coursedata.basescore<<"              "<<show_admission_status(application.second_choice[2])<<endl;

        }

         if (application.third_choice[0] == school_no){
            student->retrieve(student,application.index_number);
            course->retrieve_course(course,application.third_choice[0],application.third_choice[1]);
            result ->retrieve_result(application.index_number, result);
           Student studentdata = *student;
            Course coursedata = *course;
            Result  resultdata = *result;
            cout<<studentdata.surName<<"         "<<application.index_number<<"      "<<coursedata.course_name
            <<"     "<<resultdata.total_score<<"            "<<coursedata.basescore<<"              "<<show_admission_status(application.third_choice[2])<<endl;

        }

          if (application.fourth_choice[0] == school_no){
            student->retrieve(student,application.index_number);
            course->retrieve_course(course,application.fourth_choice[0],application.fourth_choice[1]);
            result ->retrieve_result(application.index_number, result);
           Student studentdata = *student;
            Course coursedata = *course;
            Result  resultdata = *result;
            cout<<studentdata.surName<<"         "<<application.index_number<<"      "<<coursedata.course_name
            <<"     "<<resultdata.total_score<<"            "<<coursedata.basescore<<"              "<<show_admission_status(application.fourth_choice[2])<<endl;

        }
  }
}

    }


    void update_admission_status(int school_id){

    const string filename = "application.csv";
    const string temp_filename = "app_temp.csv";
    Result *result = new Result();
    Course *course = new Course();

    ifstream infile(filename);
    ofstream outfile(temp_filename);

    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        // Modify the necessary fields here
        //
        int indexnumber = atoi(fields[0].c_str());
        result->retrieve_result(indexnumber,result);
        Result resultdata = *result;

       int first_choice = atoi(fields[1].c_str());
       int first_choice_course = atoi(fields[2].c_str());
       course->retrieve_course(course,first_choice,first_choice_course);
        Course course1 = *course;

        int  second_choice = atoi(fields[4].c_str());
        int  second_choice_course= atoi(fields[5].c_str());
        course->retrieve_course(course,second_choice,second_choice_course);
        Course course2 = *course;

        int third_choice = atoi(fields[7].c_str()) ;
        int third_choice_course = atoi(fields[8].c_str()) ;
        course->retrieve_course(course,third_choice,third_choice_course);
        Course course3 = *course;

        int  fourth_choice=atoi(fields[10].c_str());
        int  fourth_choice_course=atoi(fields[11].c_str());
        course->retrieve_course(course,fourth_choice,first_choice_course);
        Course course4 = *course;

        //First choice check

        if( resultdata.total_score >= course1.basescore && first_choice == school_id)
            fields[3] = "1";
        //Second choice check
         if( resultdata.total_score >= course2.basescore && second_choice== school_id)
            fields[6] = "1";
        //Third Choice Check
         if(resultdata.total_score >= course3.basescore && third_choice== school_id)
            fields[9] = "1";
         //Fourth Choice Check
         if(resultdata.total_score >= course4.basescore && fourth_choice == school_id)
            fields[12] = "1";

        // Write the updated line to the temporary file
        copy(fields.begin(), fields.end(),
                  std::ostream_iterator<string>(outfile, ","));
        outfile.seekp(-1, ios_base::cur);  // remove the extra comma
        outfile << "\n";
    }

    infile.close();
    outfile.close();

    // Replace the original file with the updated file
    
    remove(filename.c_str());
    rename(temp_filename.c_str(), filename.c_str());

cout<<"The Quallified Applicants have beeen admitted(All qualified applicants per the cut off scores wiill be admitted)\n";
Application*app = new Application();
view_applications(school_id,app);


    }
};

#endif // APPLICATION_H_INCLUDED
