#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

enum Status {Incomplete, Fail, Pass};

struct student {
    char name[20];
    int id;
    float gpa;
};

int main(){
  // Program to automatically calculate if a student passes or fails a class
    ifstream input("StudentMarks.txt");

    student ClassList [5];
    for (int i = 0; i < 5; i++){
        input >> ClassList[i].name >> ClassList[i].id >> ClassList[i].gpa;
        
    }

    for (int i = 0; i < 5; i++){
        cout << ClassList[i].name << endl;
        if (ClassList[i].gpa >= 2){
            Status Student = Pass;
            cout << "Status: " << Student << endl;;
        } else if (ClassList[i].gpa < 2 && ClassList[i].gpa >= 1){
            Status Student = Fail;
            cout << "Status: " << Student << endl;
        } else {
            Status Student = Incomplete;
            cout << "Status: " << Student << endl;
        }

    }

    input.close();
    return 0;

}
