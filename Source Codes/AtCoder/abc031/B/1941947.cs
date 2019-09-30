using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var L = int.Parse(line[0]);
        var h = int.Parse(line[1]);
        var n = int.Parse(Console.ReadLine().Trim());
        for (int i = 0; i < n; i++)
        {
            var a = int.Parse(Console.ReadLine().Trim());
            if (a > h) Console.WriteLine(-1);
            else if (a < L) Console.WriteLine(L - a);
            else Console.WriteLine(0);
        }
    }
}