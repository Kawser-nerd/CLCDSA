using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = int.Parse(line[0]);
        var b = int.Parse(line[1]);
        var k = int.Parse(Console.ReadLine().Trim());
        line = Console.ReadLine().Trim().Split(' ');
        var p = Array.ConvertAll(line, int.Parse);
        if (p.Contains(a) | p.Contains(b)) { Console.WriteLine("NO"); goto end; }
        var pd = p.Distinct().ToArray().Length;
        Console.WriteLine(pd == p.Length ? "YES" : "NO");
        end:;
    }
}