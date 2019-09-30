using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var t = int.Parse(line[1]);
        var tsum = 0;
        var pret = int.Parse(Console.ReadLine().Trim());
        for (int i = 1; i < n; i++)
        {
            var a = int.Parse(Console.ReadLine().Trim());
            if (pret + t < a) tsum += t;
            else { tsum += a - pret; }
            pret = a;
        }
        tsum += t;
        Console.WriteLine(tsum);
    }
}