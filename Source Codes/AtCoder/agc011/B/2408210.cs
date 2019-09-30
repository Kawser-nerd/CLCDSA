using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, long.Parse);
        Array.Sort(a);
        var sum = a[0]; var si = 0;
        for (int i = 1; i < n; i++)
        {
            if (sum * 2 < a[i]) si = i;
            sum += a[i];
        }
        Console.WriteLine(n - si);
    }
}