using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        List<int> b = Console.ReadLine().Split().Select(int.Parse).ToList();
        List<int> a = solve(b,n);
        foreach(int i in a) Console.WriteLine(i);
    }
    static List<int> solve(List<int> b, int n) {
        List<int> a = new List<int>();
        for (int i = n; i >= 1; i --) {
            if (b[i-1]>i) {
                    a.Clear();
                    a.Add(-1);
                    return a;
                }
            for (int j = i-1; j >= 0; j --) {
                if (b[j]==j+1) {
                    a.Add(b[j]);
                    b.RemoveAt(j);
                    break;
                }
            }
        }
        a.Reverse();
        return a;
    }
}