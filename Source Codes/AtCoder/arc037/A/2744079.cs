using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var res = a.Select(x => Math.Max(0, 80 - x)).Sum();
        Console.WriteLine(res);
    }
}