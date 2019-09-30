using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var w = new int[1000001];
        var n = int.Parse(Console.ReadLine().Trim());
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]);
            var b = int.Parse(line[1]);
            w[a]++;
            if (b + 1 <= 1000000) w[b + 1]--;
        }
        var w2 = new int[1000001];
        w2[0] = w[0];
        for (int i = 1; i < 1000001; i++)
            w2[i] = w[i] + w2[i - 1];
        Console.WriteLine(w2.Max());
    }
}