#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "student.h"
#include "school.h"
#include "result.h"
#include "application.h"
using namespace std;


int main()
{
    /*
int choice;
cout<<"The HIGH SCHOOL DIGITAL PLACEMENT portal\n";
cout<<"Who are you?"<<endl;
cout<<"1. Student"<<endl;
cout<<"2. High School admin"<<endl;
cin>> choice;
switch (choice){
//Student User features
case 1:
    cout<<"Welcome student !\n";

//School admin user features
case 2:
    break;
default:
    break;


}*/
//Unit tests
//testing display of students
 //Student* studentrecord = new Student();
  //studentrecord->display(studentrecord,3021520);

//testing Student User verification
/*Student *currentstudent = new Student();
cout<<currentstudent ->verify_student(3031520,"123as",currentstudent)<<endl;*/

//testing School user verification
/*School * currentschool = new School();
cout<<currentschool ->verify_school(1,"qwerty",currentschool)<<endl;

// Testing Schools' records display
/*School * schoolrecord = new School();
schoolrecord->display(schoolrecord);*/

//Testing results Display
//Result * studentresult = new Result();

//studentresult->display_result(3021520, studentresult);

// Viewind the Application list of a student
//Application *app= new Application(3021520);
//app->view_application(3021520,app);

    /*
        Testing display of course records

        Course *courserecord = new Course(0,"",0,0,0);
        courserecord->view_courses(courserecord);

        Testing the course create feature
        Course course(0,"",0,0,0);
        course.create_course(2);
        cout<<"School name  id  is "<<courserecord->school_id<<"\n";
        */
return 0;
}
