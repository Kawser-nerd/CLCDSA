using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{       
    static IEnumerable<string> GenerateChain(int start, int count)
    {
        foreach(int i in Enumerable.Range(1, count))
        {
            yield return $"{start} {start + i}";
        }
    }
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int a = int.Parse(inputs[0]);
        int b = int.Parse(inputs[1]);
        int c = int.Parse(inputs[2]);
        System.Console.WriteLine(b + Math.Min(b + a + 1, c));
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}