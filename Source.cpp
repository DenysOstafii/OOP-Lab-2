#include <iostream>
#include <cmath>
#define N 3
using namespace std;

class triangle
{
private:

	int* M;

public:

	triangle(int a, int b, int c)
	{
		M = new int[N];
		M[0] = a;
		M[1] = b;
		M[2] = c;
		cout << "Викликався конструктор\n";
	}
	triangle(const triangle &obj) //конструктор копіювання
	{
		M = new int [N];
		for (int i = 0; i < N; ++i)
			M[i] = obj.M[i];
		cout << "Викликався конструктор копіювання\n";
	}

	int SetA(int* M) { M[0] = this->M[0]; }
	int SetB(int* M) { M[1] = this->M[1]; }
	int SetC(int* M) { M[2] = this->M[2]; }

	int GetA() { return M[0]; }
	int GetB() { return M[1]; }
	int GetC() { return M[2]; }

	~triangle()
	{
		delete[]M;
		cout << "\nВикликався деструктор";
	}

	int Per(int a, int b, int c)
	{
		return (a + b + c);
	}

	double Square(int a, int b, int c)
	{
		int p;
		double s;

		p = a + b + c;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}

	void Sin_Tr(double a, double b, double c)
	{
		double cosa, cosb, cosc;
		cosa = (a * a - b * b - c * c)/(-2 * b * c);
		cosb = (b * b - a * a - c * c) / (-2 * a * c);
		cosc = (c * c - a * a - b * b) / (-2 * a * b);
		cout << "\n Кут між сторонами a та b : arccos " << cosa << "\n Mіж сторонами b та c : arccos " << cosb << "\n Mіж сторонами a та c : arccos " << cosc;
	}

};

int main()
{
	system("chcp 1251");
	int a, b, c;
	cout << "Input 1st side : ";
	cin >> a;
	cout << "Input 2nd side : ";
	cin >> b;
	cout << "Input 3rd side : ";
	cin >> c;
	if ((a + b) < c || (b + c) < a || (a + c) < b)
	{
		cout << "Error";
		return 0;
	}
	triangle tr(a, b, c);
	triangle obj(tr);
	cout << " Периметр трикутника : " << obj.Per(a, b, c) << " \n Площа трикутника :" << obj.Square(a, b, c);
	obj.Sin_Tr(a, b, c);
	return 0;
}