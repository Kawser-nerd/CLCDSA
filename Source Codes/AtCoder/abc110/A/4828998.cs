using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Array.Sort(s);
        Console.WriteLine(s[2]*10 + s[1] + s[0]);
    }
}