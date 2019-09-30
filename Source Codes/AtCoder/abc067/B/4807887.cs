using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Math;


namespace AtCodeeeer
{
    class AtCOOOOOOOOOOOder
    {
        static void Main(string[] args)
        {
            int[] s = ReadLine().Split(' ').Select(int.Parse).ToArray();
            int N = s[0];
            int K = s[1];
            List<int> ls = new List<int>();
            ls.AddRange(ReadLine().Split(' ').Select(int.Parse).ToArray());
            ls.Sort();
            int ans = 0;
            for (int i = ls.Count-1; (ls.Count-1)-i <K; i--)
            {
                ans += ls[i];
            }
            WriteLine(ans);
        }
    }
}