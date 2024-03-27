/*
    Name: Nikhil Nawani
    Section: B
    University Roll No: 2021330
*/
/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

pair<char,int> maxOccurence(vector<char> ch)
{
    // using counting sort find most occuring element
    int count[26]={0};
    for(int i=0;i<ch.size();i++)
    {
        count[ch[i]-'a']++;
    }
    int max=0;
    char c;
    for(int i=0;i<26;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            c=i+'a';
        }
    }
    return make_pair(c,max);
}

int main()
{
    int t,n;
    char c;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin>>t;
    while(t--)
    {
        fin>>n;
        vector<char> ch(n);
        for(int i=0;i<n;i++)
        {
            fin>>c;
            ch[i]=c;
        }
        pair<char,int> p=maxOccurence(ch);
        for(int i=0;i<n;i++)
        {
            cout<<ch[i]<<" ";
        }
        if(p.second==1)
            fout<<"No Duplicates Present"<<endl;
        else
        fout<<p.first<<"-"<<p.second<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}