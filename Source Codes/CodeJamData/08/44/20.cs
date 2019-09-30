using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace D
{
    class Program
    {
        static int[] tab;
        static int k;
        static int min;
        static int check(int a)
        {
            int wyn=0;
            int[] tb = new int[k];
            bool[] wys=new bool[k];
            for (int i = 0; i < k; i++)
            {
                tb[i] = (a % k);
                wys[a%k]=true;
                a = a / k;
            }
            for (int i = 0; i < k; i++)
                if (!wys[i]) return 1000000000;

            
            int last = -1;
            for (int i = 0; i < tab.Length; i++)
            {
                int nw = tab[k * (i / k) + tb[i % k]];
                if (nw > 'z') nw = nw - 'a';
                if (nw == last) continue;
                else
                {
                    last = nw;
                    wyn++;
                }
            }
            if (wyn < min) return wyn;
            else return wyn;
        }

        static void Main(string[] args)
        {
            long N = long.Parse(Console.ReadLine());
            for (long i = 1; i <= N; i++)
            {
                k=int.Parse(Console.ReadLine());
                string s = Console.ReadLine();
                tab = new int[s.Length];
                for (int j = 0; j < s.Length; j++) tab[j] = s[j] - 'a';
                long max = k;
                int tmp = k - 1;
                while (tmp > 0)
                {
                    max *= k;
                    tmp--;
                }
                min = s.Length;
                for (int j = 0; j < max; j++)
                {
                    int tm = check(j);
                    if (tm < min) min = tm;
                }

                Console.WriteLine("Case #" + i.ToString() + ": "+min.ToString());

            }
        }
    }
}
