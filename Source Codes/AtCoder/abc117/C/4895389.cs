using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = s[0];
        int m = s[1];
        List<int> x = Console.ReadLine().Split().Select(int.Parse).ToList();
        x.Add(x.Min());
        x.Sort();
        int[] l = new int[m];
        for(int i = 0; i < m; i ++) {
            l[i] = Math.Abs(x[i+1]-x[i]);
        }
        Array.Sort(l);
        Array.Reverse(l);
        for(int i = 0; i < n-1; i ++) {
            l[i] = 0;
            if(i == m-1) break;
        }
        Console.WriteLine(l.Sum());
    }
}