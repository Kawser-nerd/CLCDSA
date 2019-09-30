#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int s;
  	cin >> s;
  	
  	vector<int>	value;
  
  	bool flg = true;
  
  	int num = 1;
  
  	value.resize(0);	
  	
  	value.push_back(s);
  
  	while(flg)
    {
      	num++;	
      
    	if(s%2==0)
        {
			s /= 2;
        }
      	else
      	{
      		s = 3*s + 1;
        }
      
      	for(int i=0;i<value.size();i++)
        {
        	if(value[i] == s)
            {
            	printf("%d",num);	
              
              flg = false;
              break;
            }
        }
      
      	value.push_back(s);
    }

  	return 0;
}