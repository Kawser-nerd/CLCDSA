using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string s = Console.ReadLine();
            int n0 = 0, n1 = 0;
            foreach (char c in s)
            {
                if (c == '0') n0++;
                else n1++;
            }
            Console.WriteLine(Math.Min(n0, n1) * 2);
            
        }
    }
    //mcs Main.cs
    //mono Main.exe