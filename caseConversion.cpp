#include <iostream>
#include <cstring> // Used to check that the user only inputs one character for the conversion

using namespace std;

int main(){
    cout <<"Please input a character: ";

    bool oneChar = false; // Used to check length of user input, will become true if user only inputs one character 
    char input[100] = {}; // Array to store user input

    while (!oneChar){
        cin >> input;
        int length = strlen(input); // Checks length

        if (length > 1 ){
            // Error message that is outputted if user inputs more than one character, gives opportunity to try again
            cout << "You entered more than one character. Please try again." << endl << "Pleaes enter a character: ";
        } else {
            oneChar = true; 
        }
    }

    char inputChar = input[0]; // Stores the character as a char data type instead of in an array
    int numValue = int(inputChar); // ASCII value of the character
    char newChar; // Variable for the converted character

    if (numValue >= 65 && numValue <= 90){
        // Converts lower case to upper case
        numValue += 32;
        newChar = numValue;
        cout << "The lower case of " << inputChar << " is " << newChar << endl;
    } else if (numValue >= 97 && numValue <= 122){
        // Converts upper case to lower case
        numValue -= 32;
        newChar = numValue;
        cout << "The upper case of " << inputChar << " is " << newChar << endl;
    } else {
        cout << "The input character is " << inputChar;
    }

    return 0;
}
