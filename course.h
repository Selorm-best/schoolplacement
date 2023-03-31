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
        Course(int cid,string name,int sid, int max_num,int bscore )
            {course_id = cid; course_name = name; school_id = sid; max_enrollment = max_num; basescore=bscore; }

        set_course(int cid,string name,int sid, int max_num,int bscore)
                {course_id = cid; course_name = name; school_id = sid; max_enrollment = max_num; basescore=bscore; }
        create_course(int schoolid){
        fstream fout;
        string coursename;
        int maxenroll;
        int rawscore;
        fout.open("Courses.csv", ios::out | ios::app);

        cout <<"Kindly enter the following details to create a course for your school\n";
        cout <<"coursename:";
        getline(cin,coursename);
        cout <<"Maximum enrollment:";
        cin>> maxenroll;
        cout <<"Basic raw score:";
        cin>> rawscore;

        fout<<"200"<<","
                <<coursename<<","
                <<schoolid<<","
                <<maxenroll<<","
                <<rawscore<<",\n";
        fout.close();
        }
//Display all courses offered by a school
    view_courses(Course *courserecord){

    vector<Course> courses ;
    ifstream inputfile;
    inputfile.open("Courses.csv");
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
            cout<<"Name of course: "<<course.course_name<<endl;
            cout<<"Maximum Number of enrollments : "<<course.max_enrollment<<endl;
            cout<<"The base raw score is: "<<course.basescore<<endl;
            cout<<"\n"<<endl;

        }



    }




// Display a specific course for all schools
         void view_course(int course_id){
        cout<< course_name<<" Options \n";
        cout<<"School: "<<school_id<<endl;
        cout<<"Maximum Number of Enrollments:"<<max_enrollment<<endl;
        }

//Display a specific course for a specific school
        void view_course(int school_id, int course_id){
             cout<<"Name of course: "<<course_name<<endl;;
            cout<<"Maximum Number of enrollments : "<<max_enrollment<<endl;
            cout<<"The base raw score is: "<<basescore<<endl;
        }
private:
         delete_course(int course_id){

        }
        update_course(int course_id,int option, string newvalue){

        }

};

#endif // COURSE_H_INCLUDED
