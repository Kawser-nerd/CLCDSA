using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var a = int.Parse(line[2]);
        var b = int.Parse(line[3]);
        var st = n;
        for (int i = 0; i < m; i++)
        {
            if (st <= a) st += b;
            st -= int.Parse(Console.ReadLine().Trim());
            if (st < 0) { Console.WriteLine(i + 1); goto end; }
        }
        Console.WriteLine("complete");
        end:;
    }
}