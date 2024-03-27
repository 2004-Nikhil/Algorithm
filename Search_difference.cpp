// Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int countPairs(const vector<int>& arr, int K) {
    int count = 0;
    unordered_map<int, int> frequency;

    // Store the frequency of each element in the array
    for (int num : arr) {
        frequency[num]++;
    }

    // Count the pairs
    for (int num : arr) {
        int complement = num + K;

        // Check if the complement exists in the array
        if (frequency.find(complement) != frequency.end()) {
            // If num and complement are the same, ensure that there are at least two occurrences
            if (num == complement && frequency[num] > 1) {
                count += frequency[num] * (frequency[num] - 1) / 2;
            }
            // If num and complement are different
            else {
                count += frequency[num] * frequency[complement];
            }
        }
    }

    return count;
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
        int res = countPairs(nums, key);
        
        fout<<res<<endl;
    }
    fin.close();
    fout.close();
}