using System;
using System.Collections;
using System.Linq;


public class Test
{	
	public static int min = 999999999;
	public static int target = 0;
	public static int n =0;
	public static int[] questions = new int[10];
	public static int[]  bonus = new int[10];
	public static void Main()
	{
		string[] str = Console.ReadLine().Split(' ');
		n = int.Parse(str[0]);
		target = int.Parse(str[1]);

		for(int i = 0 ; i < n ; i++)
		{
			str = Console.ReadLine().Split(' ');
			questions[i] = int.Parse(str[0]);
			bonus[i] = int.Parse(str[1]);
		}
		string s = "";
		tansaku(s);
		Console.WriteLine(min);
	}

	public static void tansaku(string s)
	{
		if(s.Length == n)
		{
			keisan(s);
		}
		else
		{
			tansaku(s+"1");
			tansaku(s+"0");
		}
	}

	public static void keisan(string s)
	{
		char[] c = s.ToCharArray();
		int cnt = 0;
		int a = 0;
		for(int i = 0 ; i < n ; i++ )
		{
		   
			if(c[i] == '1')
			{
				a += (questions[i]*(i+1)*100)+bonus[i];
	
				cnt += questions[i];
			}
		
		}
        
		for(int i = n-1 ; i >= 0 ; i--)
		{
		    if(c[i]=='0')
				{
				    int aa = 0;
				    while(target > a && aa< questions[i]){
    					a += ((i+1)*100);
    					aa ++;
    					cnt ++;
				    }
			        break;
				}
			
		}

         if(min > cnt && target <= a)
                  {
                   // Console.WriteLine(a);
            
                    min = cnt;
            
                  }
        
	}
}