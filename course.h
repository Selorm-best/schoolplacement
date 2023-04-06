#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Course{
public:
        int course_id;
        string course_name;
        int school_id;
        int max_enrollment;
        unsigned int basescore;
public:

        void set_course(int cid,string name,int sid, int max_num,int bscore)
                {course_id = cid; course_name = name; school_id = sid; max_enrollment = max_num; basescore=bscore; }
        void create_course(int schoolid){
        fstream fout;
        string coursename;
        int maxenroll;
        int rawscore;


        ifstream inputfile;
        inputfile.open("Courses.csv", ios::out | ios::app);

        string line = "";
        int count =0;
        int coursecode=1000;
       while(getline(inputfile, line,'\n')) {

             count++;
        }
        coursecode+=count;
        inputfile.close();
    fout.open("Courses.csv", ios::out | ios::app);
        cout <<"Kindly enter the following details to create a course for your school\n";
        cout <<"coursename:";
        getline(cin,coursename);
        cout <<"Maximum enrollment:";
        cin>> maxenroll;
        cout <<"Basic raw score:";
        cin>> rawscore;

        fout<<coursecode<<","
                <<coursename<<","
                <<schoolid<<","
                <<maxenroll<<","
                <<rawscore<<",\n";
        fout.close();
        }
//Display all courses offered by a school
    void view_courses(Course *courserecord, int schoolcode){

    vector<Course> courses ;
    ifstream inputfile;
    inputfile.open("Courses.csv");

    string line = "";
    getline(inputfile, line);
    line = "";
    while(getline(inputfile,line)){
        int courseId;
        string coursename;
        int schoolid;
        int maxenroll;
        int basescore;
        string  tempString =" ";
        stringstream inputString(line);

        getline(inputString,tempString,',');
        courseId =atoi(tempString.c_str());

        getline(inputString,coursename,',');

        getline(inputString,tempString,',');

        schoolid =atoi(tempString.c_str());
        if (schoolid == schoolcode){
        getline(inputString,tempString,',');
         maxenroll=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        basescore =atoi(tempString.c_str());

        //After every record of Construct, construct student object and add to vector
        courserecord->set_course(courseId,coursename,schoolid,maxenroll,basescore);
        courses.push_back(*(courserecord));


        line = "";
        }
    }


    for (auto course : courses){
            cout<<"Course Id: "<<course.course_id<<endl;
            cout<<"Name of course: "<<course.course_name<<endl;
            cout<<"Maximum Number of enrollments : "<<course.max_enrollment<<endl;
            cout<<"Cutoff Raw Score: "<<course.basescore<<endl;
            cout<<"\n"<<endl;

        }






    }





//Display a specific course for a specific school
        void view_course(int school_id, int course_id){
             cout<<"Name of course: "<<course_name<<endl;;
            cout<<"Maximum Number of enrollments : "<<max_enrollment<<endl;
            cout<<"The base raw score is: "<<basescore<<endl;
        }


        void retrieve_course(Course*course, int school_id, int coursecode){

    ifstream inputfile;
    inputfile.open("Courses.csv", ios::out | ios::app);
    int schoolcode = 2;
    string line = "";
    getline(inputfile, line);
    line = "";
    while(getline(inputfile,line)){
        int courseId;
        string coursename;
        int schoolid;
        int maxenroll;
        int basescore;
        string  tempString =" ";
        stringstream inputString(line);

        getline(inputString,tempString,',');
        courseId =atoi(tempString.c_str());

        getline(inputString,coursename,',');

        getline(inputString,tempString,',');

        schoolid =atoi(tempString.c_str());
        if (schoolid == school_id && coursecode == courseId){
        getline(inputString,tempString,',');
         maxenroll=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        basescore =atoi(tempString.c_str());

        //After every record of Construct, construct student object and add to vector
        course->set_course(courseId,coursename,schoolid,maxenroll,basescore);



        line = "";
        }
    }

        }
private:
         delete_course(int course_id){

        }
        update_course(int course_id,int option, string newvalue){

        }

};

#endif // COURSE_H_INCLUDED
