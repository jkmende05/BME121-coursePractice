#include <iostream>

using namespace std;

int fibonacci (int n) {
    int total = 1;

    int prev = 0;

    if (n == 1){
        total = 1;
    } else {
        for (int i = 2; i <= n; i++){
            int temp = total;
            total = temp + prev;
            prev = temp;

        }
    }

    return total;
}

int main(){
    int x;
    cin >> x;

    cout << fibonacci(x);

    return 0;
}
