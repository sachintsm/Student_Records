#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

void openFile();
void subject();
void student();
void disSubSummary();
void save();

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;

int main(){
    int option;

    //openFile();

    cout << "Hello Friend, Choose your option !!!" << endl;
        do{
            cout<<"\t 1. Display Subject\n\t 2. Display Student\n\t 3. Display Subject Summary\n\t 4. Save Summaries\n\t 5. Exit Program" << endl;
            cin >> option;
            switch(option){
                case 1:
                    subject();
                    break;
                case 2:
                    student();
                    break;
                case 3:
                    disSubSummary();
                    break;
                case 4:
                    save();
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
void openFile(){
    const int size = 20 ;
    int stuArray[size];
    int count = 0;

    ifstream stuFile;
    stuFile.open("test.txt");
    if(stuFile.is_open()){
        for(int count=0; count<size; count++){
            stuFile >> stuArray[count];
        }
        stuFile.close();

        for(count =0; count<size; count++){
            cout << stuArray[count] << "\n";
            count = count+1;
        }
    }
    else{
        cout << "Your file is not open successfully"<< endl;
        exit(1);
    }
}
void subject(){

}
void student(){

}
void disSubSummary(){

}
void save(){
    ofstream outFile;
    outFile.open("outTest.txt");

    outFile << "I am sachin" << endl;

    outFile.close();
}