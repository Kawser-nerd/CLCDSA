using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var s = 0L;  var w = 0L;
        for (int i = 0; i < k; i++) w += a[i];
        s = w;
        for (int i = 0; i < n - k; i++)
        {
            w += - a[i] + a[i + k];
            s += w;
        }
        Console.WriteLine(s);
    }
}