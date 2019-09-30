using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
    		string[] s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            int ans = 0;

            if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
            {
                Console.WriteLine(0);
                return;
            }
            while(ans < 32)
            {
                int bit = 1 << ans;
                if ((a & bit) != (b & bit)) break;
                if ((b & bit) != (c & bit)) break;
                ans++;
            }
            if (ans == 32) Console.WriteLine(-1);
            else Console.WriteLine(ans);
            
        }
    }
    //mcs Main.cs
    //mono Main.exe