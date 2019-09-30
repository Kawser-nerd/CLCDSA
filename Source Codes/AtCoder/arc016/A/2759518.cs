using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        for (int i = 1; i <= n; i++)
            if (i != m) { Console.WriteLine(i); break; }
    }
}