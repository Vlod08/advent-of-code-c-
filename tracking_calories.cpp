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
    int maxc = vect_cals[0];
    for(int cals: vect_cals)
    {
        maxc = (maxc<cals)? cals : maxc;
    }

    return maxc;

}

int main (int argc, char** args)
{

    cout<<args[1]<<endl;
    cout<<"The max calories is : "<<max_cals(args[1])<<endl;
    return 0;
}
