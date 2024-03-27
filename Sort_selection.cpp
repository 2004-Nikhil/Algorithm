#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void selectionSort(vector<int> &nums,int &comparisons,int &shifts)
{
    int n = nums.size();
    for(int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            comparisons++;
            if(nums[j]<nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i],nums[minIndex]);
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
        selectionSort(nums,comparisons,shifts);
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