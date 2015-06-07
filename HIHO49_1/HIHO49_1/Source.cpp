#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct edge
{
	int vertex1;
	int vertex2;
};

bool isVertexAlreadyHave(int* vertex, int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(vertex + i) == x)
			return true;

	}
	return false;

}

int isOdd(int x)
{
	return x - x / 2 * 2;
}
int main()
{
	int n, m;

	//create edges
	cin >> n >> m;
	edge* edges = new edge[m];
	for (int i = 0; i < m; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		edges[i].vertex1 = temp1;
		edges[i].vertex2 = temp2;
	}
	int* vertex = new int[n];
	int size_temp = 0;

	//create vertex
	for (int i = 0; i < m; i++)
	{
		if (size_temp == 0)
		{
			*(vertex + 0) = edges[0].vertex1;
			*(vertex + 1) = edges[0].vertex2;
			size_temp += 2;
		}
		else
		{
			if (!isVertexAlreadyHave(vertex, edges[i].vertex1, size_temp))
			{
				*(vertex + size_temp) = edges[i].vertex1;
				size_temp += 1;
			}
			if (!isVertexAlreadyHave(vertex, edges[i].vertex2, size_temp))
			{
				*(vertex + size_temp) = edges[i].vertex2;
				size_temp += 1;
			}
		}

	}
	
	sort(vertex, vertex + n);
	for (int i = 0; i < n; i++)
	{
		cout << *(vertex + i) << endl;
	}

	//initialize matrix
	int **matrix;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	}

	//fill the matrix
	for (int i = 0; i < m; i++)
	{
		int x = edges[i].vertex1;
		int y = edges[i].vertex2;
		matrix[x - 1][y - 1] = 1;
		matrix[y - 1][x - 1] = 1;
	}

	//print matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

	//check the number of odd-degree vertex
	int odd_degree_vertex = 0;
	for (int i = 0; i < n; i++)
	{
		int degree = 0;
		for (int j = 0; j < n; j++)
			degree += matrix[i][j];
		if (isOdd(degree) == 1)
			odd_degree_vertex += 1;
	}
	 cout << "odd degree vertex number is: " << odd_degree_vertex << endl;

	return 0;

}
