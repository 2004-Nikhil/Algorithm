// Wap to implement counting sort for the given array of integers
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void countingSort(vector<int>& nums)
{
    int n = nums.size();
    int max = nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]>max)
        {
            max = nums[i];
        }
    }
    vector<int> count(max+1,0);
    for(int i=0;i<n;i++)
    {
        count[nums[i]]++;
    }
    for(int i=1;i<=max;i++)
    {
        count[i] += count[i-1];
    }
    vector<int> output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[count[nums[i]]-1] = nums[i];
        count[nums[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        nums[i] = output[i];
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
        countingSort(nums);
        for(int i=0;i<n;i++)
        {
            fout<<nums[i]<<" ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}