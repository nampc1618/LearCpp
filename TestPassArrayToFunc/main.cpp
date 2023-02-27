#include <iostream>

void fun(int* arr, unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		std::cout << " " << arr[i] << std::endl;
	}
}

double getAverage(int arr[], int size)
{
	int i, sum = 0;
	double avg;
	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	avg = double(sum) / size;

	return avg;
}

int main(int argv, const char* argc)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	unsigned int n = sizeof(arr) / sizeof(arr[0]);
	fun(arr, n);

	int balance[5] = { 100, 40, 20, 67, 43 };
	double avg;

	avg = getAverage(balance, 5);
	std::cout << "Average value is: " << avg << std::endl;

	return 0;
}
