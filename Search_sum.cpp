// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> findSum(vector<int> nums)
{
    int n=nums.size();
    if(n<3) return {-1,-1,-1};
    int i=0,j=1,k=n-1;
    while(k<n && nums[i]+nums[j]<nums[k])
    {
        if((nums[i]+nums[j])==nums[k])
        {
            return {i,j,k};
        }
        
    }
    return {-1,-1,-1};
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
        vector<int> res=findSum(nums);
        if(res)
        
    }
    fin.close();
    fout.close();
}