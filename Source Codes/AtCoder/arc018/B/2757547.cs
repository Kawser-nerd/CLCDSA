using System;

public class P
{
    public int x { get; set; }
    public int y { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ps = new P[n];
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            ps[i] = new P { x = int.Parse(line[0]), y = int.Parse(line[1]) };
        }
        var count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (checkT(ps, i, j, k)) count++;
        Console.WriteLine(count);
    }
    public static bool checkT(P[] ps, int t1, int t2, int t3)
    {
        var x1 = (long)(ps[t2].x - ps[t1].x);
        var y1 = (long)(ps[t2].y - ps[t1].y);
        var x2 = (long)(ps[t3].x - ps[t1].x);
        var y2 = (long)(ps[t3].y - ps[t1].y);
        var tr0 = Math.Abs(x1 * y2 - x2 * y1);
        return (tr0 != 0 && tr0 % 2 == 0);
    }
}