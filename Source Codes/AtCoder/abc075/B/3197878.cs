using System;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int h = int.Parse(input[0]);
	int w = int.Parse(input[1]);
    string result = "";
    string[] masu = new string[h];
	for(int i = 0; i < h; i++)
        {
          masu[i] = Console.ReadLine();	
        }
      
       
        for(int i = 0; i < h; i++)
        {
          result = "";
          for(int j = 0; j < w; j++)
        	{
            int k = 0;
          		for(int a = i-1; a <= i+1; a++)
        		{
                  for(int b = j-1; b <= j+1; b++)
        			{
                    if(a >= 0 && b >= 0 && a < h && b < w)
                    	{
                    	if(masu[a][b] == '#')k++;
                   	    }
                    	
                    }
                  
                }
            if(masu[i][j] == '.')result += k;
            else result += '#';
                  
                
       	    }
          Console.WriteLine(result);
          
        }
	}
  
}