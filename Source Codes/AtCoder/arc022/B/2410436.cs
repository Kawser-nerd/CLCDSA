using System;
using System.Collections.Generic;
using System.Linq;

namespace arc022_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            HashSet<int> sweets = new HashSet<int>();
            int l = 0;
            int ret = 0;
            for (int r = 0; r < n; r++)
            {
                while (sweets.Contains(x[r])) { sweets.Remove(x[l]); l++; }
                ret = Math.Max(ret, r - l + 1);
                sweets.Add(x[r]);
            }
            Console.WriteLine(ret);
        }
    }
}