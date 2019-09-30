using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace arc_036_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = new int[s[0]];
            for (int i = 0; i < s[0]; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
                if (i > 1) { if (a[i] + a[i - 1] + a[i - 2] >=s[1]) { }
                    else { Console.WriteLine(i+1);break; }
                }
                if (i == s[0] - 1) { Console.WriteLine("-1"); } 
            }
        }
    }
}