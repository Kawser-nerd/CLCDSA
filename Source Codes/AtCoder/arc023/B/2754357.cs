using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var d = int.Parse(line[2]);
        var odd = true;
        if (d % 2 == 0) odd = false;
        var res = 0;
        for (int i = 0; i < h; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < w; j++)
            {
                var te = int.Parse(line[j]);
                var ij = i + j;
                var ij2 = ij % 2;
                if (ij <= d && ((odd && ij2 == 1) | (!odd && ij2 == 0))) res = Math.Max(res, te);
            }
        }
        Console.WriteLine(res);
    }
}