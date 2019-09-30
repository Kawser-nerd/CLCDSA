#include <iostream>
using namespace std;

int* h;
int num;
int doN;

bool wator()
{
  	int i;
  
  	int s = -1;

   	bool flg = false;
  
	for(i=0;i<num;i++)
    {
    	if(h[i]!=0)
        {
			flg = true;
          s = i;
          break;
        }
    }
  
  	if(!flg)
    {
    	return false;
    }
      	
  	for(i = s+1; i<num; i++)
    {
    	if(h[i] == 0)
        {
        	break;
        }
    }
  
  	for(int j=s;j<i;j++)
    {
    	h[j]--;
    }
  
  doN++;
  
  return true;
}


int main()
{
 	cin >> num;
	h = new int[num];
  	for(int i=0;i<num;i++)
    {
    	cin >> h[i];
    }
  
  	doN = 0;  	
  	while(wator());
  
  	printf("%d",doN);

	return 0;
}