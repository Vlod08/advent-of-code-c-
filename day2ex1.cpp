#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main ()
{
    ifstream file;
    file.open("input.txt");
    string line;
    int score=0;
    while(!file.eof())
    {
        getline(file,line);
        if (line == "A Y" || line == "B Z" || line == "C X")
        {
            score = score +6;
        }
        else if (line == "A X" || line == "B Y" || line == "C Z")
        {
            score =score +3;
        }
        if (line[2]=='X')
        {
            score = score + 1;
        }
        if (line[2]=='Y')
        {
            score = score + 2;
        }
        if (line[2]=='Z')
        {
            score = score + 3;
        }

        cout<<score<<endl;
    }
    cout<< score<<endl;
    return 0;
}
