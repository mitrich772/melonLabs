// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "func.h"
#include <iostream>
using namespace std;
int main(){
    int choose;
    cout << "1 - min 2-max 3-sigma 4-fibon 5-fibonBine 6-integer_bit" << endl;
    cin >> choose;
    double a[8]{ 4, 3, 2, 1 ,1.4,-3,6.8,0};
    int b = size(a);
    int fib_start;
    int fib_count;
    switch (choose){
    case 1:
        cout << "Min:" << min(a, b) << endl;
        break;
    case 2:
        cout << "Max:" << max(a, b) << endl;
        break;
    case 3:
        cout << "Sigma:" << sigma(a, b);
        break;
    case 4:
        cout << "start:";
        cin >> fib_start;
        cout << "number:";
        cin >> fib_count;
        fibonacci(fib_start, fib_count);
        break;
    case 5:
        cout << "start:";
        cin >> fib_start;
        cout << "number:";
        cin >> fib_count;
        fibonacciBine(fib_start, fib_count);
        break;
    case 6:
        cin >> fib_start;
        integer_bit(fib_start);
        break;
    default:
        cout << "Opsss" << endl;
        break;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
