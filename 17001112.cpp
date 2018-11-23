#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;

class student{
    public:
        //student();
        void openFile();
        void subject();
        void stu_data();
        void disSubSummary();
        void save();
    private:
        int index;
        int marks;
        int stu_count;
        string sub;
    protected:

};
int main(){
    int option;
    student stu;
    stu.openFile();

    cout << "Hello Friend, Choose your option !!!" << endl;
        do{
            cout<<"\t 1. Display Subject\n\t 2. Display Student\n\t 3. Display Subject Summary\n\t 4. Save Summaries\n\t 5. Exit Program" << endl;
            cin >> option;
            switch(option){
                case 1:
                    stu.subject();
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
    int subjects_A[MAXSUBJECTS];
    int students_A[MAXSTUDENTS];
    int i;
    int count = 0;
    cout << "file is open"<<endl;

    ifstream stuFile;
    stuFile.open("test.txt");
    
    if(stuFile.is_open()){
        while(stuFile >> subjects_A[i]){
            while(stuFile >> students_A[i]){
                i++;
            } 
        }
        for(int j =0; j<size ; j++){
            cout << subjects_A[j] << "\n";
        }
        //     stuFile >> stuArray[count];
        //     count++;            
        // }
        // while(stuArray[count] >> index >> marks){
        //     cout << index << ' ' << marks ;
        // }
        }
    else{
        cout << "Your file is not open successfully"<< endl;
        exit(1);
    }
}
void student::subject(){
    cout<<"Sachin1;"<<endl;
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