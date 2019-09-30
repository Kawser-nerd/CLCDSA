using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    
    public void slove()
    {
        int n = int.Parse(Console.ReadLine());
        var heights = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var result = Enumerable.Range(0, n).OrderByDescending(x => heights[x]).ToArray();
        System.Console.WriteLine(string.Join("\n", result.Select(x => x + 1)));
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}