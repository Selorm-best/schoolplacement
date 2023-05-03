
// some header files
#include "welcome.h"  
using namespace std;




int main()
{
    

}*/
   /* vector<Student> students ;
    ifstream inputfile;
    inputfile.open("C:\\temp\\Students.csv");

    string line = "";
    getline(inputfile, line);
    line = "";
    while(getline(inputfile,line)){
        int indexNumber;
        string surname;
        string firstname;
        string  tempString =" ";
        stringstream inputString(line);

        getline(inputString,surname,',');
        getline(inputString,firstname,',');
        getline(inputString,tempString,',');
        indexNumber =atoi(tempString.c_str());
        //After every record of students, construct student object and add to vector
        Student studentrecord(surname,firstname,indexNumber);
        students.push_back(studentrecord);


        line = "";
    }
    for (auto student : students){
            student.display();

        }
*/

        Course *courserecord = new Course(0,"",0,0,0);
        courserecord->view_courses(courserecord);

        Course course(0,"",0,0,0);
        course.create_course(2);
        cout<<"School name  id  is "<<courserecord->school_id<<"\n";

return 0;
}

