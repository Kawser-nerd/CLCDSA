using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
    		long n = long.Parse(Console.ReadLine());
            if (n < 10)
            {
                Console.WriteLine(n);
                return;
            }
            bool allNine = true;
            int count = 0;
            for (count = 0;; count++)
            {
                if (n % 10 != 9) allNine = false;
                n = n / 10;
                if (n < 10) break;
            }
            if (allNine) Console.WriteLine(9 * count + n + 9);
            else Console.WriteLine(9 * count + n + 8);
            
        }
    }
    //mcs Main.cs
    //mono Main.exe