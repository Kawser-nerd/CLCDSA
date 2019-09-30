using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var r = int.Parse(line[1]);
        var s = Console.ReadLine().Trim();
        var nr = -1;
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '.') { nr = i; break; }
        if (nr == -1) { Console.WriteLine(0); goto end; }
        var ret1 = Math.Max(0, nr - r + 1);
        var ret2 = 0;
        var p = 0;
        while (p <= nr)
        {
            if (s[p] == '.') { ret2++; p += r; }
            else p++;
        }
        Console.WriteLine(ret1 + ret2);
        end:;
    }
}