using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            int n = int.Parse(Console.ReadLine());
            double ans = 0;
            for (int i=0; i<n; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                if (s[1] == "JPY") ans += double.Parse(s[0]);
                else ans += double.Parse(s[0]) * 380000;
            }
            Console.WriteLine(ans);
        }
    }
    //mcs Main.cs
    //mono Main.exe