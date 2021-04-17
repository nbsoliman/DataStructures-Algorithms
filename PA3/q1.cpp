#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
using namespace std;


/*void bubbleSort(string arr[])
{
   int length = sizeof(arr)/sizeof(arr[0]);
   string tmp;
   for(int w = 0; w < length-1; w++){
    if(arr[w]>arr[w+1]){
        tmp = arr[w];
        arr[w].clear();
        arr[w]=arr[w+1];
        arr[w+1]=tmp;
    }
   }
   return;
}*/

int main()
{
    string line, filename, word;
    int pos;
    bool inList = 1;
    const int SIZE = 200;
    string wordList[SIZE];
    int listIndicate = 0;
    string variables[SIZE];

    ifstream in;
    set<string> idents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    int i = 0;
    while (in)
    {
        //Creates a string array that stores all the words
        for(int i = 0; i < line.length(); i++){
            //cout << line[i];
            if(line[i] == '"'){
                i+=1;
                while(line[i]!='"'){
                    i++;
                }
            }
            if(isalpha(line[i]) && !isdigit(line[i]) && line[i]!= ' '){
                word+=line[i];
            } else if(word.length()!=0) {
                wordList[listIndicate] = word;
                listIndicate +=1;
                word.clear();
            }
            
        }
        getline(in,line);
    }
    //Compares values in both arrays and creates a new array with values outside of reservedArray[]
    int varIndicate=0;
    for (int j = 0; j < listIndicate; j++){
        inList = 0;
        for(int a = 0; a<22; a++){
            if(wordList[j]==reserveArray[a]){
                inList+=1;
            }
        }
        if(inList==0){
                variables[varIndicate] = wordList[j];
                varIndicate+=1;
        }
    }
    

    //
    //----------------------------------------
   string tmp;
   int w =0;
   int ctr = 0;
   int ctr2=0;
   int length2 =0;
   //Finds the length of the string array
   while (variables[w].length()>0){
    length2++;
    w++;
   }
   w=0;
   //Sorts the variables alphabetically
   while (ctr < length2){
    w=0;
    ctr2=0;
    while(ctr2<length2-1){
        if(variables[w]>=variables[w+1]){
         tmp = variables[w];
         variables[w].clear();
         variables[w]=variables[w+1];
         variables[w+1]=tmp;
        }
        ctr2++;
        w++;
    }
    ctr++;
}
   //---------------------------------------------------
    for(int b = 0; b < varIndicate; b ++){
        cout<< variables[b] << endl;
    }


    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
