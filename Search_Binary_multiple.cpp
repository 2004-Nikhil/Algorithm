/*
    Name: Nikhil Nawani
    Section: B
    University Roll No: 2021330
*/
/* Given a sorted array of positive integers containing few duplicate elements, design
an algorithm and implement it using a program to find whether the given key
element is present in the array or not. If present, then also find the number of copies
of given key. (Time Complexity = O(log n))
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int binarySearch(vector<int> nums, int key,int flag)
{
    int right = nums.size();
    int left =0, result = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == key)
        {
            result = mid;
            if(flag==1)// if flag is 1 then we are finding lower bound
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (nums[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int countfreq(vector<int> nums, int n, int key)
{
    int ll = binarySearch(nums,key,1);
    if(ll==-1)
    {
        return 0;
    }
    int ul = binarySearch(nums,key,0);
    cout<<ul<<" "<<ll<<endl;
    return ul-ll+1;
}

int main()
{
    int t, n, num, key;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin >> t;
    while (t--)
    {
        fin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            fin >> num;
            nums[i] = num;
        }
        fin >> key;
        int frequency = countfreq(nums, n, key);
        if (frequency > 0)
            fout << key << " - " << frequency << endl;
        else
            fout << "Not Present " << endl;
    }
    fin.close();
    fout.close();
}