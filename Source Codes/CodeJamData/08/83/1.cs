using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static int ile = 500;
        static long modul = 1000000009;
        static long K = 0;
        static int N = 0;
        static int[,] tab = new int[500, 500];
        static long calc(int wierz, int prev, long last, long lastlast)
        {
            long wyn = 1;
            int sum=0;
            for(int i=0; i<N; i++)if(tab[wierz,i]==1)sum++;
            sum--;
            if (sum > K - last - lastlast) return 0;
            long pocz = K - last - lastlast;
            for (int i = 0; i < N; i++)
            {
                if (i == prev || tab[wierz, i] == 0) continue;
                long tmp = calc(i, wierz, 1, sum);
                wyn = (((wyn*pocz)% modul)*tmp)%modul;
                pocz--;
            }
            return wyn;
        }

        static void Main(string[] args)
        {
            int C = int.Parse(Console.ReadLine());
            for (int j = 1; j <=C; j++)
            {
                long wyn = 0;
                for (int i = 0; i < ile; i++)
                    for (int k = 0; k < ile; k++)
                        tab[i, k] = 0;
                string[] s = Console.ReadLine().Split(' ');
                N = int.Parse(s[0]);
                K = long.Parse(s[1]);
                for (int i = 1; i < N; i++)
                {
                    s = Console.ReadLine().Split(' ');
                    int a = int.Parse(s[0])-1;
                    int b = int.Parse(s[1])-1;
                    tab[a, b] = 1;
                    tab[b, a] = 1;
                }
                wyn = calc(0, -1, 0, 0);
                Console.WriteLine("Case #" + j.ToString() + ": " + wyn.ToString());
            }
        }
    }
}
