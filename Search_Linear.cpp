// Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case.
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int linearSearch(vector<int> nums,int key)
{
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]==key)
        {
            return i+1;
        }
    }
    return -n;
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
        int comparison = linearSearch(nums,key);
        if(comparison>0) fout<<"Present "<<comparison<<endl;
        else fout<<"Not Present "<<-comparison<<endl;
    }
    fin.close();
    fout.close();
}