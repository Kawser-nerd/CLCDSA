using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> min = new List<int>();
        for (int i = 0; i < s[0]; i ++) {
            int[] c = Console.ReadLine().Split().Select(int.Parse).ToArray();
            if (c[1]<=s[1]) min.Add(c[0]);
        }
        if (min.Count()==0) Console.WriteLine("TLE");
        else Console.WriteLine(min.Min());
    }
}