#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

int main(){ 
    const int MAXSUBJECTS = 10;
    const int MAXSTUDENTS = 100;
    int index;
    int marks;
    int stu_count;
    string sub;
    const int size = 20 ;

    char subjects_A[MAXSUBJECTS][50];
    char students_A[MAXSTUDENTS][50];
    int i;
    int count = 0;
    cout << "file is open"<<endl;

    ifstream stuFile;
    stuFile.open("test.txt");
    
    while(stuFile >> subjects_A[i] >> students_A[i])
    {
        i++;
    }
    for(int j =0; j<i; j++){
        cout << subjects_A[j] << "\t" << students_A[j] << endl;
    }
}