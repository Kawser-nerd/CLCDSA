using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var wr = new bool[n];
        var a = new int[m];
        for (int i = 0; i < m; i++)
            a[m - 1 - i] = int.Parse(Console.ReadLine().Trim()) - 1;
        for (int i = 0; i < m; i++)
            if (!wr[a[i]]) { Console.WriteLine(a[i] + 1); wr[a[i]] = true; }
        for (int i = 0; i < n; i++)
            if (!wr[i]) Console.WriteLine(i + 1);
    }
}