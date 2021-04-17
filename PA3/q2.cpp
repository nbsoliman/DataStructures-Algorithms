#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename, country, cases;
    map <string,int> coronamap;
    int casee;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    string partOf;

    while (in)
    {
        //Gets country name
        for(int i = 0; i < line.length(); i++){
            if(!isdigit(line[i])&&line[i]!=' '){
                country+=line[i];
            }
        }
        //Gets confirmed cases
        for(int i = 0; i < line.length(); i++){
            if(isdigit(line[i])&&line[i]!=' '){
                cases+=line[i];
            }
        }
        cout << country << "  " << cases << endl;
        casee=stoi(cases);

        coronamap[country] = casee;

        getline(in,line);
        country.clear();
        cases.clear();
    }
    
    // your implementation here to print the country with max cases
    // E.g. Most confirmed cases are in USA
    int max=0;
    string maxcountry;
    for (map<string, int>::iterator it = coronamap.begin();
        it != coronamap.end(); ++it)
    {   
        if( it->second > max){
            max = it->second;
            maxcountry = it->first;
        } 
    }
    cout << "Most confirmed cases are in " << maxcountry << " with " << max << " cases." << endl;

    return 0;
}
