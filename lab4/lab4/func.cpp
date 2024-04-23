#include<array>
#include <iostream>
double min(double all[], int len) {
	using namespace std;
	int min = all[0];
	for (int i = 0; i < len; i++) {
		//cout << min;
		if (min > all[i]) {
			min = all[i];
		}
	}
	return min;
}

double max(double all[], int len) {
	double max = all[0];
	for (int i = 0; i < len; i++) {
		if (max < all[i]) {
			max = all[i];
		}
	}
	return max;

}
double sigma(double all[], int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += all[i];
	}
	double sr = sum / len;
	double sr_ra = 0;
	for (int i = 0; i < len; i++) {
		sr_ra += abs(sr - all[i]) * abs(sr - all[i]);
	}
	return sr_ra / len;
}
void fibonacci(int n_start, int n_count) { // криво работает допилить или позориться :D
	using namespace std;
	int fib_pre_pre = 1;
	int fib_pre = 1;
	int fib_new = 1;
	for (int i = 0; i < n_start + n_count; i++) {
		if (i < 2) {
			cout << 1 << endl;
		}
		else{
			fib_new = fib_pre_pre + fib_pre;
			fib_pre_pre = fib_pre;
			fib_pre = fib_new;
		}
		if (i >= n_start) {
			cout << fib_new << endl;
		}
	}
}

void fibonacciBine(int n_start, int n_count) {
	double fi = (1 + sqrt(5)) / 2;
	double res;
	for (int i = n_start; i < n_start + n_count; i++) {
		res = round((pow(fi, i) - pow(-fi, -i)) / (2 * fi - 1));
		std::cout << res << std::endl;

	}
}

void integer_bit(int num) {
	using namespace std;
	int t = 0, d = 1;
	while (num){
		t += (num % 2) * d;

		num /= 2;

		d = d * 10;
	}
	cout << t;
	cout << endl;
}