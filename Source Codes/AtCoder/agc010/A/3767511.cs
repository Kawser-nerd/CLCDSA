using System;
using System.Linq;
class c
{
    static void Main()
    {
        Console.ReadLine();
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int odd = a.Count(f => f % 2 == 1);
        Console.WriteLine(odd % 2 == 0 ? "YES" : "NO");
    }
}