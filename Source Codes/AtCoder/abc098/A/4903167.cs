using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] l = new int[3] {s[0]+s[1], s[0]-s[1], s[0]*s[1]};
        Console.WriteLine(l.Max());
    }
}