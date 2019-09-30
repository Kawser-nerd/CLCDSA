using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = long.Parse(line[0]);
        var b = long.Parse(line[1]);
        var c = long.Parse(line[2]);
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) { Console.WriteLine(0); goto end; }
        if (a == b && b == c) { Console.WriteLine(-1); goto end; }
        var count = 0;
        while (true)
        {
            if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) { Console.WriteLine(count); goto end; }
            var  wa = a / 2;
            var wb = b / 2;
            var wc = c / 2;
            a = wb + wc;
            b = wc + wa;
            c = wa + wb;
            count++;
        }
        end:;
    }
}