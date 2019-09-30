using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        double[] s = Console.ReadLine().Split().Select(double.Parse).ToArray();
        Console.WriteLine(Math.Ceiling(s.Average()));
    }
}