using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = s[0];
        int k = s[1];
        List<int> h = new List<int>();
        for (int i = 0; i < n; i ++) h.Add(int.Parse(Console.ReadLine()));
        h.Sort();
        int ans = h[k-1]-h[0];
        for (int i = 1; i < n-k+1; i ++) {
            int tmp = h[i+k-1] - h[i];
            if(tmp<ans) ans = tmp;
        }
        Console.WriteLine(ans);
    }
}