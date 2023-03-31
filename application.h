#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

using namespace std;

class Application{
private:
    int index_number;
    int first_choice_school;
    int first_choice_course;
    int second_choice_school;
    int second_choice_course;
    int third choice_school;
    int third choice_course;
    int fourth_choice_course;

public:
    Application(int index_no,)
                {index_number = index_no; }
    //View All Applications for a School
    view_application(school_id)const{

            cout<< "Here is the application List for ....\n\n";
            cout<<"Student name: "<<student_name<<"("<<index_number<<")"<<endl;
            cout<<"First choice: "<<first_choice<<"-"<<first_course<<endl;
            }
};

#endif // APPLICATION_H_INCLUDED
