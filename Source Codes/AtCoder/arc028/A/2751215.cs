using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = int.Parse(line[1]);
        var b = int.Parse(line[2]);
        var antwin = true;
        while (true)
        {
            if (n <= a) break;
            else n -= a;
            if (n <= b) { antwin = false; break; }
            else n -= b;
        }
        Console.WriteLine(antwin ? "Ant":"Bug");
    }
}