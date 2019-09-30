using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    private Scanner cin;

    static void Main()
    {
        new Program().Run();
    }

    void Run()
    {
        cin = new Scanner();
        int T = cin.NextInt();
        for (int tc = 1; tc <= T; tc++)
        {
            Console.Write("Case #{0}: ", tc);
            SolveCase();
        }

        // Console.ReadLine();
    }

    void SolveCase()
    {
        List<int> D = new List<int>();
        List<int> M = new List<int>();

        int N = cin.NextInt();
        for (int i = 0; i < N; i++)
        {
            int d = cin.NextInt();
            int h = cin.NextInt();
            int m = cin.NextInt();
            for (int hh = 0; hh < h; hh++)
            {
                D.Add(d);
                M.Add(m + hh);
            }
        }

        double v1 = 360.0 / M[0];
        double v2 = 360.0 / M[1];

        double d0 = 360 - D[0];
        double d1 = 360 - D[1];

        double t_1 = (360 - D[0]) / v1;
        double t_2 = (360 - D[1]) / v2;
        double t0 = Math.Max(t_1, t_2) + 0.00000000001;

        if (v1 * t0 + D[0] >= 720.0  || v2 * t0 + D[1] >= 720.0)            
            Console.WriteLine("1");
        else
            Console.WriteLine("0");
    }
}

class Scanner
{
    private string[] tokens;
    private int t;

    public string Next()
    {
        if (tokens == null || t >= tokens.Length)
        {
            tokens = Console.ReadLine().Split();
            t = 0;
        }
        return tokens[t++];
    }

    public int NextInt()
    {
        return int.Parse(Next());
    }

    public long NextLong()
    {
        return long.Parse(Next());
    }

    public double NextDouble()
    {
        return double.Parse(Next());
    }
}