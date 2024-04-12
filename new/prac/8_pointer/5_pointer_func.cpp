#include <bits/stdc++.h>
using namespace std;

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
}

void update(int *p)
{
    // p = p + 1;
    // cout << "Inside Update: " << p << endl;

    // To update value outside function
    *p = *p + 1;
}

// int getSum(int arr[], int n)  (writing arr[] and *arr is same when passing an array)
int getSum(int *arr, int n)
{
    cout << "\n"
         << "Size: " << sizeof(arr) << endl;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // int value = 5;
    // int *p = &value;

    // // print(p);

    // cout << "Before: " << *p << endl;
    // update(p);
    // cout << "After: " << *p << endl;

    int arr[6] = {1, 2, 3, 4, 5, 8};
    cout << "Sum is: " << getSum(arr, 5) << endl;
    cout << "Sum is: " << getSum(arr + 3, 3) << endl;
    return 0;
}