#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int jumpSearch(vector<int> nums,int key)
{
    int n = nums.size();
    int ll=0,ul,k=0;

    while(pow(2,k)<n && nums[pow(2,k)]<key)
    {
        k++;
    }
    ll=pow(2,k-1)>0?pow(2,k-1):0;// smaller value
    ul=pow(2,k)>n?n:pow(2,k);// greater value
    while(ll<ul)
    {
        int mid = (ll+ul)/2;
        if(nums[mid]==key)
        {
            cout<<"Found"<<endl;
            return 1;
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
    cout<<"Not Found"<<endl;
    return -1;
}

int main()
{
    int t,n,num,key;
    cout<<"Enter number of test cases : ";
    cin>>t;
    while(t--)
    {
        cout<<"Enter number of terms : ";
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>num;
            nums[i]=num;
        }
        cout<<"Enter number to search : ";
        cin>>key;
        int comparison = jumpSearch(nums,key);
    }
}