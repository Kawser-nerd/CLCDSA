using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var hs = new HashSet<int>();
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        foreach(var x in a)
        {
            var t = x;
            while (true)
            {
                if (t % 2 == 0) t /= 2;
                else { hs.Add(t); break; }
            }
        }
        Console.WriteLine(hs.Count());
    }
}