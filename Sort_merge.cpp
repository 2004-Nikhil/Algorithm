/*
    Name: Nikhil Nawani
    Section: B
    University Roll No: 2021330
*/
/*
    Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void merge(vector<int>& nums, int l, int m, int r, int& comp, int& inv)
{
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0;i<n1;i++)
    {
        L[i] = nums[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = nums[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        comp++;
        if(L[i]<=R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
            inv += n1-i;
        }
        k++;
    }
    while(i<n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& nums, int l, int r, int& comp, int& inv)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        mergeSort(nums,l,m,comp,inv);
        mergeSort(nums,m+1,r,comp,inv);
        merge(nums,l,m,r,comp,inv);
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
        int comp = 0, inv = 0;
        mergeSort(nums,0,n-1,comp,inv);
        for(int i=0;i<n;i++)
        {
            fout<<nums[i]<<" ";
        }
        fout<<endl;
        fout<<"Comparisons: "<<comp<<endl;
        fout<<"Inversions: "<<inv<<endl;
    }
    return 0;
}