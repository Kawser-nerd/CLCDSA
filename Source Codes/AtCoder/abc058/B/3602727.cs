using System;
using System.Collections;
using System.Linq;


public class Test
{	
	public static void Main()
	{
		string even = Console.ReadLine();
        string odd = Console.ReadLine();
        string ans = "";

        int a = 0;
        int b = 0;
        for(int i = 0 ; i < (odd.Length + even.Length) ; i++)
        {
            if(i%2 == 1)
            {
                ans += odd[a].ToString();
                a++;
            }
            else
            {
                ans += even[b].ToString();
                b++;
            }
        }

        Console.WriteLine(ans);
	}

}