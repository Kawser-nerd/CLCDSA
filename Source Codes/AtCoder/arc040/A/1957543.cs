using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        int takahashi = 0;
        int aoki = 0;
        for (int i = 0; i < n; i++)
        {
            string s = Console.ReadLine();
            takahashi += s.Count(x => x == 'R');
            aoki += s.Count(x => x == 'B');
        }
        Console.WriteLine(takahashi == aoki ? "DRAW" : (takahashi > aoki ? "TAKAHASHI" : "AOKI"));
    }
}