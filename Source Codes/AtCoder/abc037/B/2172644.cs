using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var q = int.Parse(line[1]);
        var a = new int[n];
        for (int i = 0; i < q; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var L = int.Parse(line[0]) - 1;
            var r = int.Parse(line[1]) - 1;
            var t = int.Parse(line[2]);
            for (int j = L; j <= r; j++) a[j] = t;
        }
        foreach (var x in a) Console.WriteLine(x);
    }
}