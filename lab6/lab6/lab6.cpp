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
        double min_value = dinamic_array[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                min_value = dinamic_array[i][j] < min_value ? dinamic_array[i][j] : min_value;

            }
        }
        cout << min_value << endl;
    }
    void maxElement() {
        double max_value = dinamic_array[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_value = dinamic_array[i][j] > max_value ? dinamic_array[i][j] : max_value;

            }
        }
        cout << max_value << endl;
    }
    double spur() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dinamic_array[i][i];
        }
        return sum;
    }
    void transopanate() {
        double t;
        for (int i = 0; i < n; ++i){
            for (int j = i; j < n; ++j){
                t = dinamic_array[i][j];
                dinamic_array[i][j] = dinamic_array[j][i];
                dinamic_array[j][i] = t;
            }
        }
    }
    void clearMemory(double** a, int n) { //Функция освобождения памяти, выделенной под двумерный динамический массив
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    int findDet() { //Рекурсивная функция вычисления определителя матрицы
        if (n == 1)
            return dinamic_array[0][0];
        else if (n == 2)
            return dinamic_array[0][0] * dinamic_array[1][1] - dinamic_array[0][1] * dinamic_array[1][0];
        else {
            double d = 0;
            for (int k = 0; k < n; k++) {
                double** m = new double* [n - 1];
                for (int i = 0; i < n - 1; i++) {
                    m[i] = new double[n - 1];
                }
                for (int i = 1; i < n; i++) {
                    int t = 0;
                    for (int j = 0; j < n; j++) {
                        if (j == k)
                            continue;
                        m[i - 1][t] = dinamic_array[i][j];
                        t++;
                    }
                }
                d += pow(-1, k + 2) * dinamic_array[0][k] * findMinor(m, n - 1);
                clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
            }
            return d; //Возвращаем определитель матрицы
        }
    }

    double findMinor(double** dinamic_array, int n) { // функция вычисления минора
        if (n == 1)
            return dinamic_array[0][0];
        else if (n == 2)
            return dinamic_array[0][0] * dinamic_array[1][1] - dinamic_array[0][1] * dinamic_array[1][0];
        else {
            double d = 0;
            for (int k = 0; k < n; k++) {
                double** m = new double* [n - 1];
                for (int i = 0; i < n - 1; i++) {
                    m[i] = new double[n - 1];
                }
                for (int i = 1; i < n; i++) {
                    int t = 0;
                    for (int j = 0; j < n; j++) {
                        continue; //пропускаем
                        m[i - 1][t] = dinamic_array[i][j];
                        t++;
                    }
                }
                d += pow(-1, k + 2) * dinamic_array[0][k] * findMinor(m, n - 1);
                clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
            }
            return d; //Возвращаем определитель матрицы
        }
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
    Matrix first_matrix(3);
    Matrix second_matrix(4u);
    
    first_matrix.printElements();
    second_matrix.printElements();
    second_matrix.maxElement();
    second_matrix.minElement();
    cout<<second_matrix.spur()<<endl;
    first_matrix.transopanate();
    first_matrix.printElements();
    cout << first_matrix.findDet() << endl;
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
