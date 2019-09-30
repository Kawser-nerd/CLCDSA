#include <iostream>

int main()
{
	char	str;
  	std::cin >> str;
  
  	if(str == 'A')
    {
    	printf("T");
    }
  	else if(str == 'T')
    {
  		printf("A");
    }
  	else if(str == 'C')
    {
        	printf("G");
    }
  	else
    {
    	    	printf("C");
    }
  
  	return 0;
}