#include <iostream>

using namespace std;

int LinearSearch(int arr[], int length, int value);
void MergeArrays(int arr1[], int arr2[], int length1, int length2);

int main()
{
    //Create two arrays
    int arr1[20]; 
    int arr2[20];
    //int arr3[40];

    int m1;
    int m2;

    int val;
    int arrayNum;
    int result;

    cout << "Array 1 and 2 are size 20.\n";
    cout << "How many elements in Array 1? ";
    cin >> m1;
    if (m1 > 20)
    {
        cout << "The array cannot be greater than 20\n";
        return 0;
    }
    for (int i = 0; i < m1; i++)
    {
        cout << "Element value at index: " << i << ": ";
        cin >> arr1[i];
    }

    cout << "How many elements in Array 2? ";
    cin >> m2;
    if (m2 > 20)
    {
        cout << "The array cannot be greater than 20\n";
        return 0;
    }
    for (int i = 0; i < m2; i++)
    {
        cout << "Element value at index: " << i << ": ";
        cin >> arr2[i];
    }

    cout << "Choose Your Operation. Pick a Number: \n";
    int choice;
    cout << "1. Linear Search\n";
    cout << "2. Merge Arrays\n";
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "Which Array Are You Searching Through?\n ";
        cout << "1 or 2? ";
        cin >> arrayNum;
        while (arrayNum != 1 && arrayNum != 2)
        {
            cout << "Which Array Are You Searching Through ? \n ";
        cout << "1 or 2? ";
        cin >> arrayNum;
        }
        cout << "What value are you looking for? ";
        cin >> val;
        if (arrayNum == 1)
            result = LinearSearch(arr1, m1, val);
        else if (arrayNum == 2)
            result = LinearSearch(arr2, m2, val);

        if (result == -1)
        {
            cout << "The value is not in the array!\n";
            break;
        }
        else {
            cout << "The value was found in index " << result << endl; 
            break;
        }
    }

    case 2: 
        MergeArrays(arr1, arr2, m1, m2);
        break;
    }
}

int LinearSearch(int arr[], int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void MergeArrays(int arr1[], int arr2[], int length1, int length2)
{
    int arr3[40];
    int length3 = length1 + length2;
    int i = 0, j = 0, k = 0;
    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            k++; i++;
        }
        else if (arr2[j] < arr1[i]) {
            arr3[k] = arr2[j];
            k++; j++;
        }
        else
        {
            arr3[k] = arr1[i];
            k++; i++;
            arr3[k] = arr2[j];
            k++; j++;
        }
    }
    while (i < length1)
    {
        arr3[k] = arr1[i];
        k++; i++;
    }
    while (j < length2)
    {
        arr3[k] = arr2[j];
        k++; j++;
    }
    
    cout << "Array 3 is now merged, the values are ";
    
    for (int s = 0; s < length3; s++)
    {
        cout << arr3[s] << " ";
    }

}
