using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var w = a.Count(x => x % 2 == 1);
        Console.WriteLine(w % 2 == 0 ? "YES":"NO");
    }
}