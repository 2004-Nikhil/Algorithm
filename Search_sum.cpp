// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> findIndices(vector<int>& arr) 
{
    int n = arr.size();

    // Iterate through the array
    for (int i = n - 1; i >= 2; i--) {
        // Initialize two pointers
        int left = 0, right = i - 1;

        // Find pair with the remaining part of the array
        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == arr[i]) 
            {
                return {left+1, right+1, i+1};
            }
            else if (sum < arr[i])
                left++;
            else
                right--;
        }
    }
    return {-1, -1, -1};
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
        vector<int> res = findIndices(nums);
        for(int i=0;i<3;i++)
        {
            fout<<res[i]<<" ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}