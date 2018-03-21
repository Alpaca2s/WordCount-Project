#include <iostream>

using namespace std;

#define N 5
#define M 100

int w[N][N]{
		{ 0 ,3 ,8 ,M ,-4 },
		{ M ,0 ,M ,1 ,7 },
		{ M ,4 ,0 ,M ,M },
		{ 2 ,M ,-5,0 ,M },
		{ M ,M ,M ,6 ,0 }
};
int tL[N][N]{
		{ 0 ,3 ,8 ,M ,-4 },
		{ M ,0 ,M ,1 ,7 },
		{ M ,4 ,0 ,M ,M },
		{ 2 ,M ,-5,0 ,M },
		{ M ,M ,M ,6 ,0 }
};
int nL[N][N]{
		{ 0 ,3 ,8 ,M ,-4 },
		{ M ,0 ,M ,1 ,7 },
		{ M ,4 ,0 ,M ,M },
		{ 2 ,M ,-5,0 ,M },
		{ M ,M ,M ,6 ,0 }
};
int(*thisL)[N] = tL;
int(*nextL)[N] = nL;
int(*pL)[N] = w;
int(*thisD)[N] = tL;
int(*nextD)[N] = nL;
int(*pD)[N] = w;

int Add(const int a, const int b)
{
		if ((a == M) | (b == M))
				return M;
		else
				return a + b;
}

void Extend_Shortest_Paths(const int(*thisL)[N], const int(*w)[N], int(*nextL)[N])
{
		for (int i = 0; i<N; i++)
				for (int j = 0; j < N; j++)
				{
						nextL[i][j] = M;
						for (int k = 0; k < N; k++)
								if (nextL[i][j] > Add(thisL[i][k], w[k][j]))
										nextL[i][j] = Add(thisL[i][k], w[k][j]);
				}
}

void Show_All_Pairs_Shortest_Paths()
{
		for (int m = 2; m < N; m++)
		{
				Extend_Shortest_Paths(thisL, w, nextL);
				pL = nextL;
				nextL = thisL;
				thisL = pL;
		}
}

void Faster_All_Pairs_Shortest_Paths()
{
		for (int m = 1; m < N - 1; m = 2 * m)
		{
				Extend_Shortest_Paths(thisL, thisL, nextL);
				pL = nextL;
				nextL = thisL;
				thisL = pL;
		}
}

void Floyd_Warshall()
{
		for (int k = 0; k < N; k++)
		{
				for (int i = 0; i < N; i++)
						for (int j = 0; j < N; j++)
								if (thisD[i][j] > Add(thisD[i][k], thisD[k][j]))
										nextD[i][j] = Add(thisD[i][k], thisD[k][j]);
								else
										nextD[i][j] = thisD[i][j];
				pD = nextD;
				nextD = thisD;
				thisD = pD;
		}
		pL = pD;
}

#define NIL N
int tP[N][N]{
		{ NIL,0  ,0  ,NIL,0 },
		{ NIL,NIL,NIL,1  ,1 },
		{ NIL,2  ,NIL,NIL,NIL },
		{ 3  ,NIL,3  ,NIL,NIL },
		{ NIL,NIL,NIL,4  ,NIL }
};
int nP[N][N]{
		{ NIL,0  ,0  ,NIL,0 },
		{ NIL,NIL,NIL,1  ,1 },
		{ NIL,2  ,NIL,NIL,NIL },
		{ 3  ,NIL,3  ,NIL,NIL },
		{ NIL,NIL,NIL,4  ,NIL }
};
int(*thisP)[N] = tP;
int(*nextP)[N] = nP;
int(*pP)[N] = tP;
void Print_All_Pairs_Shortest_Path(const int i, const int j)
{
		if (i == j)
				cout << i + 1;
		else
				if (pP[i][j] == NIL)
						cout << "no shortest path from " << i + 1 << " to " << j + 1 << " exists";
				else
				{
						Print_All_Pairs_Shortest_Path(i, pP[i][j]);
						cout << "--->" << j + 1;
				}
}
void Floyd_Warshall_Plus()
{
		for (int k = 0; k < N; k++)
		{
				for (int i = 0; i < N; i++)
						for (int j = 0; j < N; j++)
								if (thisD[i][j] > Add(thisD[i][k], thisD[k][j]))
								{
										nextD[i][j] = Add(thisD[i][k], thisD[k][j]);
										nextP[i][j] = thisP[k][j];
								}
								else
								{
										nextD[i][j] = thisD[i][j];
										nextP[i][j] = thisP[i][j];
								}
				pD = nextD;
				nextD = thisD;
				thisD = pD;
				pP = nextP;
				nextP = thisP;
				thisP = pP;
		}

		cout << "各点对最短距离" << endl;
		for (int i = 0; i < N; i++)
		{
				for (int j = 0; j < N; j++)
						cout << pD[i][j] << "\t";
				cout << endl;
		}
		cout << endl;

		//for (int i = 0; i < N; i++)
		//{
		//		for (int j = 0; j < N; j++)
		//				if (w[i][j] != M)
		//						cout << w[i][j] << "\t";
		//				else
		//						cout << "∞" << "\t";
		//		cout << endl;
		//}
		//cout << endl;

		//for (int i = 0; i < N; i++)
		//{
		//		for (int j = 0; j < N; j++)
		//				if (pP[i][j] != NIL)
		//						cout << pP[i][j] + 1 << "\t";
		//				else
		//						cout << "NIL" << "\t";
		//		cout << endl;
		//}
		//cout << endl;

		cout << "各点对最短路径" << endl;
		for (int i = 0; i<N; i++)
				for (int j = 0; j < N; j++)
				{
						if (i == j)
								cout << i + 1 << "--->" << j + 1;
						else
								Print_All_Pairs_Shortest_Path(i, j);
						cout << endl;
				}
		cout << endl;
}

int main()
{
		//Show_All_Pairs_Shortest_Paths();
		//Faster_All_Pairs_Shortest_Paths();
		//Floyd_Warshall();
		//for (int i = 0; i < N; i++)
		//{
		//		for (int j = 0; j < N; j++)
		//				cout << pL[i][j] << "\t";
		//		cout << endl;
		//}

		Floyd_Warshall_Plus();
		return 0;
}