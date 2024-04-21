// 5_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
using namespace std;

void printArray(int* numbers, int n) {
    for (int i = 0; i < n; i++) {
        cout << i+1 << ":" << numbers[i] << endl;
    }
}

void mostCommon(int numbers[], int len) {
    int max_value_key = numbers[0];
    int max_value = -1;
    map<int, int> integers;
    for (int i = 0; i < len; i++) {
        integers[numbers[i]]++;
    }
    for (auto& item : integers) {
        cout << item.first << " : " << item.second << endl; //Вывод ключей и значений
    }
}

void arrayUpper(int* numbers, int n){
    int max_value = 0;
    int cur_value = 0;
    int max_len = 0;
    int cur_len = 0;
    for (int i = 0; i < n-1; i++){
        if(numbers[i] < numbers[i+1]) {
            cur_value += numbers[i];
            cur_len++;
        }
        else {
            cur_value += numbers[i];
            cur_len++;
            max_value = cur_value > max_value ? cur_value : max_value;
            max_len = cur_len > max_len ? cur_len : max_len;
            cur_value = 0;
            cur_len = 0;
        }
    }
    cout <<"value:" << max_value << endl;
    cout <<"len:" << max_len << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");



    int n = 30;
    int* numbers{ new int[n] };

    int turn;
    cin >> turn;
    switch (turn) {
    case 1:
        int x;
        double y;
        char c;
        int* pi;
        double* pf;
        char* pc;
        cout << "Введите значения (целое,вещественное,символ): ";
        cin >> x >> y >> c;
        pi = &x;
        pf = &y;
        pc = &c;
        *pi = *pi * 2;
        *pf = *pf * 2;
        *pc = *pc * 2; // может вылезавет за дозваоленную область

        cout << "x=" << *pi << " (" << pi << ")" << endl;
        cout << "y=" << *pf << " (" << pf << ")" << endl;
        cout << "z=" << *pc << " (" << pc << ")" << endl;
        break;
    case 2:
        for (int i = 0; i < n; i++) {
            numbers[i] = rand();
        }
        printArray(numbers, n);
        arrayUpper(numbers, n);
        break;
    
    case 3:
        const int arr_size = 10;
        int array[arr_size];
        for (int i = 0; i < arr_size; i++) {
            array[i] = rand()%10;
        }
        printArray(array, arr_size);
        mostCommon(array, arr_size);
        break;
    }
}


