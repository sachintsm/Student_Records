#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
#include <typeinfo>

using namespace std;

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;

class student{
    private:
        	//function to calculate grade
    public:
        int marks;
        int index; 
        char grade;
        student(int idx,int mrk){
            index = idx;
            marks = mrk;
            calculate();
        }
        char grades();
        char calculate();
        void sub_data_print();
};

class subject{
    private:
        int numA, numB, numC, numD, numF;
        double sumA , sumB , sumC , sumD , sumF;
        student *stuarray[MAXSTUDENTS]; 
    public:

        int stu_count;
        string sub;
        void save();
        void sub_summary();
        void sub_details();
        void stu_data(int);
        subject(string  input[]){
            numA = numB = numC = numD = numF = 0;
            
            string col_1 = input[0].substr(0,7);
            string col_2 = input[0].substr(8,3);
            sub = col_1;
            stu_count = atoi(col_2.c_str());

            for(int i=1; i<=stu_count; i++){
                string col1 = input[i].substr(0,8);
                string col2 = input[i].substr(9,3);
                int index = atoi(col1.c_str());
                int marks = atoi(col2.c_str());
                student *stu = new student(index,marks);

                char temp = stu->calculate();
                if(temp == 'A') numA++;
                else if(temp == 'B') numB++;
                else if(temp == 'C') numC++;
                else if(temp == 'D') numD++;
                else numF++;

                stuarray[i-1]=stu;
            }
        }
};

void subject::save(){
    double sumA = sumB = sumC = sumD = sumF = 0;
    for(int i =0; i<stu_count; i++){
        stuarray[i]->grade;
    }
    sumA = numA/stu_count*100;
    sumB = numB/stu_count*100;
    sumC = numC/stu_count*100;
    sumD = numD/stu_count*100;
    sumF = numF/stu_count*100;

    cout << sub << " A- " <<sumA << " B- "<<sumB << " C- " <<sumC << " D- "<< sumD << " F- "<<sumF << endl;

    ofstream outFile;
    outFile.open("summdata.txt");
    outFile << sub << " A- " <<sumA << " B- "<<sumB << " C- " <<sumC << " D- "<< sumD << " F- "<<sumF << endl;
    outFile.close();


} 

void subject::sub_summary(){
    double average=0,stan_div=0,sum =0,total = 0;
    int num;
    for(int i=0;i<stu_count; i++){
        sum = sum+stuarray[i]->marks;
    }
    average = sum/stu_count;
    for(int i =0; i<stu_count; i++){
        total = total + ((stuarray[i]->marks - average)*(stuarray[i]->marks - average));
    }
    stan_div = sqrt(total/stu_count);

    cout<<"\tAverage is :"<<average << endl;
    cout << "\tStanderd diviation is : " << stan_div << endl;
    cout << "\tNumber of A : " << numA << endl;
    cout << "\tNumber of A : " << numB << endl;
    cout << "\tNumber of A : " << numC << endl;
    cout << "\tNumber of A : " << numD << endl;
    cout << "\tNumber of A : " << numF << endl;
}
void subject::stu_data(int index){
    cout << "SUBJECT\t\tMARKS\tGRADE"<<endl;
    for(int i=0; i<stu_count; i++){
        if(stuarray[i]->index == index){
            cout << sub << "\t" << stuarray[i]-> marks << "\t" << stuarray[i]->grade << endl;
            return;
        }
    }
    cout << sub << " Student is not found" << endl;
}

void student::sub_data_print(){
    cout << index << "|\t  " << marks << "|\t " << calculate() << endl;
}

void subject::sub_details(){
    cout << "INDEX \t\tMARKS \tGRADE"<< endl;
    cout << "-----------------------------" << endl;
    for(int i=0; i < stu_count; i++){
        stuarray[i]->sub_data_print();
    }
}
char student::calculate()
{
	if(marks >= 70) return (grade='A');
    else if(marks >= 55) return (grade = 'B');
    else if(marks >= 40) return (grade = 'C');
    else if(marks >= 30) return (grade = 'D');
    else return (grade = 'F');
}


int main(){
    ifstream stuFile;
    int option,i=0,count = 0,sub_idx=0;
    string array[MAXSTUDENTS * MAXSUBJECTS];
    subject * subarray[MAXSUBJECTS];
    string line;
    

    stuFile.open("subjdata.txt");
    if(stuFile.is_open()){
        while(getline(stuFile,line)){
            array[count++] = line;
        }
        stuFile.close();
    }else cout << "file is not open successfully..\n" << endl;

    while(i<count){
        subarray[sub_idx++] = new subject(&array[i]);
        string col_1 = array[i].substr(0,7);
        string col_2 = array[i].substr(8,3);
        int j = atoi(col_2.c_str());
        i += (j+1);
    }
    string subcode;
    int index; 
    cout << "\nHello Friend, Choose your option !!!" << endl;
      do{
            cout<<"\n\t 1. Display Subject\n\t 2. Display Student\n\t 3. Display Subject Summary\n\t 4. Save Summaries\n\t 5. Exit Program" << endl;
            cin >> option;
            switch(option){
                case 1:
                    
                    cout << "Enter the subject code : " ;
                    cin >> subcode;

                    for(i =0; i<sub_idx; i++){
                        if(subcode == subarray[i]->sub){
                            subarray[i]->sub_details();
                            break;
                        }
                    }
                    if(i >= sub_idx){
                        cout << "Wrong SUBCODE\n";
                    }

                    break;
                case 2:
                    cout << "Enter the index number : ";
                    cin >> index;
                    for(i=0; i<sub_idx; i++){
                        subarray[i]->stu_data(index);
                    }
                    break;
                case 3:
                    cout << "Enter the subject code : ";
                    cin >> subcode;
                    for(i=0; i<sub_idx; i++){
                        if(subcode == subarray[i]->sub){
                            subarray[i]->sub_summary();
                        }
                    }
                    break;
                case 4:
                    for(i=0; i<sub_idx; i++){
                        subarray[i]->save();
                    }
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