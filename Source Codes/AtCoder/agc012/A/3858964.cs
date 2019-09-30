using System;
using System.Linq;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        Console.WriteLine(a.OrderBy(f => f).Where((f, g) => n <= g && g % 2 == n % 2).Sum());
    }
}