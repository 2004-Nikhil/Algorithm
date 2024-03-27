/*
    Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partition(vector<int>& nums, int l, int r, int& comp, int& swa)
{
    int pivot = nums[r];
    int i = l-1;
    for(int j=l;j<r;j++)
    {
        comp++;
        if(nums[j]<pivot)
        {
            i++;
            swa++;
            swap(nums[i],nums[j]);
        }
    }
    swa++;
    swap(nums[i+1],nums[r]);
    return i+1;
}

void quickSort(vector<int>& nums, int l, int r, int& comp, int& swa)
{
    if(l<r)
    {
        int pi = partition(nums,l,r,comp,swa);
        quickSort(nums,l,pi-1,comp,swa);
        quickSort(nums,pi+1,r,comp,swa);
    }
}

int main()
{
    int t,n,num;
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
        int comp = 0, swa = 0;
        quickSort(nums,0,n-1,comp,swa);
        for(int i=0;i<n;i++)
        {
            fout<<nums[i]<<" ";
        }
        fout<<endl;
        fout<<"Comparisons: "<<comp<<endl;
        fout<<"swaps: "<<swa<<endl;
    }
    return 0;
}