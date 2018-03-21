#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <iterator>
using namespace std;

void InsertionSort(int A[], int length)
{
		int key;
		for (int j = 1; j < length; j++)
		{
				key = A[j];
				int i = j - 1;
				for (; (i >= 0 & A[i] > key); i--)
						A[i + 1] = A[i];
				A[i + 1] = key;
		}
}


int B[100];

void Merge(int A[], int b, int m, int e)
{
		int i, j, k;
		for (i = m + 1; i > b; i--)
				B[i - 1] = A[i - 1];
		for (j = m; j < e; j++)
				B[e + m - j] = A[j + 1];
		for (k = b; k <= e; k++)
		{
				if (B[i] > B[j])
						A[k] = B[j--];
				else
						A[k] = B[i++];
		}
}

void MergeSort(int A[], int b, int e)
{
		if (b < e) {
				int m = (b + e) / 2;
				MergeSort(A, b, m);
				MergeSort(A, m + 1, e);
				Merge(A, b, m, e);
		}
		else
				return;
}


#define M 10
int C[M];

void CountSort(int A[], int b, int e)
{
		int i, j;
		for (int j = 0; j < M; j++)
				C[j] = 0;
		for (int i = b; i <= e; i++)
				C[A[i]]++;
		for (j = 1; j < M; j++)
				C[j] += C[j - 1];
		for (int i = e; i >= b; i--)
		{
				B[C[A[i]]] = A[i];
				C[A[i]]--;
		}
		for (i = b; i <= e; i++)
				A[i] = B[i];
}

int Partion(int A[], int b, int e)
{
		int i = b - 1;
		for (int j = b; j < e; j++)
		{
				int v = A[e];
				if (A[j] <= v)
				{
						i++;
						v = A[j];
						A[j] = A[i];
						A[i] = v;
				}
		}
		int v = A[e];
		A[e] = A[i + 1];
		A[i + 1] = v;
		return i + 1;
}

void QuickSort(int A[], int b, int e)
{
		int i;
		if (b < e)
		{
				i = Partion(A, b, e);
				QuickSort(A, b, i - 1);
				QuickSort(A, i + 1, e);
		}
		else
				return;
}

int RandomPartion(int A[], int b, int e)
{
		srand((unsigned)time(NULL));
		int i = rand() % (e - b + 1) + b;
		int v = A[i];
		A[i] = A[e];
		A[e] = v;
		return Partion(A, b, e);
}

void RandomQuickSort(int A[], int b, int e)
{
		int i;
		if (b < e)
		{
				i = RandomPartion(A, b, e);
				RandomQuickSort(A, b, i - 1);
				RandomQuickSort(A, i + 1, e);
		}
		else
				return;
}

int main()
{
		int a[] = { 0,2,5,6,8,11,4,10,2,9,5,13,5,2,12 };
		int b[] = { 0,16,5,9,7,9,6,23,5,9,7,12,6,5,9 };
		int c[] = { 0,1,3,2,6,9,7,4,9,2,3,2,6,4,9,9,5,2,6,2,1,5,4,9,5,3,2,6,5,9 };
		int d[] = { 0,13,26,7,9,78,45,61,37,97,9,5,13,49,56,16,84,46,13,25 };
		int e[] = { 0,13,26,7,9,78,45,61,37,97,9,5,13,49,56,16,84,46,13,25 };

		auto al = end(a) - begin(a);
		auto bl = end(b) - begin(b);
		auto cl = end(c) - begin(c);
		auto dl = end(d) - begin(d);
		auto el = end(e) - begin(e);

		for (int i = 0; i < al; i++)
				cout << a[i] << " ";
		cout << endl;
		for (int i = 0; i < bl; i++)
				cout << b[i] << " ";
		cout << endl;
		for (int i = 0; i < cl; i++)
				cout << c[i] << " ";
		cout << endl;
		for (int i = 0; i < dl; i++)
				cout << d[i] << " ";
		cout << endl;
		for (int i = 0; i < el; i++)
				cout << e[i] << " ";
		cout << endl;

		InsertionSort(a, al);
		MergeSort(b, 0, bl - 1);
		CountSort(c, 0, cl - 1);
		QuickSort(d, 0, dl - 1);
		RandomQuickSort(e, 0, el - 1);

		cout << endl;
		for (int i = 0; i < al; i++)
				cout << a[i] << " ";
		cout << endl;
		for (int i = 0; i < bl; i++)
				cout << b[i] << " ";
		cout << endl;
		for (int i = 0; i < cl; i++)
				cout << c[i] << " ";
		cout << endl;
		for (int i = 0; i < dl; i++)
				cout << d[i] << " ";
		cout << endl;
		for (int i = 0; i < el; i++)
				cout << e[i] << " ";
		cout << endl;

		return 0;
}