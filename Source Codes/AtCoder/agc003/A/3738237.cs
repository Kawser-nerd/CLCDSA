using System;
using System.Linq;
class c
{
    static void Main()
    {
        var s = string.Join("",Console.ReadLine().Distinct().OrderBy(f => f));
        Console.WriteLine( s=="EW" || s=="NS" || s=="ENSW" ? "Yes" : "No");
    }
}