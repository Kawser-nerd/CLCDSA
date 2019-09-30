using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string[] s0 = Console.ReadLine().Split(' ');
    		int n = int.Parse(s0[0]);
            int m = int.Parse(s0[1]);
            int[] arr = new int[n];
            for (int i=0; i<m; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                arr[int.Parse(s[0]) - 1]++;
                arr[int.Parse(s[1]) - 1]++;
            }
            
            bool ans = true;
            foreach (int i in arr)
            {
                if (i%2 == 1)
                {
                    ans = false;
                    break;
                }
            }
            if (ans) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
    //mcs Main.cs
    //mono Main.exe