#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include<vector>
class Result{

private:
    int index_number;
    int subject_1;
    int subject_2;
    int subject_3;
    int subject_4;
    int subject_5;
    int subject_6;
    int  total_score;

public:
    Result(){}

    void set_result(int index_no,int subject1,int subject2,int subject3,int subject4,int subject5,int subject6,int totalscore){
    index_number = index_no;
    subject_1 =subject1;
    subject_2 = subject2;
    subject_3 = subject3;
    subject_4=subject4;
    subject_5 = subject5;
    subject_6 = subject6;
    total_score = totalscore;
    }
    void compute_totalscore(){

    }

    void display_result(int index_no, Result * studentresult){

    ifstream file;
    file.open("results.csv",ios::out|ios::app);
    vector<Result> results;
    string line="";
    getline(file,line);
    line="";

    while(getline(file,line)){

        int indexnumber;
        int subject1;
        int subject2;
        int subject3;
        int subject4;
        int subject5;
        int subject6;
        int totalscore;
        string tempString ="";
        stringstream inputString(line);
        getline(inputString,tempString,',');
        indexnumber = atoi(tempString.c_str());
        if (indexnumber == index_no){
        getline(inputString,tempString,',');
        subject1=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        subject2=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        subject3=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        subject4=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        subject5=atoi(tempString.c_str());

        getline(inputString,tempString,',');
        subject6=atoi(tempString.c_str());

        totalscore =subject1+subject2+subject3+subject4+subject5+subject6;
        studentresult -> set_result(index_no,subject1,subject2,subject3,subject4,subject5,subject6,totalscore);
    results.push_back(*(studentresult));
        }
        line ="";
    }
for(auto result : results){
    cout<<"Name - "<<result.index_number<<endl;
    cout<<"-----Subject-----               -----Score-----\n";
    cout<<"Subject 1:                        " <<result.subject_1<<endl;
    cout<<"Subject 2:                        " <<result.subject_2<<endl;
    cout<<"Subject 3:                        " <<result.subject_3<<endl;
    cout<<"Subject 4:                        " <<result.subject_4<<endl;
    cout<<"Subject 5:                        " <<result.subject_5<<endl;
    cout<<"Subject 6:                        " <<result.subject_6<<endl;
    cout<<"Total Score:                     " <<result.total_score<<endl;
}
    }


};


#endif // RESULT_H_INCLUDED
