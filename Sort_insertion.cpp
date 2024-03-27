/*
    Name: Nikhil Nawani
    Section: B
    University Roll No: 2021330
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void insertionSort(vector<int> &nums,int &comparisons,int &shifts)
{
    int n = nums.size();
    for(int i=1;i<n;i++)
    {
        int temp = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>temp)
        {
            nums[j+1] = nums[j];
            j--;
            comparisons++;
            shifts++;
        }
        nums[j+1] = temp;
        shifts++;
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
        int comparisons = 0;
        int shifts = 0;
        fin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            fin>>num;
            nums[i]=num;
        }
        insertionSort(nums,comparisons,shifts);
        for(int i=0;i<n;i++)
        {
            fout<<nums[i]<<" ";
        }
        fout<<endl;
        fout<<"comparisons = "<<comparisons<<endl;
        fout<<"shifts = "<<shifts<<endl;
    }
    fin.close();
    fout.close();
}