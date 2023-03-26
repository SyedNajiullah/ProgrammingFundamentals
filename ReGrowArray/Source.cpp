#include<iostream>
#include<fstream>

void display(int * arr, int &size);
int* deepCopy(int * oldArray, int * newArray, int &size);
int * reGrow(int * oldArray, int &size, int value);

int main()
{
	int value = 0, size = 0;
	int * arr = nullptr;
	std::ifstream fin;
	fin.open("Data.txt");
	if (fin)
	{
		fin >> value;
		arr = new int[1];
		arr[0] = value;
		size++;
		while (fin >> value)
		{
			arr = reGrow(arr, size, value);
		}
	}
	else
		std::cout << "File not found" << std::endl;
	fin.close();
	std::cout << "---- NEW ARRAY IS ----" << std::endl;
	display(arr, size);
	delete[]arr;
	arr = nullptr;
	return 0;
}

void display(int * arr, int &size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
}

int* deepCopy(int * oldArray, int * newArray, int &size)
{
	for (int i = 0; i < size; ++i)
		newArray[i] = oldArray[i];
	return newArray;
}

int * reGrow(int * oldArray, int &size, int value)
{
	int * newArray = new int[size + 1];
	newArray = deepCopy(oldArray, newArray, size);
	newArray[size] = value;
	size++;
	delete[]oldArray;
	oldArray = nullptr;
	return newArray;
}