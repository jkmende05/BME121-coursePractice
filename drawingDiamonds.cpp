#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    if (cin.fail() || size <= 1 || size%2 == 0)
        return -1;

    int midpoint = (size+1)/2;

    for (int L = 1; L <= size; L++) {
        if (L == 1 || L == size){
            for (int i = 1; i < midpoint; i++){
                cout << " ";
            }

            cout << "*";
        } else if (L < midpoint){
            for (int i = 1; i < size; i++){
                if (i == midpoint - L + 1 || i == midpoint + L -1)
                    cout << "*";
                else if (i == midpoint)
                    cout << "+";
                else 
                    cout << " ";
            }
        } else if (L == midpoint){
            for (int i = 1; i <= size; i++){
                if (i == 1 || i == size)
                    cout << "*";
                else 
                    cout << "+";
            }
        } else {
            for (int i = 1; i < size; i++){
                if (i == L - midpoint + 1 || i == size - (L - midpoint))
                    cout << "*";
                else if (i == midpoint)
                    cout << "+";
                else 
                    cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
