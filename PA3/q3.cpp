#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x,doubleHash, duble);
	}
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
  int c1 = 6; 

  int buck = x % linear.size();
  int coll = 0; 

  int ctr = 0;
  while(coll < linear.size()) {

    if (linear[buck] == -1) {
      linear[buck] = x;
      return coll;
    }
    ctr++;
    buck = (buck + c1*ctr) % linear.size();
    coll++;
  }

  return coll; 
}

int insertQuad(int x, vector<int> & quad)
{
  int c1 = 3; 
  int c2 = 12;

  int buck = x % quad.size();
  int coll = 0; 
  int ctr = 0;

  while(coll < quad.size()) {

    if (quad[buck] == -1) {
      quad[buck] = x;
      return coll;
    }
    ctr++;
    buck = (buck + c1*ctr+ c2*ctr*ctr) % quad.size();
    coll++;
  }

  return coll; 
}

int insertDuble(int x, int dubHash, vector<int> & duble)
{
  int buck = x % duble.size();
  int coll = 0;
  int ctr = 0;

  while(coll < duble.size()) {
    if (duble[buck] == -1) {
      duble[buck] = x;
      return coll;
    }
    ctr++;
    buck = (buck + dubHash*ctr) % duble.size();
    coll++;
  }

  return coll; 
}
