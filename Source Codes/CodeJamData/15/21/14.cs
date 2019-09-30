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
        BuildTable(1000000);

        cin = new Scanner();
        int T = cin.NextInt();
        for (int tc = 1; tc <= T; tc++)
        {
            Console.Write("Case #{0}: ", tc);
            SolveCase();
        }        
    }

    long[] table;

    private void BuildTable(int n)
    {
        table = new long[n + 1];
        table[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            long m = table[i - 1] + 1;
            if (i % 10 != 0)
            {
                long i2 = long.Parse(new String(i.ToString().Reverse().ToArray()));
                if (i2 < i)
                    m = Math.Min(m, table[i2] + 1);
            }
            table[i] = m;
        }
    }

    void SolveCase()
    {
        long N = cin.NextLong();        
        Console.WriteLine(table[N]);
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