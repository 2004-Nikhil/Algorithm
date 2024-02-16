/*
    Name: Nikhil Nawani
    Section: B
    University Roll No: 2021330
*/
/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array 
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int jumpSearch(vector<int> nums,int key)
{
    int n = nums.size();
    int ll=0,ul,k=0;
    int NOC=0;
    while(pow(2,k)<n && nums[pow(2,k)]<=key)
    {
        k++;NOC++;
    }
    ll=pow(2,k-1)>0?pow(2,k-1):0;// smaller value
    ul=pow(2,k)>n?n-1:pow(2,k);// greater value
    cout<<ll<<" "<<ul<<endl; // Range of block
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
        int comparison = jumpSearch(nums,key);
        if(comparison>0) fout<<"Present "<<comparison<<endl;
        else fout<<"Not Present "<<-comparison<<endl;
    }
    fin.close();
    fout.close();
}
/*
input.txt has following content:
3
5
12 23 36 39 41
41
8
21 39 40 45 51 54 68 72
69
10
101 246 438 561 796 896 899 4644 7999 8545
7999

output.txt shows the following content:
Present 4
Not Present 5
Present 5
*/