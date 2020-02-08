#include <iostream>
#include <ctime>

using namespace std;

const int MAXN = 10000;
int arr[MAXN];

int generateArr(int arrSize, int range)
{
    srand(time(NULL));
    for (int i = 0; i < arrSize; ++i)
        arr[i] = rand() % range;
}
void traverseArr(int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    while (start < end)
    {
        while (start < end && arr[end] >= pivot)
            --end;
        arr[start] = arr[end];
        while (start < end && arr[start] < pivot)
            ++start;
        arr[end] = arr[start];
    }
    arr[start] = pivot;
    return start;
};
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = Partition(arr, start, end);
        QuickSort(arr, start, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int arrSize = 15;
    int numRange = 50;
    generateArr(arrSize, numRange);
    traverseArr(arrSize);
    QuickSort(arr, 0, arrSize - 1);
    traverseArr(arrSize);
    return 0;
}