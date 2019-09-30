using System;
using System.Linq;

namespace ARC070
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine(Enumerable.Range(0, 114514).Zip(Enumerable.Repeat(int.Parse(Console.ReadLine()), 364364), (i, x) => new { i, x }).TakeWhile(t => t.i * (t.i + 1) / 2 < t.x).Count());
        }
    }
}