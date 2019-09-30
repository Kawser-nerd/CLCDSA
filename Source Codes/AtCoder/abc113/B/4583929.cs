using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        double[] s = Console.ReadLine().Split().Select(double.Parse).ToArray();
        List<double> h = Console.ReadLine().Split().Select(x => s[0] - double.Parse(x)*0.006).ToList();
        Console.WriteLine(FindClosestIndex(h, s[1]));
    }
    static int FindClosestIndex(List<double> list, double value) {
        double closest = list.Aggregate((x, y) => Math.Abs(x-value) < Math.Abs(y-value) ? x : y);
        return list.IndexOf(closest) + 1;
    }
}