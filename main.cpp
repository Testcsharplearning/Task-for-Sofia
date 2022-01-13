#include <iostream>
#include <stdio.h>
using namespace std;

unsigned int left_shift(unsigned int n) {
	unsigned int i, bit;
	for (i = 0; i < 2; i++) {
		bit = n & 0x8000 ? 1 : 0;
		n <<= 1;
		n |= bit;
	}
	return n;
}

unsigned int right_shift(unsigned int n) {
	unsigned int i, bit;
	for (i = 0; i < 2; i++) {
		bit = n & 0x0001;
		n >>= 1;
		n |= bit << 15;
	}
	return n;
}

void generation(unsigned int R0, int count, int range) {

	for (int i = 0; i < count; ++i) {
		unsigned int R0_1 = left_shift(R0);
		unsigned int R0_2 = right_shift(R0);

		unsigned int R1 = R0_1 + R0_2;

		R0 = R1 % range;

		cout << R0 << endl;
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	unsigned int R0;
	int count;
	int range;

	cout << "Генератор псевдослучайных чисел по методу перемешивания" << endl;
	cout << "Введите начальное число: ";
	cin >> R0;
	cout << "Ведите длину ряда сгенерированых чисел: ";
	cin >> count;
	cout << "Введите максимально сгенерированое значение: ";
	cin >> range;
	cout << "Сгенерированый ряд: " << endl;


	generation(R0, count, range);
	
	return 0;
}