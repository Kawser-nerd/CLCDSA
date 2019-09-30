using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var count = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (a.Contains(i)) { Console.Write("\""); count++; }
            Console.Write(s[i]);
        }
        if (count == 3) Console.Write("\"");
        Console.WriteLine();
    }
}