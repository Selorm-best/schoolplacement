  #include <string>

  #include <iostream>
  #include <conio.h>


#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "student.h"
#include "school.h"
#include "result.h"
#include "application.h"
    using namespace std;
   class Welcome {
            private: 
            char response;
            int school_number;
            string password;
            char verify;
            char courseResponse;
            int index_number;
            char choice;




            public: 
            Welcome(){
              cout<<"\n\n"<<endl;
               cout<<"\t\t\t||-------------------------------------------------------------------------------------------||"<<endl;
                cout<<"\t\t\t\t\tWelcome to the School Management System\n\n \t\t\t\tAre you a  SCHOOL ADMINISTRATOR( y ) || STUDENT( n ) ?  y / n "<<endl;
              cout<<"\t\t\t||--------------------------------------------------------------------------------------------||"<<endl;
                this->response = getch();
         
            // requireEnter();

            checkResponse(&response);
            }

            void checkResponse(char* response);
            void contentSchoolAdmin();
            void userSection();
            void requireEnter();
            void verifyResponse();
            void restart();
            void continueCourse();
            void createNewCourse();
            void viewCourse();
            void updateCourse();
            void deleteCourse();
            void continueSchoolProfile();
            void continueAdmissionFeature();
            void continueUserSection();
            void moreApplicationFeatures();
            void verifyStudent();
   
   
            }; // End of the class




  void Welcome::requireEnter()
            {
                cout << "Click Enter to continue... " << endl;
                while(getch() != 13);
            }

// check reponse method
            void Welcome::checkResponse(char* response){
            if(*response == 'y'){


            system("cls");

            this->verifyResponse();


            }else{
                *response == 'n'; //You can clean it.
            cout<<"Welcome to the user section"<<endl;
         
            this->userSection();

            }

            }

void Welcome::userSection(){
system("cls");
 cout<<" --- PLEASE CHECK THE STUDENT.CSV FILE TO FIND CREDENTIALS YOU CAN TEST  ---- "<<endl;   
cout<<"Enter your index number ";cin>>this->index_number;
cout<<"Enter your password ";cin>>this->password;


this->verifyStudent();



}

void Welcome::verifyStudent(){
Student* currentStudent = new Student;
bool value  = currentStudent->verify_student(this->index_number, this->password,currentStudent);
 if(value){
 
system("cls");
 cout<<"Welcome to the Student Dashboard"<<endl;
 cout<<"1. My Result"<<endl;
 cout<<"2. Application features"<<endl;
//  cout<<"3. School selection Info"<<endl;
 this->choice = getch();
 this->continueUserSection();



 }else {
  system("cls");
   cout<<"Wrong student index number or password "<<endl;
   this->userSection();
 }

}
void Welcome::continueUserSection(){
 if(choice == '1'){
   system("cls");
   
   Result* studentResult = new Result();
   studentResult->display_result(this->index_number,studentResult);
  


 }else if(choice == '2'){
    this->moreApplicationFeatures();

 }

}

