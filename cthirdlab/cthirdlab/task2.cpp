#include <iostream>
using namespace std;
float findToNumber(int n) {
	double res = 1;
	for (int i = 0; i < n;i++){
		res += 1 / (i * (i + 1));
	}
	return res;
}




int main(){ // 14 вариант телескоп :)
	int n;
	cout << "¬ведите до какого члена р€да считать" << endl;
	cin >> n;
	double b = n >= 0 ? findToNumber(n) : 0;
	cout << b;


}