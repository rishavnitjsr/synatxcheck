#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,vector<string>> filenames;
    filenames[0]={"01.txt"};
    filenames[1]={"10.txt","12.txt","11.txt","13.txt"};
    filenames[2]={"20.txt"};
    filenames[3]={"30.txt","31.txt" ,"32.txt" ,"33.txt" ,"34.txt" ,"35.txt"};
    filenames[4]={"40.txt"};
    filenames[5]={"50.txt"};
    filenames[6]={"60.txt"};
    filenames[7]={"70.txt"};
    filenames[8]={"80.txt"};

    vector<int> seq0={8,1,3,1,5};
    vector<int> seq1 ;

    for(int k=0;k<seq0.size();k++){
    	int found = 0;
    	for(int l=0;l<seq1.size();l++){
    		if(seq1[l]==seq0[k])
    			found = 1;
    	}
    	if(found==0){
    		seq1.push_back(seq0[k]);
    	}
    }

    vector<string> filename_seq;
    for(int i=0;i<seq1.size();i++)
    {
        for(int j=0;j<filenames[seq1[i]].size();j++)
            filename_seq.push_back(filenames[seq1[i]].at(j));
    }
    for(auto i:filenames)
    {
        if(find(seq1.begin(),seq1.end(),i.first)==seq1.end())
        {
            for(int j=0;j<filenames[i.first].size();j++)
            filename_seq.push_back(i.second.at(j));
        }
    }
    for(int i=0;i<filename_seq.size();i++)
    	cout<<filename_seq[i]<<" ";
}