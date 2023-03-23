#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    #endif
}

bool Intercheck(string search,string file){
    cout<<search;
    ifstream fin;
    fin.open(file);
    if(fin.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }
    bool isFound=0;
    while(!fin.eof())
    {
        string temp = "";
        getline(fin,temp);
        for(int i=0;i<search.size();i++)
        {
            if(temp[i]==search[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
        }

        if(isFound){
            return isFound;
        }
}
return isFound;
}

int main(){

    init_code();

    string file = "30.txt";
    string search2 = "\"is\"";

    cout<<Intercheck(search2,file)<<endl;

     file = "80.txt";
     search2 = "\"yahoo!\"";
     cout<<search2<<endl;
    cout<<Intercheck(search2,file);
}