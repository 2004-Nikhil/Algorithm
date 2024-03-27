/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k - 1)
        return arr[pivotIndex];
    else if (pivotIndex > k - 1)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k);
}

int findKthSmallest(vector<int>& arr, int k) {
    int n = arr.size();
    return quickSelect(arr, 0, n - 1, k);
}

int findKthLargest(vector<int>& arr, int k) {
    int n = arr.size();
    return quickSelect(arr, 0, n - 1, n - k + 1);
}

int main()
{
    int t,n,num,key;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin>>t;
    while(t--)
    {
        fin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            fin>>num;
            nums[i]=num;
        }
        fin>>key;

        fout<<findKthSmallest(nums, key)<<" "<<findKthLargest(nums, key)<<endl;
    }
    fin.close();
    fout.close();
}