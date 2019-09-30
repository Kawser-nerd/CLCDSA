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
        int R = cin.NextInt();
        int C = cin.NextInt();
        int N = cin.NextInt();

        int min_walls = int.MaxValue;
        foreach (var comb in Combinations(R * C, N))
        {
            int walls = 0;
            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    int index = c + r * C;
                    if (comb.Contains(index))
                    {
                        if (c < C - 1 && comb.Contains(index + 1))
                            walls++;
                        if (r < R - 1 && comb.Contains(index + C))
                            walls++;
                    }
                }
            }
            min_walls = Math.Min(min_walls, walls);
        }
        Console.WriteLine(min_walls);
    }

    private IEnumerable<List<int>> Combinations(int n, int k)
    {
        if (k == 0)
        {
            yield return new List<int>();
        }
        else
        {
            // Choose 'n'                
            foreach (var sub in Combinations(n - 1, k - 1))
            {
                sub.Add(n - 1);
                yield return sub;
            }

            // Don't choose 'n'
            if (k < n)
            {
                foreach (var sub in Combinations(n - 1, k))
                {
                    yield return sub;
                }
            }
        }
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