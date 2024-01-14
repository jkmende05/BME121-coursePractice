#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <fstream>

using namespace std; 
const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified

// PART 1A: Create the data struct
struct patientInfo {
    int age;
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char sex;
};

void tiebreaker (patientInfo *record, int j); 
void swap (patientInfo *record, int j);

int main() {
    patientInfo record [NUM_PATIENTS];

    // PART 1B: Read the patient record
    ifstream textFile("patientInfo.txt"); 

    for (int i = 0; i < NUM_PATIENTS; i++){
        // Transfer the info from the txt.file to record
        textFile >> record[i].age >> record[i].id >> record[i].firstName >> record[i].lastName >> record[i].sex;  
    }

    // PART 2: Select a primary sorting category from user input
    cout << "Please input a category to sort patient records by." << endl;
    cout << "Options (case sensitive) are Age, ID, First, Last, Sex: ";

    bool validInput = false;

    char input[50] = {}; // Sets max user input to 49 characters + the end character

    // Sets character arrays to each of the possible options to sort buy, lengths are equal to number of characters + one for the end character
    char inputAge[4] = {'A', 'g', 'e'};
    char inputID[3] = {'I', 'D'};
    char inputFirst[6] = {'F', 'i', 'r', 's', 't'};
    char inputLast[5] = {'L', 'a', 's', 't'};
    char inputSex[4] = {'S', 'e', 'x'};

    int caseNum = 0; // Used when sorting the data

    while (!validInput){
        validInput = true;
        cin >> input;

        // Checks to see if user input matches any of the possible options
        if (strcmp(input, inputAge) == 0){
            cout << "Case 1, sorting by Age." << endl << endl;
            caseNum = 1;
        } else if (strcmp(input, inputID) == 0){
            cout << "Case 2, sorting by ID." << endl << endl;
            caseNum = 2;
        } else if (strcmp(input, inputSex) == 0){
            cout << "Case 3, sorting by Sex." << endl << endl;
            caseNum = 3;
        } else if (strcmp(input, inputLast) == 0){      
            cout << "Case 4, sorting by Last Name." << endl << endl;
            caseNum = 4;
        } else if (strcmp(input, inputFirst) == 0){
            cout << "Case 5, sorting by First Name." << endl << endl;
            caseNum = 5;
        } else {
            // If user input doesn't match any of the possible cases, program will ask again
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
            validInput = false;
        }
    }   

    // PART 4/5: Sorting patient records
    for (int i = 0; i < NUM_PATIENTS - 1; i ++){
        for (int j = 0; j < NUM_PATIENTS - i - 1; j++){
            switch (caseNum) {
                case 1:
                    // Bubble sorts by age
                    if (record[j].age > record[j + 1].age) {
                        swap(record, j);
                    } else if (record[j].age == record[j + 1].age) {
                        tiebreaker(record, j);
                    }
                    break;
                case 2:
                    // Bubble sort by ID number
                    if (record[j].id > record[j + 1].id) {
                        swap(record, j);
                    } else if (record[j].id == record[j + 1].id) {
                        tiebreaker(record, j);
                    }
                    break;
                case 3:
                    // Bubble sort by sex alphabetically
                    if (int(record[j].sex) > int(record[j + 1].sex)) {
                        swap(record, j);
                    } else if (int(record[j].sex) == int(record[j + 1].sex)) {
                        tiebreaker(record, j);
                    }
                    break;
                case 4:
                    // Bubble sort last names alphabetically
                    if (strcmp(record[j].lastName, record[j + 1].lastName) > 0) {
                        swap(record, j);
                    } else if (strcmp(record[j].lastName, record[j + 1].lastName) == 0) {
                        tiebreaker(record, j);
                    }
                    break;
                case 5:
                    // Bubble sort by first name
                    tiebreaker(record, j);
                    break;
            }
        }
    }

    // PART 3: Outputting patient records to terminal in tabular form

    // Prints age first, then ID, First Name, Last Name and sex in the proper sorted arrangement
    cout << setw(12) << "Age: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].age;
    }

    cout << endl << setw(12) << "ID: "; // Endl included before ID to print the ID numbers on a different line than the ages
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].id;
    }

    cout << endl << setw(12) << "First Name: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].firstName;
    }

    cout << endl << setw(12) << "Last Name: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].lastName;
    }

    cout << endl << setw(12) << "Sex: ";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << record[i].sex;
    }

    return 0;
}

void tiebreaker (patientInfo *record, int j){
    // Sorts by first name alphabetically
    if (strcmp(record[j].firstName, record[j + 1].firstName) > 0){
        swap(record, j);
    }
}

void swap (patientInfo *record, int j){
    // Function performs the actual swapping part of the bubble sort
    patientInfo temp [1] = {record[j]};

    record[j] = record [j + 1];
    record[j+1] = temp[0];
}
