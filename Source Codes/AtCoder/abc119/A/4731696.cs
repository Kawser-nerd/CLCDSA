using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string[] s = Console.ReadLine().Split('/');
            
            int y = int.Parse(s[0]);
            if (y < 2019) Console.WriteLine("Heisei");
            else if (y > 2019) Console.WriteLine("TBD");
            else
            {
                int m = int.Parse(s[1]);
                int d = int.Parse(s[2]);
                if (m * 100 + d <= 430) Console.WriteLine("Heisei");
                else Console.WriteLine("TBD");
            }
        }
    }
    //mcs Main.cs
    //mono Main.exe