// lab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;




class Matrix { // Matrix(n)
    private:

    int n;
    double** dinamic_array;

    public:
    Matrix(int n = 3) {
        this->dinamic_array = new double* [n];
        this->n = n;
        for (int i = 0; i < n; i++) {
            this->dinamic_array[i] = new double[n];
            for (int j = 0; j < n; j++){
                cout << "Введите элемент[" << i << "][" << + j <<"]" << endl;
                cin >> this->dinamic_array[i][j];
            }
        }

    }
    Matrix(unsigned int n) {
        this->dinamic_array = new double* [n];
        this->n = n;
        for (int i = 0; i < n; i++) {
            this->dinamic_array[i] = new double[n];
            for (int j = 0; j < n; j++) {
                this->dinamic_array[i][j] = i + j + 1;
            }
        }

    }
    void printElements() {
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++) {
                cout << dinamic_array[i][j] << " ";
            }
            cout << endl;
        }
    }
    void minElement() {
        int min_value = dinamic_array[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                min_value = dinamic_array[i][j] < min_value ? dinamic_array[i][j] : min_value;

            }
        }
        cout << min_value << endl;
    }
    void maxElement() {
        int max_value = dinamic_array[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_value = dinamic_array[i][j] > max_value ? dinamic_array[i][j] : max_value;

            }
        }
        cout << max_value << endl;
    }
    void spur() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dinamic_array[i][i];
        }
        cout <<"Spur:" << sum << endl;
    }
    ~Matrix() {
        for (int i = 0; i < this->n; i++) {
            delete[] dinamic_array[i];
        }

        delete[] dinamic_array;
    } 

};
int main(){
    setlocale(LC_ALL, "RU");
    Matrix first_matrix(2);
    Matrix second_matrix(4u);
    
    first_matrix.printElements();
    second_matrix.printElements();
    second_matrix.maxElement();
    second_matrix.minElement();
    second_matrix.spur();
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
