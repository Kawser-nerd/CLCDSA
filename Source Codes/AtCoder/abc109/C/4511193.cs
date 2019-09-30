using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    public static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = s[0];
        int X = s[1];
        int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> d = new List<int>();
        for (int i = 0; i < n; i ++) {
            d.Add(Math.Max(x[i],X) - Math.Min(x[i],X));
          d.Distinct();
        }
        int result = d[0];
        for(int i = 1; i < d.Count(); i ++) {
            result = gcd(result, d[i]);
        }
        Console.WriteLine(result);
    }
    public static int gcd(int a, int b) {
        if (a < b) return gcd(b,a);
        while (b != 0) {
             var remainder = a % b;
             a = b;
             b = remainder;
         }
         return a;
    }
}