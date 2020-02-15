#include <iostream>

using namespace std;


int ** init_matrix(int**matrix, int size_of_matrix);
void printMatrix(int **matrix, int size_of_matrix);
int** spiral(int**matrix, int size_of_matrix);

int main()
{
	int size_of_matrix;
	cout<<"vvedite 4islo"<<endl;
	cin>>size_of_matrix;
	
	int **matrix = NULL;
	matrix = init_matrix(matrix, size_of_matrix);
	spiral(matrix, size_of_matrix);
	
	
	
	system("pause");
	return 0;
}

int ** init_matrix(int**matrix, int size_of_matrix)
{
	matrix = new int *[size_of_matrix];
	for(int i = 0;i<size_of_matrix;i++)
	{
		matrix[i] = new int[size_of_matrix];
		for(int j = 0;j<size_of_matrix;j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void printMatrix(int **matrix, int size_of_matrix)
{
	for(int i = 0;i<size_of_matrix; i++)
	{
		for(int j = 0;j<size_of_matrix;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}


int **spiral(int**matrix, int size_of_matrix)
{
	int value = 1;
	int cur_str = 0;
	int cur_cul = 0;
	for(int border = 0;value < size_of_matrix*size_of_matrix;border++)
	{
		cur_str = border;
		cur_cul = border;
		for(;cur_cul<size_of_matrix - border; cur_cul++)
		{
			matrix[cur_str][cur_cul] = value++;
		}
		for(cur_cul--, value -- ;cur_str<size_of_matrix - border; cur_str++)
		{
			matrix[cur_str][cur_cul] = value++;
		}
		for(cur_cul--, cur_str--;cur_cul>=border; cur_cul--)
		{
			matrix[cur_str][cur_cul] = value++;
		}
		for(cur_cul++, cur_str--;cur_str>border; cur_str--)
		{
			matrix[cur_str][cur_cul] = value++;
		}
		printMatrix(matrix, size_of_matrix);
		cout<<endl;
	}	
	return matrix;
}
