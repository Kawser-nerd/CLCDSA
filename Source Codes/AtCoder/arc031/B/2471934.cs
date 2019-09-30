using System;

namespace arc031_2
{
    class Program
    {
        static bool[,] ban = new bool[12, 12];
        static int[] mox = new int[] { 1, -1, 0, 0, };
        static int[] moy = new int[] { 0, 0, 1, -1, };
        static void bfs(int x, int y)
        {
            ban[x, y] = false;
            for (int i = 0; i < 4; i++)
            {
                if (ban[x + mox[i], y + moy[i]]) bfs(x + mox[i], y + moy[i]);
            }
        }
        static void Main(string[] args)
        {
            bool[,] x = new bool[12, 12];
            for (int i = 0; i < 10; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < 10; j++)
                {
                    x[i + 1, j + 1] = s[j] == 'o';
                }
            }
            bool ret = false;
            for (int i = 1; i < 11; i++)
            {
                for (int j = 1; j < 11; j++)
                {
                    if (!x[i, j])
                    {
                        for (int k = 0; k < 12; k++)
                            for (int l = 0; l < 12; l++)
                                ban[k, l] = x[k, l];
                        ban[i, j] = true;
                        bfs(i, j);
                        bool now = true;
                        foreach (var a in ban)
                        {
                            foreach (var b in ban) if (b) now = false;
                        }
                        if (now)
                            ret = true;
                    }
                }
            }
            Console.WriteLine(ret ? "YES" : "NO");
        }
    }
}