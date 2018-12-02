#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>
#include<map>
#include<stdlib.h>


using namespace std;

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;

class student{
   
    public:
        void openFile();
        void subject(string sub);
        void stu_data();
        void disSubSummary();
        void save();
        char grades(int index, int marks);

    private:
        int index;
        int marks;
        int stu_count;
        string sub;
        string current;
        string array[100];
        int arr[10][100];
        string line;
        
    protected:
};
int main(){
    int option;
    student stu;
    stu.openFile();
    string sub; 
    cout << "Hello Friend, Choose your option !!!" << endl;
        do{
            cout<<"\t 1. Display Subject\n\t 2. Display Student\n\t 3. Display Subject Summary\n\t 4. Save Summaries\n\t 5. Exit Program" << endl;
            cin >> option;
            switch(option){
                case 1:
                    cin >> sub;
                    stu.subject(sub);
                    break;
                case 2:
                    stu.stu_data();
                    break;
                case 3:
                    stu.disSubSummary();
                    break;
                case 4:
                    stu.save();
                    break;
                case 5:
                    return EXIT_FAILURE;
                    break;
                default:
                cout<<"Please, Enter valid option !" << endl;
            }
        }while(option != 5);
    return 0;
}
void student::openFile(){
    const int size = 20 ;
    
    int i,j,k;
    int count = 0;
    cout << "file is open"<<endl;

    ifstream stuFile;
    stuFile.open("subjdata.txt");

    //cout<< marks["Maths", "IT001"] <<endl;

    if(stuFile.is_open()){
       while(!stuFile.eof()){
            getline(stuFile,line);
            string col_1 = line.substr(0,line.find(" "));
            string col_2 = line.substr(col_1.length()+1,line.find(" "));
            
            if(col_1.length()== 7){
                sub = col_1;
                stu_count = atoi(col_2.c_str());
                cout << sub << " " << stu_count << endl;
            }else{
                index = atoi(col_1.c_str());
                marks = atoi(col_2.c_str());
                cout << index << " " << marks << endl;
            }
            i++;     
        }
        stuFile.close();
    }
    else{
        cout << "Your file is not open successfully"<< endl;
        exit(1);
    }
}

void student::subject(string sub){
    
}
void student::stu_data(){

}
void student::disSubSummary(){

}
void student::save(){
    ofstream outFile;
    outFile.open("outTest.txt");
    outFile << "I am sachin" << endl;
    outFile.close();
}

char student::grades(int index, int marks){
    if(marks<100) return('A');
    else if(marks < 70) return ('B');
    else if(marks < 55) return ('C');
    else if(marks < 40) return ('D');
    else return ('F');
}
