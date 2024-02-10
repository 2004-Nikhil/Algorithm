// Given an already sorted array of positive integers from a file, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int binarySearch(vector<int> nums,int key)
{
    int n = nums.size();
    int NOC=0;
    int ll=0,ul;
    ul=n-1;
    while(ll<=ul)
    {
        NOC++;
        int mid = (ll+ul)/2;
        if(nums[mid]==key)
        {
            return NOC;
        }
        else if(nums[mid]<key)
        {
            ll=mid+1;
        }
        else
        {
            ul=mid-1;
        }
    }
    return -NOC;
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
        int comparison = binarySearch(nums,key);
        if(comparison>0) fout<<"Present "<<comparison<<endl;
        else fout<<"Not Present "<<-comparison<<endl;
    }
    fin.close();
    fout.close();
}