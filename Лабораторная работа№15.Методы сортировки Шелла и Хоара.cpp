#include <iostream>
using namespace std;

void Vvod(int n,int *mas)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите "<<i<<" элемент: ";
		cin >> mas[i];
	}
}

void Print(int n, int* mas)
{
	for (int i = 1; i <= n; i++)
	{
		cout << mas[i]<<"\t";
	}
	cout << endl;
}

void Shell(int n,int *mas)
{
	int d = n / 2;
	while (d > 0)
	{
		for (int i = 1; i <= n-2*d; i=i+d)
		{
			for (int j = i+d; j >0; j=j - d)
			{
				if (mas[j] < mas[j + d])
				{
					int t = mas[j];
					mas[j] = mas[j + d];
					mas[j + d] = t;
				}
			}
		}
		d = d / 2;
	}
	cout << "Отсортированный массив методом Шелла: ";
	Print(n, mas);
	int f=0;
	for(int i=1;i<=n-1; i++)
	{
		if (mas[i] > mas[i + 1])
			f ++;
		if (f == 3)
			cout << "Третий по величине элемент массива: " << mas[i];
	}
	if (f < 3)
		cout << "Третий по величине элемент массива не найден.";
	cout << endl;
}

void Hoare(int *mas,int left,int right)
{
	int p, i,j;
	p = mas[(right+left) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while ((mas[i] > p)&&(i<right))
			i++;
	    while ((mas[j] < p) && (j > left))
		    j--;
		if (i <= j)
		{
			int t = mas[i];
			mas[i] = mas[j];
			mas[j] = t;
			i++;
			j--;
		}
	}
	if (j>left)
		Hoare(mas, left, j);
	if (i<right)
		Hoare(mas, i, right);
}

int main()
{
	setlocale(0, "");
	system("color F0");
	int n=0;
	while (n <= 0)
	{
		cout << "Введите размер массива: ";
		cin >> n;
	}
	int* mas = new int [n];

	Vvod(n,mas);

	cout << "Начальный массив: ";
	Print(n, mas);

	int sort;
	cout << "1 - Сортировка методом Шелла" << endl;
	cout<< "2 - Сортировка методом Хоара" << endl;
	cin >> sort;
	if (sort == 1)
	{
		cout << "МЕТОД ШЕЛЛА:" << endl;
		Shell(n, mas);
	}
	else 
		if (sort == 2)
		{
			cout << "МЕТОД ХОАРА:" << endl;
			int left = 1;
			int right = n;
			Hoare(mas, left, right);
			cout << "Отсортированный массив методом Хоара: ";
			Print(n, mas);
			int f = 0;
			for (int i = 1; i <= n-1; i++)
			{
				if (mas[i] > mas[i + 1])
					f++;
				if (f == 3)
					cout << "Третий по величине элемент массива: " << mas[i];
			}
			if (f < 3)
				cout << "Третий по величине элемент массива не найден.";
			cout << endl;
		}
		else
		{
			cout << "Введено некорректное значение!!!" << endl;
		}

	return 0;
}
