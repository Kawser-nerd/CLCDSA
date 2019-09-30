using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WorldCup2010
{
    class Program
    {
        public static int solve()
        {
            int P = Int32.Parse(Console.ReadLine());
            int[] M = new int[1 << P];
            {
                String[] s = Console.ReadLine().Split(' ');
                for (int i = 0; i < M.Length; i++)
                {
                    M[i] = Int32.Parse(s[i]);
                }
            }

            for (int i = 0; i < P; i++)
            {
                String[] s = Console.ReadLine().Split(' ');
            }
            Boolean[] tree = new bool[1 << P];
            for (int i = 0; i < M.Length; i++)
            {
                int num = i + (1 << P);
                num /= 2;
                int m = M[i];
                for (; m > 0; m--)
                {
                    num /= 2;
                }
                for (; num > 0; num /= 2)
                {
                    tree[num] = true;
                }
            }
            int c = 0;
            foreach (bool i in tree)
            {
                if (i) c++;
            }
            return c;


        }

        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #" + (i + 1) + ": " + solve());
            }
        }
    }
}
