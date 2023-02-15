#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> topn_max_cals(string file_loc,int topn)
{
    ifstream file;
    file.open(file_loc);
    string line;
    vector<int> vect_cals;
    int acc = 0 ;
    while(!file.eof())
    {
        getline(file,line);
        if(line == "")
        {
            vect_cals.push_back(acc);
            acc = 0;
            
        }
        else
        {
            acc = acc + stoi(line);
        }

    }
/***********finding the max amongst the cals**************/
    vector<int> maxc; 
    maxc.push_back(vect_cals[0]);
    for(int cals: vect_cals)
    {
        maxc[0] = (maxc[0]<cals)? cals : maxc[0];
    }
    for(int i = 1;i<topn;i++)
    {
    	maxc.push_back(vect_cals[0]);
    	for(int cals: vect_cals)
    	{
        	maxc[i] = ((maxc[i]<cals)&&(maxc[i]<maxc[i-1]) )? cals : maxc[i];
    	}
    	
    }

    return maxc;

}

int main (int argc, char** args)
{

    cout<<args[1]<<endl;
    vector<int> result = topn_max_cals(args[1],stoi(args[2]));
    for(int val: result)
    {
    	cout<<val<<endl;
    }
    
    return 0;
    
}
