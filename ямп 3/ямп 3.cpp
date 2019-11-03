// ямп 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
////для решения используем кольцевой список.
struct pers {
	int pred;
	int sled;
};
pers A[10000];

int main()
{

	int N, M, L;

	cin >> N >> M >> L;
	//заполняем структуру
	for (int i = 1; i <= N; i++)
	{
		A[i].pred = i - 1;
		if (A[i].pred == 0)
			A[i].pred = N;
		A[i].sled = i + 1;
		if (A[i].sled == N + 1)
			A[i].sled = 1;

	}
	cout << endl;
	int ost = 1; //начинаем считать с первого

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++)//считалка
			ost = A[ost].sled;
		cout << ost;
		A[A[ost].pred].sled = A[ost].sled;
		A[A[ost].sled].pred = A[ost].pred;
		ost = A[ost].sled;
	}

	cout << ost <<endl;

	int beg = L - ost + 1;

	if (beg <= 0)
		beg = beg + N;

	cout << beg;

	return 0;
}