using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int x = Console.ReadLine().Split().Select(int.Parse).ToArray().Concat(new[] {s[2]}).Max();
        int y = Console.ReadLine().Split().Select(int.Parse).ToArray().Concat(new[] {s[3]}).Min();
        Console.WriteLine(x < y ? "No War" : "War");
    }
}