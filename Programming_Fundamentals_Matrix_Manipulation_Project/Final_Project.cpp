#include<iostream>
#include<fstream>
using namespace std;
void read(ifstream& myfile, int** ptr, int r, int c) // to read from file
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			myfile >> ptr[i][j];
		}
	}
}
void display(int** ptr, int r, int c)   // to display
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void input(int** ptr, int r, int c)  // to take input
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ptr[i][j];
		}
	}
	cout << "Matrix entered is" << endl;
	display(ptr, r, c);
}
void sum_of_matrix(int** ptr, int row, int col) // to find sum of whole matrix
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum = sum + ptr[i][j];
		}
	}
	cout << "Sum of the whole matrix is-->";
	cout << sum << endl;
}
void product_of_matrix(int** ptr, int row, int col)   // product of whole matrix
{
	int product = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			product = product * ptr[i][j];
		}
	}
	cout << "Product of the whole matrix is-->";
	cout << product << endl;
}
float* col_wise_matrix_average(int** matrix, int rows, int cols)   // column wise average
{
	float* col_averages = new float[cols];
	for (int c = 0; c < cols; ++c)
	{
		int sum = 0;
		for (int r = 0; r < rows; ++r)
		{
			sum = sum + matrix[r][c];
		}
		col_averages[c] = (float)sum / rows;
	}
	return col_averages;
}
float* row_wise_matrix_average(int** matrix, int rows, int cols)   // row wise average
{
	float* row_averages = new float[rows];
	for (int r = 0; r < rows; ++r)
	{
		int sum = 0;
		for (int c = 0; c < cols; ++c) {
			sum = sum + matrix[r][c];
		}
		row_averages[r] = (float)sum / cols;
	}
	return row_averages;
}
void whole_matrix_average(int** matrix, int rows, int cols)  // average of whole matrix
{
	float sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum = sum + matrix[i][j];
		}
	}
	int cells = rows * cols;
	cout << "Average if whole matrix is-->";
	cout << (float)sum / cells << endl;
}
void add_matrices(int** ptr, int r, int c, int** p)  // addition on two matrices
{
	cout << "Addition is" << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << ptr[i][j] + p[i][j] << " ";
		}
		cout << endl;
	}
}
void subtract_matrices(int** ptr, int r, int c, int** p)  // subtraction of 2 matrices
{
	cout << "Subtraction is" << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << ptr[i][j] - p[i][j] << " ";
		}
		cout << endl;
	}
}
void row_wise_sorting(int** ptr, int r, int c)  // row wise sorting
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < r; k++)
				for (int l = 0; l < c; l++)
					if (ptr[i][j] < ptr[k][l])
					{
						int temp = ptr[i][j];
						ptr[i][j] = ptr[k][l];
						ptr[k][l] = temp;
					}
	cout << "Row wise sorting is" << endl;
	display(ptr, r, c);
}
void col_wise_sorting(int** ptr, int r, int c) // column wise sorting
{
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				for (int l = 0; l < r; l++)
					if (ptr[j][i] < ptr[l][k])
					{
						int temp = ptr[j][i];
						ptr[j][i] = ptr[l][k];
						ptr[l][k] = temp;
					}
	cout << "Column wise sorting is" << endl;
	display(ptr, r, c);
}
int **transpose(int** ptr, int &r, int &c)  // to find transpose
{
	int** p = new int* [c];
	for (int i = 0; i < c; i++)
	{
		p[i] = new int[r];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			p[j][i] = ptr[i][j];
		}
	}
	int temp = r;
	r = c;
	c = temp;
	for (int i = 0; i < c; i++)
	{
		delete[] ptr[i];
	}
	delete[] ptr;
	ptr = NULL;

	return p;
}
int main()
{
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "                                   WELCOME TO MATRIX MANIPULATOR                                    " << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	int choose = 0;   // to read from file or to input data from user
	cout << endl;
	cout << "ENTER 1 TO GET DATA FROM THE FILE" << endl;
	cout << "ENTER 2 TO INPUT DATA" << endl;
	cin >> choose;
	while (-1)   // for wrong input 
	{
		if (choose == 1 || choose == 2)
		{
			break;
		}
		else
		{
			cout << "Invalid input enter either 1 or 2-->";
			cin >> choose;
		}
	}
	if (choose == 2)  // input data
	{
		int row = 0;
		int col = 0;
		cout << "Enter rows of 2D array-->";
		cin >> row;
		while (-1)  // for wrong input of rows
		{
			if (row > 0)
			{
				break;
			}
			else
			{
				cout << "Invalid enter number greater then 0-->";
				cin >> row;
			}
		}
		cout << "Enter columns of matrix-->";
		cin >> col;
		while (-1)  // for wrong output of columns
		{
			if (col > 0)
			{
				break;
			}
			else
			{
				cout << "Invalid enter number greater then 0-->";
				cin >> col;
			}
		}
		int** ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}
		cout << endl;
		cout << "Enter matrix elements" << endl;
		input(ptr, row, col);   // input function
		cout << endl;
		cout << "THIS PROGRAM IS ABLE TO PERFORM THE FOLLOWING TASKS" << endl;
		while (-1)  // to use it till user says it to stop 
		{
			cout << "*********************************************************" << endl;
			cout << "*********************************************************" << endl;
			cout << "**     1.Sum of the matrix(sum of all values)          **" << endl;
			cout << "**     2.Product of the matrix(product of all values)  **" << endl;
			cout << "**     3.Row wise average                              **" << endl;
			cout << "**     4.Column wise average                           **" << endl;
			cout << "**     5.Average of whole matrix                       **" << endl;
			cout << "**     6.Row wise sorting                              **" << endl;
			cout << "**     7.column wise sorting                           **" << endl;
			cout << "**     8.Addition of two matrices                      **" << endl;
			cout << "**     9.Subtraction of two matrices                   **" << endl;
			cout << "**     10.Matrix transpose                             **" << endl;
			cout << "**     11.To end the program                           **" << endl;
			cout << "*********************************************************" << endl;
			cout << "*********************************************************" << endl;
			int number;
			cout << endl;
			cout << "Enter the number assigned with each task to perform it" << endl;
			cin >> number;
			while (-1)  // for wrong input of the tasks assigned
			{
				if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9 || number == 10 || number == 11)
				{
					break;
				}
				else
				{
					cout << "Invalid enter number between 1 or 11-->";
					cin >> number;
				}
			}
			if (number == 1)  // sum of whole matrix
			{
				sum_of_matrix(ptr, row, col);
			}
			if (number == 2)  // product of whole matrix 
			{
				product_of_matrix(ptr, row, col);
			}
			if (number == 3)    // row wise matrix average 
			{
				float* p = new float[row];
				p = row_wise_matrix_average(ptr, row, col); 
				for (int i = 0; i < row; i++)  // to display the returned array of average (row wise)
				{
					cout << "AVERAGE OF ROW " << i + 1 << " is-->" << p[i] << " " << endl;
				}
				cout << endl;
			}
			if (number == 4)
			{
				float* p = new float[col];
				p = col_wise_matrix_average(ptr, row, col);
				for (int i = 0; i < col; i++)  // to display the returned array of average (col wise)
				{
					cout << "AVERAGE OF COLUMN " << i + 1 << " is-->" << p[i] << " " << endl;
				}
				cout << endl;
			}
			if (number == 5) // whole matrix average 
			{
				whole_matrix_average(ptr, row, col);
			}
			if (number == 6)  // row wise average 
			{
				row_wise_sorting(ptr, row, col);
			}
			if (number == 7)  // column wise average 
			{
				col_wise_sorting(ptr, row, col);
			}
			if (number == 8)  //  addition of two matrices
			{
				int** p = new int* [row];
				for (int i = 0; i < row; i++)
				{
					p[i] = new int[col];
				}
				cout << "Enter elements of second matrix" << endl;
				input(p, row, col);
				cout << "After addition newly formed matrix is" << endl;
				add_matrices(ptr, row, col, p);
			}
			if (number == 9) // subtraction of two matrices
			{
				int** p = new int* [row];
				for (int i = 0; i < row; i++)
				{
					p[i] = new int[col];
				}
				cout << "Enter elements of second matrix" << endl;
				input(p, row, col);
				cout << "After subtraction newly formed matrix is" << endl;
				subtract_matrices(ptr, row, col, p);
			}
			if (number == 10)  // transpose of two matrices
			{
				ptr = transpose(ptr, row, col);
				cout << "Transpose is" << endl;
				display(ptr, row, col);
			}
			if (number == 11)  // end the program
			{
				cout << "----------------------------------" << endl;
				cout << "             THE END             " << endl;
				cout << "----------------------------------" << endl;
				break;
			}
		}
	}
	if (choose == 1)  // to read from the file 
	{
		cout << "FILE HAS ALREADY ENOUGH DATA STORED IN IT. WHAT IS THE SIZE YOU NEED?" << endl;
		cout << "ENTER ROW OF MATRIX-->";
		int row;
		cin >> row;
		while (-1)  // for wrong input of rows
		{
			if (row > 0)
			{
				break;
			}
			else
			{
				cout << "Invalid enter value greater then 0-->";
				cin >> row;
			}
		}
		int col;
		cout << "ENTER COLUMN OF MATRIX-->";
		cin >> col;
		while (-1)  // for wrong input of columns 
		{
			if (col > 0)
			{
				break;
			}
			else
			{
				cout << "Invalid enter value greater then 0-->";
				cin >> col;
			}
		}
		int** ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}
		ifstream myfile;   // filing 
		myfile.open("data.txt");
		if (myfile.is_open())
		{
			read(myfile, ptr, row, col);
			cout << "MATRIX READ THROUGH FILE IS" << endl;
			display(ptr, row, col);  // display the read matrix
			cout << endl;
			while (-1) // to use the program till user says
			{
				cout << "*********************************************************" << endl;
				cout << "*********************************************************" << endl;
				cout << "**     1.Sum of the matrix(sum of all values)          **" << endl;
				cout << "**     2.Product of the matrix(product of all values)  **" << endl;
				cout << "**     3.Row wise average                              **" << endl;
				cout << "**     4.Column wise average                           **" << endl;
				cout << "**     5.Average of whole matrix                       **" << endl;
				cout << "**     6.Row wise sorting                              **" << endl;
				cout << "**     7.column wise sorting                           **" << endl;
				cout << "**     8.Addition of two matrices                      **" << endl;
				cout << "**     9.Subtraction of two matrices                   **" << endl;
				cout << "**     10.Matrix transpose                             **" << endl;
				cout << "**     11.To end the program                           **" << endl;
				cout << "*********************************************************" << endl;
				cout << "*********************************************************" << endl;
				int number;
				cout << endl;
				cout << "Enter the number assigned with each task to perform it" << endl;
				cin >> number;
				while (-1)  // wrong input of numbers
				{
					if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9 || number == 10 || number == 11)
					{
						break;
					}
					else
					{
						cout << "Invalid enter number between 1 or 11-->";
						cin >> number;
					}
				}
				if (number == 1)  // sum of whole matrix
				{
					sum_of_matrix(ptr, row, col);
				}
				if (number == 2)  // product of whole matrix
				{
					product_of_matrix(ptr, row, col);
				}
				if (number == 3)  // row wise average of matrix
				{
					float* p = new float[row];
					p = row_wise_matrix_average(ptr, row, col);
					for (int i = 0; i < row; i++)
					{
						cout << "AVERAGE OF ROW " << i + 1 << " is-->" << p[i] << " " << endl;
					}
					cout << endl;
				}
				if (number == 4)  // column wise average of matrix
				{
					float* p = new float[col];
					p = col_wise_matrix_average(ptr, row, col);
					for (int i = 0; i < col; i++)
					{
						cout << "AVERAGE OF COLUMN " << i + 1 << " is-->" << p[i] << " " << endl;
					}
					cout << endl;
				}
				if (number == 5)  // whole matrix average
				{
					whole_matrix_average(ptr, row, col);
				}
				if (number == 6) // row wise sorting 
				{
					row_wise_sorting(ptr, row, col);  
				}
				if (number == 7) // column wise sorting 
				{
					col_wise_sorting(ptr, row, col);
				}
				if (number == 8)  // add 2 matrices
				{
					int** p = new int* [row];
					for (int i = 0; i < row; i++)
					{
						p[i] = new int[col];
					}
					cout << "Enter elements of second matrix" << endl;
					input(p, row, col);
					cout << "After addition newly formed matrix is" << endl;
					add_matrices(ptr, row, col, p);
				}
				if (number == 9) // subtract two matrices
				{
					int** p = new int* [row];
					for (int i = 0; i < row; i++)
					{
						p[i] = new int[col];
					}
					cout << "Enter elements of second matrix" << endl;
					input(p, row, col);
					cout << "After subtraction newly formed matrix is" << endl;
					subtract_matrices(ptr, row, col, p);
				}
				if (number == 10) // transpose of matrix 
				{
					ptr = transpose(ptr, row, col);
					cout << "Transpose is" << endl;
					display(ptr, row, col);
				}
				if (number == 11)  // end the program 
				{
					cout << "----------------------------------" << endl;
					cout << "             THE END              " << endl;
					cout << "----------------------------------" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "File not found" << endl;
		}
	}
	system("pause");
	return 0;
}