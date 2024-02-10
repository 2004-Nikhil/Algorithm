// Wap a to sort an array of 0's,1's and 2's in O(n) time complexity and O(1) space complexity.
#include <iostream>
using namespace std;
void sort012(int nums[],int n)
{
    int start = 0,i=0,end=n-1;
    for(i=0;i<=end;i++)
    {
        if(nums[i]==0) swap(nums[i],nums[start++]);
        else if(nums[i]==2) swap(nums[i--],nums[end--]);
    }
}

int main()
{
    int i=0,n;
    cout<<"Enter total numbers ";
    cin>>n;
    int nums[n];
    cout<<"Enter "<<n<<" numbers\n";
    while(i<n) cin>>nums[i++];
    sort012(nums,n);
    i=0;
    cout<<"Sorted order is :\n";
    while(i<n) cout<<nums[i++];
}
/*
Do not forget the else as if not used case will not be mutually exclusive and there is a chance that we will still end up 
doing swaping even after i has become more than end 
*/