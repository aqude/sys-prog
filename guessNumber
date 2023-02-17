#include <iostream>

using namespace std;

//int Random(int min, int max) {
//    return min + rand() % (max - min);
//}
int Random(int max) {
    return rand() % max;
}

int main() {
    int inputResult;
    int max;
    cout << "Write ur range" << endl;
    cin >> max;
    int randRes = Random(max);
    cout << "guess the number" << endl;
    do {
        cin >> inputResult;

        if (inputResult == randRes) {
            break;
        }

        if (inputResult > randRes) {
            cout << "guess number <" << endl;
        } else {
            cout << "guess number >" << endl;
        }
    } while (inputResult != randRes);
    cout << "Wow, good! " << endl;
    cout << "Your guess number is a " << randRes << endl;
}
