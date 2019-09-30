using System;
using System.Linq;
class c
{
    static void Main()
    {
        var s = Console.ReadLine();
        s = string.Join("", s.Distinct().OrderBy(f => f));
        Console.WriteLine(s == "EW" || s == "NS" || s == "ENSW" ? "Yes" : "No");
    }
}