using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ret = 0d;
        for (int i = 0; i < n; i++)
        {
            var w = 0d;
            string[] line = Console.ReadLine().Trim().Split(' ');
            var a = Array.ConvertAll(line, int.Parse);
            for (int j = 0; j < 4; j++) w+= a[j];
            w += 11d / 90 * a[4];
            ret = Math.Max(ret, w);
        }
        Console.WriteLine(ret);
    }
}