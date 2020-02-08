#include <iostream>
#include <ctime>

using namespace std;

const int MAXN = 10000;
int arr[MAXN];

void BubbleSort(int arr[], int arrSize)
{
    for (int i = arrSize - 1; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
};

int generateArr(int arrSize)
{
    srand(time(NULL));
    for (int i = 0; i < arrSize; ++i)
        arr[i] = rand() % 200;
}

void traverseArr(int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arrSize = 50;
    generateArr(arrSize);
    traverseArr(arrSize);
    BubbleSort(arr, arrSize);
    traverseArr(arrSize);
    return 0;
}