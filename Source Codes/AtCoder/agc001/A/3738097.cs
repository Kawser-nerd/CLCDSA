using System;
using System.Linq;
class c
{
    static void Main()
    {
        Console.ReadLine();
        var l = Array.ConvertAll(Console.ReadLine().Split(), int.Parse).OrderBy(f => f);
        int ans = l.Where((f, g) => g % 2 == 0).Sum();
        Console.WriteLine(ans);
    }
}