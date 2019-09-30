using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace D
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            for (int i = 1; i <= N; i++)
            {
                int wyn = 0;
                string[] s = Console.ReadLine().Split(' ');
                int H, W, R;
                H = int.Parse(s[0]);
                W = int.Parse(s[1]);
                R = int.Parse(s[2]);
                int[,] tab = new int[200,200];
                for (int j = 0; j < R; j++)
                {
                    string[] y = Console.ReadLine().Split(' ');
                    tab[int.Parse(y[0]), int.Parse(y[1])] = -1;
                }
                tab[1, 1] = 1;
                for(int j=1; j<=H; j++)
                    for (int k = 1; k <= W; k++)
                    {
                        if (tab[j, k] == -1) continue;
                        if (tab[j + 2, k + 1] >= 0) tab[j + 2, k + 1] = (tab[j + 2, k + 1] + tab[j, k]) % 10007;
                        if (tab[j + 1, k + 2] >= 0) tab[j + 1, k + 2] = (tab[j + 1, k + 2] + tab[j, k]) % 10007;
                    }
                wyn = tab[H, W];
                Console.WriteLine("Case #" + i.ToString() + ": " + wyn.ToString());
            }
        }
    }
}
