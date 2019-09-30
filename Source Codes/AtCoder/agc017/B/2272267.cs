using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = long.Parse(line[0]);
        var a = long.Parse(line[1]);
        var b = long.Parse(line[2]);
        var c = long.Parse(line[3]);
        var d = long.Parse(line[4]);
        for (long i = 0; i < n -1; i++)
        {
            long af = n - 1 - i;
            long t0 = c * af - d * i;
           long t1 = d * af - c * i;
            if (t0 <= b - a && t1 >= b - a) { Console.WriteLine("YES"); goto end; }
        }
        Console.WriteLine("NO");
    end:;
    }
}