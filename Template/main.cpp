#include <iostream>
using namespace std;

// Function Template 1
template <typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

// Function Template 2
template <class T> void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1;  i < j; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

// Class Template 1 
template <typename T> class Array {
private:
	T* ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};
template <typename T> Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
	{
		ptr[i] = arr[i];
	}
}
template <typename T> void Array<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << *(ptr + i);
	}
	cout << endl;
}

// Class Template 2
template <class T, class U> class A {
	T x;
	U y;
public:
	A() { cout << "Constructor Called : " << typeid(T).name() << " - " << typeid(U).name() << endl; }
};

// Class Template 3
template <class T, class U = char> class B {
public:
	T x;
	U y;
	B() { cout << "Constructor Called : " << typeid(T).name() << endl; }
};

// Class Template 4
template <class T, int max> int arrMin(T arr[], int n) {
	int m = max;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < m)
			m = arr[i];
	}
	return m;
}

// Class Template 5
template <class T> class info {
public:
	info(T A) {
		cout << "\n"
			<< "A = " << A
			<< " size of data in bytes: " << sizeof(A);
	}
};

int main(int argv, const char* argc)
{
	cout << "--------------Function Template 1--------------" << endl;
	cout << myMax<int>(7, 3) << endl;
	cout << myMax<double>(5.0, 2.3) << endl;
	cout << myMax<char>('a', 'n') << endl;

	cout << "--------------Function Template 2--------------" << endl;
	int a[5] = { 10, 30, 25, 65, 58 };
	int n = sizeof(a) / sizeof(a[0]);
	bubbleSort<int>(a, n);
	cout << " Sorted array: ";
	for ( int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "--------------Class Template 1--------------" << endl;
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int> array(arr, 5);
	array.print();

	cout << "--------------Class Template 2--------------" << endl;
	A<char, char> c;
	A<int, double> d;

	cout << "--------------Class Template 3--------------" << endl;
	B<int> g;

	cout << "--------------Class Template 4--------------" << endl;
	int arr1[] = { 10, 20, 15, 12 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	char arr2[] = { 1, 2, 3 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	// Second template parameter to arrMin must be a
	// constant
	cout << arrMin<int, 10000>(arr1, n1) << endl;
	cout << arrMin<char, 256>(arr2, n2);

	cout << "--------------Class Template 5--------------" << endl;
	// clrscr();

	// passing character value by creating an objects
	info<char> p('x');

	// passing integer value by creating an object
	info<int> q(22);

	// passing float value by creating an object
	info<float> r(2.25);

	return 0;
}