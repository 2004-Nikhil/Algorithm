#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool palindrome(string &st)
{
	int n=st.length();
	vector<int> mp(256,0);
	for(int i=0;i<n;i++)
	{
		mp[int(st[i])]++;
	}
	int chance=2;
	for(i=0;i<256;i++)
	{
		if(mp[i]%2==1)
		{
			chance--;
			if(!chance) return false;
		}
	}
	return true;
}

int main()
{
    int t;
    string st;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    fin>>t;
    while(t--)
    {
        fin>>st;
        int possible = palindrome(st);
        if(possible) fout<<"Yes Possible"endl;
        else fout<<"Not Possible"<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