void Welcome::moreApplicationFeatures(){
system("cls");
cout<<"1.View application"<<endl;
cout<<"2.Apply for schools"<<endl;
this->choice = getch();

if(this->choice == '1'){

Application* application = new Application();
application->view_application(this->index_number,application);


}else if (this->choice == '2'){


Application *app= new Application();
app->create_application(this->index_number);

}





}

 void Welcome::verifyResponse(){
            cout<<"To go back to change your response, press 'Esc' or press 'Enter' to continue"<<endl;
            this->verify = getch();
            // while(getch() == 27 || getch() == 13);
            if(this->verify == 27){

            system("cls");
            restart();

            }else if(this->verify == 13){
                cout<<"Okay, Please continue"<<endl;

             if(this->response == 'y'){


   cout<<"||----------------------------------------------------------------------------------------||"<<endl;
  cout<<"\t Test credentials"<<endl;
  cout<<endl;
   cout<< "\t\tschool number/id of 1 is Presec and password is qwerty"<<endl;
   cout<<endl;
   cout<<"\t\tschool number/id of 2 is Mpantsipim and password is asdfg"<<endl;
    cout<<"||----------------------------------------------------------------------------------------||"<<endl;
   cout<<"Please enter credentials , School Number :  " ; cin>>this->school_number;
            cout<<"Enter the password for your School Number : " ; cin>>this->password;


            system("cls");

            // verification would be done later.
            School*schoolrecord = new School();
            bool value = schoolrecord->verify_school(this->school_number,this->password,schoolrecord);
         

           if(value){
            // The user is an admin 

           }else {
            // The user has no account
            cout<<"Wrong school Number or password, Are you sure you don't belong to the student section ?"<<endl;
            this->restart();
           }


  cout<<"\t\t\t\t\t||-------------------------------------------||"<<endl;
            cout<<"\t\t\t\t\tOkay, please choose one of the options you want to go"<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t1.Courses Features"<<endl;
            cout<<"\t\t\t\t\t\t2.School profile  Features"<<endl;
            cout<<"\t\t\t\t\t\t3.Admission  Features"<<endl;
 cout<<"\t\t\t\t\t||---------------------------------------------||"<<endl;           
          this->courseResponse = getch();
                 system("cls");
            switch(this->courseResponse){
                     case '1': 
                    cout<<"Welcome to the course Feature where you would be able to  create, read , update and delete courses "<<endl;          
                      cout<<"1. Create New course"<<endl;
                      cout<<"2. View Course"<<endl;
                   
                   
                      this->choice = getch();
                      this->continueCourse();
                
                    break;
                 case '2': 
                   cout<<"Welcome to the School Profile where you can get the information of your school"<<endl;
                   cout<<"1. View Your School Profile"<<endl;
                   this->choice = getch();



                this->continueSchoolProfile();

                    break;

                   case '3': 
                 cout<<"Welcome to the Admission feature where you can find pending applicants and accepted applicants"<<endl;
                  cout<<"1.View the List of applicants"<<endl;
                  cout<<"2.Verify admission status"<<endl;
                               this->choice = getch();
                        if(  this->choice== '1'  ){
                           this->continueAdmissionFeature();
                         
                        }else if( this->choice == '2'){

                        // function to update the status
                         
                        Application application = Application();
                        application.update_admission_status(this->school_number);
                        }



              
                 
                   
                    break;

                  default: 
                   cout<<"Please try again "<<endl;
                   this->verifyResponse();      

            }




             } // End of the if statement
             else if(this->response == 'n'){

             }
         



            }


            }

void Welcome::continueAdmissionFeature(){

Application* application = new Application();
application->view_applications(this->school_number,application);

cout<<"Please enter esc or enter to exit or continue respectively "<<endl;
this->choice = getch();

            // while(getch() == 27 || getch() == 13);
            if(this->choice == 27){
            this->verifyResponse();
        

            }else if(this->choice == 13){
      system("cls");
            restart();
            }
                



}




void Welcome::continueSchoolProfile(){


      if(this->choice == '1'){
        

School* school = new School();
school->retrieve(school,this->school_number);
cout<<"------------------------------ School profile of "<<school->schoolName<<"---------------"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<< "-----              The name of your school is "<<school->schoolName<<endl;
cout<< "-----              The school id of your school is  "<<school->school_id<<endl;
cout<< "-----              The prefix of the school is  "<<school->schoolPrefix<<endl;
cout<< "-----              The password for the school is   **********"<<endl;
cout<<"--------------------------------------------------------------"<<endl;




cout<<"Please enter esc or enter to exit and continue respectively"<<endl;
cout<<endl;

char wait = getch();


system("cls");
if(wait == 13){
this->restart();

}else if(wait == 27){
this->restart();
}


      }else {
     system("cls");
        this->continueSchoolProfile();
      }



}

void Welcome::continueCourse(){
  if(this->choice == '1'){
        this->createNewCourse();
  }else if(this->choice == '2'){
       this->viewCourse();
  }
}

void Welcome::createNewCourse(){
 
Course* course = new Course();
course->create_course(this->school_number);


   cout<<"Press Esc or enter to exit and continue respectively"<<endl;
   char response = getch();
     if(response == 13){
      system("cls");
  this-> verifyResponse();      
 
     }else if (response == 27){
      system("cls");
           this->verifyResponse();
     }
     {
        /* code */
     }
     
}

void Welcome::viewCourse(){
 
 cout<<"You want to view courses"<<endl;


Course* courseRecord = new Course();
courseRecord->view_courses(courseRecord,this->school_number);
this->verifyResponse();


}


void Welcome::updateCourse(){

cout<<"You want to update the courses"<<endl;





}

void Welcome::deleteCourse(){

cout<<"You want to delete the courses"<<endl;

}

 void Welcome::restart(){
            Welcome welcome;
            }



