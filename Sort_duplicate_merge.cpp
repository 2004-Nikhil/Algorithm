// Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not without sorting. (use sorting) (Time Complexity = O(n log n))
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, bool& flag) 
{
    int i = left, j = mid + 1;
    vector<int> temp(right - left + 1);
    int k = 0;

    while (i <= mid && j <= right) 
    {
        if (arr[i] < arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else if (arr[i] > arr[j]) 
        {
            temp[k++] = arr[j++];
        } 
        else 
        {
            flag = true;
            temp[k++] = arr[i++];
            j++;
            return;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right, bool& flag) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, flag);
        mergeSort(arr, mid + 1, right, flag);
        merge(arr, left, mid, right, flag);
        if(flag) return;
    }
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
        bool flag = false;
        mergeSort(nums, 0, n - 1, flag);
        if(flag)
            fout<<"YES\n";
        else
            fout<<"NO\n";
    }
    fin.close();
    fout.close();
}