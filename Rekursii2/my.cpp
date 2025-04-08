#include "my.h"

int Menu() {
	int i;
	system("cls");
	cout << "����.\n1. ���� ������ � ����������.\n2. ���� ������ �� ����� (input.txt).\n3. ������� ������ ����������� ��������.\n4. �������� ���������� � ������� �����.\n5. ����� ����������� � ���� (output.txt).\n6. �����.\n\n������� ����� ����: ";
	while(!(cin >> i) || cin.peek() != '\n') {
		cout << "���� �����������. ���������� ���: ";
		cin.clear();
		cin.ignore(100500, '\n');
	}
	return i;
}

int InputKeyBoard() {
	int i;
	system("cls");
	cout << "������� ����� �� 2 �� 100 ������������: ";
	while (!(cin >> i) || cin.peek() != '\n') {
		cout << "���� �����������. ���������� ���: ";
		cin.clear();
		cin.ignore(100500, '\n');
	}
	return i;
}

int InputFile() {
	string s;
	int i = 2;
	ifstream file;
	file.open("input.txt");
	if (!file) {
		ofstream file2;
		file2.open("input.txt");
		cout << "��������� �� ����� ���� ����� ������, ������� �� ��� ������ ��������������.\n�� ��������� � �� �������� ����� 2.\n";
		file2 << 2;
	} else {
		getline(file, s);
		cout << "�� ����� ���� ��������� ��������� �����: " << s << endl;
	}
	i = stoi(s);
	return i;
}

void OutputFile(double a, int k) {
	ofstream file;
	file.open("output.txt", ios::app);
	file << a << " ��� k = " << k << '\n';
	file.close();
}

double Recursion(int n) {
	static int k = 2;
	static double sum = 0;
	static double a2prew = cos(1) * cos(1);
	static double aprew = sin(1) * sin(1) * (-1);
	double ak = 2 * aprew - a2prew;
	double result;
	if (ak < 2) {
		sum = (ak * ak) + sum;
	}
	a2prew = aprew;
	aprew = ak;

	k++;

	if (k <= n) {
		result = Recursion(n);
	} else {
		result = sum;
		sum = 0;
		a2prew = cos(1) * cos(1);
		aprew = sin(1) * sin(1) * (-1);
		k = 2;
	}

	return result;
}
double Check(int n) {
	int k = 2;
	double sum = 0;
	double a[100];
	a[0] = cos(1) * cos(1);
	a[1] = sin(1) * sin(1) * (-1);
	while (k <= n) {
		a[k] = 2 * a[k - 1] - a[k - 2];
		if (a[k] < 2)
			sum = a[k] * a[k] + sum;
		k++;
	}
	return sum;
}