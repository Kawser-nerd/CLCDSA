using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private bool[] B = new bool[26];
    private int[] Map = new int[26];
    private int[] T = new int[1 << 25];
    const int Mod = 1000000007;

    private void Scan()
    {
        for (int i = 0; i < 5; i++)
        {
            var line = Console.ReadLine().Split(' ');
            for (int j = 0; j < 5; j++)
            {
                int k = int.Parse(line[j]);
                if (k != 0)
                {
                    B[k] = true;
                    Map[k] = i * 5 + j;
                }
            }
        }
    }

    private int Bit(long i)
    {
        i = (i & 0x55555555) + (i >> 1 & 0x55555555);
        i = (i & 0x33333333) + (i >> 2 & 0x33333333);
        i = (i & 0x0f0f0f0f) + (i >> 4 & 0x0f0f0f0f);
        i = (i & 0x00ff00ff) + (i >> 8 & 0x00ff00ff);
        i = (i & 0x0000ffff) + (i >> 16 & 0x0000ffff);
        return (int)i;
    }

    private bool Calc(int state, int i)
    {
        int pos = 1 << i;
        return (state & pos) > 0;
    }

    private int Minus(int state, int i)
    {
        int pos = 1 << i;
        return state - pos;
    }

    private int DFS(int state)
    {
        if (T[state] != -1)
        {
            return T[state];
        }
        int c = Bit(state);
        if (B[c])
        {
            int j = Map[c];
            if (!Calc(state, j))
            {
                T[state] = 0;
                return 0;
            }
            int x = j % 5;
            int y = j / 5;
            if (0 < x && x < 4 && (Calc(state, j + 1) ^ (Calc(state, j - 1))))
            {
                T[state] = 0;
                return 0;
            }
            if (0 < y && y < 4 && (Calc(state, j + 5) ^ (Calc(state, j - 5))))
            {
                T[state] = 0;
                return 0;
            }

            int res = DFS(Minus(state, j));
            T[state] = res;
            return res;
        }
        else
        {
            int sum = 0;
            for (int j = 0; j < 25; j++)
            {
                if (!Calc(state, j))
                {
                    continue;
                }
                int x = j % 5;
                int y = j / 5;
                if (0 < x && x < 4 && (Calc(state, j + 1) ^ (Calc(state, j - 1))))
                {
                    continue;
                }
                if (0 < y && y < 4 && (Calc(state, j + 5) ^ (Calc(state, j - 5))))
                {
                    continue;
                }

                sum += DFS(Minus(state, j));
                sum %= Mod;
            }
            T[state] = sum;
            return sum;
        }
    }

    public void Solve()
    {
        Scan();
        for(int i = 0; i < (1 << 25); i++)
        {
            T[i] = -1;
        }
        T[0] = 1;
        Console.WriteLine(DFS((1 << 25) - 1));
    }
}