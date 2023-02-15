#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int max_cals(string file_loc)
{
    ifstream file;
    file.open(file_loc);
    string line;
    vector<int> vect_cals;
    int acc = 0 ;
    while(!file.eof())
    {
        getline(file,line);
        if(line == "\n")
        {
            vect_cals.push_back(acc);
        }
        else
        {
            acc = acc + stoi(line);
        }

    }
/***********finding the max amongst the cals**************/
    int maxc = vect_cals[0];
    for(int cals: vect_cals)
    {
        maxc = (maxc<cals)? cals : maxc;
    }

    return maxc;

}

void main (char** args, int argc)
{
    cout<<max_cals()<<endl;
    
}
