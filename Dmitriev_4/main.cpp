#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

class my_exception
{
	string data_;
public:
	my_exception(const char* text)
	{
		data_ = text;
	}

	string& get_error()
	{
		return data_;
	}
};

class Equation
{
	double a, b, c;
public:
	Equation()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	Equation(double a_, double b_, double c_)
	{
		a = a_;
		b = b_;
		c = c_;
	}

	void equation_show()
	{
		cout << "���������: " << a << "x^2 +" << b << "x +" << c << "= 0" << endl;
	}

	double sqrt_discriminant()
	{
		double descriminant = (b * b - 4 * a * c);
		if (descriminant < 0)
		{
			throw my_exception("������! ������������ ��������� �������������!");
		}

		return sqrt(descriminant);
	}

	void solve()
	{
		double sqrtDesc = sqrt_discriminant();
		if (sqrtDesc == 0)
		{
			cout << "�������: " << -b / (2 * a) << endl;
		}
		else
		{
			cout << "������ ������� ���������: " << (-b + sqrtDesc) / (2 * a) << endl;
			cout << "������ ������� ���������: " << (-b - sqrtDesc) / (2 * a) << endl;
		}
	}
};


int main()
{
	double a, b, c;
	setlocale(0, "russian");
	cout << "������� ���������� A: ";
	cin >> a;
	cout << "������� ���������� B: ";
	cin >> b;
	cout << "������� ���������� C: ";
	cin >> c;
	
	Equation equation1(a, b, c);
	equation1.equation_show();
	try
	{
		equation1.solve();
	}
	catch (my_exception& e)
	{
		cout << e.get_error() << endl;
	}

	_getch();
	return 0;
}
