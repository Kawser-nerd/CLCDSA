using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var xy = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var a = new int[7] { 1, 3, 5, 7, 8, 10, 12 };
        var b = new int[4] { 4, 6, 9, 11 };
        Console.WriteLine((a.Contains(xy[0]) && a.Contains(xy[1])) || (b.Contains(xy[0]) && b.Contains(xy[1])) ? "Yes" : "No");
    }
}