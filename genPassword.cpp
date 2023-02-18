#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

string randomNumbers(int range) {
    char arr[range];
    string arrNumbers;
    for (int i = 0; i < range; i++) {
        int numbers = arr[i] = rand() % 10;
        arr[i] = numbers;
        // конвертация для join str
        arrNumbers += to_string(numbers);
    }

    return arrNumbers;
}

string randomLetters(int range) {
    char arr[range];
    string arrLetters;
    // Создание генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // Создание распределения, которое генерирует случайные целые числа от 0 до 25
    std::uniform_int_distribution<> dis(0, 25);

    // Генерация случайной буквы
    for (int i = 0; i < range; i++) {
        char letter = 'a' + dis(gen);
        arr[i] = letter;
        arrLetters += letter;
    }

    return arr;
}

string shuffleMergeStrings(const string& str) {
    string shuffled = str;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(shuffled.begin(), shuffled.end(), default_random_engine(seed));
    return shuffled;
}
string mergeStrings(const string& str1, const string& str2) {
    string merged = str1 + str2;
    return merged;
}

string randomFull( string (*funcLetters)(int), string (*funcNumbers)(int), int range ) {
    string letters = funcLetters(range);
    string numbers = funcNumbers(range);
    string MergedString = mergeStrings(letters, numbers);
    string ShuffleMergeStrings = shuffleMergeStrings(MergedString);
    return ShuffleMergeStrings;
}

int main() {
    int rangePassword;
    bool lettersCheck, numbersCheck;

    cout << "Генератор пароля" << endl;
    cout << "================" << endl;

    cout << "Введите длину пароля (default range 10)" << endl;
    cin >> rangePassword;
    cout << "1 - letters, 2 - numbers, 3 - L+N" << endl;
    int inputMethod;
    cin >> inputMethod;
    switch (inputMethod) {
        case 1:
            cout << randomLetters(rangePassword) << endl;
            break;
        case 2:
            cout << randomNumbers(rangePassword) << endl;
            break;
        case 3:
            cout << randomFull( &randomLetters, &randomNumbers, rangePassword) << endl;
            break;
    }
    return 0;
}
