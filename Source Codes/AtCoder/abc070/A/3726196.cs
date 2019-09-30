using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = Console.ReadLine();
        var m = n.ToCharArray().Reverse();

        var str = "";
        foreach (var ch in m)
        {
            str += ch;
        }

        Console.WriteLine(n == str ? "Yes" : "No");
    }
}