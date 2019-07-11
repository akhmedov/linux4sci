// https://codeforces.com/problemset/problem/597/B

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define ORDERS 500000
struct Order { int from{}, till{}; };
Order DP[ORDERS];

void print (int size)
{
    for (int i = 0; i < size; i++)
        cout << '{' << DP[i].from << ',' << DP[i].till << "} ";
    cout << endl;
}

void binary_insert (Order item, int size)
{
    int low = 0, mid, high = size;

    if (DP[low].till >= item.till) { 
        high = 0; 
        goto insert;
    }

    while (high - low > 1) {
        mid = (low+high)/2;
        if (item.till > DP[mid].till) low = mid;
        else high = mid;
    }

    insert: for (int i = size; i > high; i--) DP[i] = DP[i-1];
    DP[high] = item;
}

template <typename T> void bubble_sort (T* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (arr[j].till > arr[j+1].till) {
				Order tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

template <typename T> void swap (T* a, T* b)  
{  
    T t = *a;  
    *a = *b;  
    *b = t;  
}

template <typename T> void quik_sort (T* array, size_t length)
{
    int i = 0, j = length - 1;
    T key = array[i];

    if (i >= j) return;

    while(i < j) {
        while(i < j && array[j].till >= key.till) j--;
        array[i] = array[j];
        while(i < j && array[i].till <= key.till) i++;
        array[j] = array[i];
    }

    array[i] = key;
    quik_sort(&array[0], i);
    quik_sort(&array[i+1], length - i - 1);
}

template <typename T>  void quickSort (T* arr, int low, int high)  
{  
    if (low < high) {

        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].till <= pivot.till) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i+1], &arr[high]);
        int pi = i + 1;

        if (low < pi-1)  quickSort(arr, low, pi - 1);
        if (pi+1 < high) quickSort(arr, pi + 1, high);
    }
}

int main ()
{
	int orders;

    // freopen("25_input.txt", "r", stdin);
    cin >> orders;

	for (int i = 0; i < orders; i++) {
        Order odr;
        cin >> odr.from >> odr.till;
        // binary_insert(odr, i);
        DP[i] = odr;
        // print(orders);
	}

    // bubble_sort(DP,orders);
    quik_sort(DP,orders);
    // print(orders);

	int count = 1;
	int last = DP[0].till;

	for (int i = 1; i < orders; i++) {
        if (DP[i].from > last) 
            count++, last = DP[i].till;
	}

    cout << count << endl;
	return 0;
}
