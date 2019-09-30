using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] l = new int[] {Math.Abs(a[0]-a[1]), Math.Abs(a[0]-a[2]), Math.Abs(a[1]-a[2])};
        Array.Sort(l);
        Console.WriteLine(l[0]+l[1]);
    }
}