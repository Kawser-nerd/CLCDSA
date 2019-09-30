using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace Milkshakes
{
    class Program
    {
        TextReader cin = Console.In;
        TextWriter cout = Console.Out;

        public Program(string s)
        {
            cin = new StreamReader(s);
            s = s.Substring(0, s.Length - 2) + "out";
            cout = new StreamWriter(s);
        }

        public static void Main(string[] args)
        {
            foreach (string s in Directory.GetFiles(@"C:\Users\Michael\Desktop\GCJ", "*.in"))
            {
                new Program(s).run();
            }
        }

        private void run()
        {
            int C = readInt();
            for (int cn = 1; cn <= C; cn++)
            {
                int N = readInt();
                int M = readInt();
                int[] malt = new int[M];
                int[] nomalt = new int[M];
                for (int i = 0; i < M; i++)
                {
                    int[] c = readInts();
                    for (int j = 0; j < c[0]; j++)
                    {
                        if (c[j * 2 + 2] == 0)
                            nomalt[i] |= 1 << (c[j * 2 + 1] - 1);
                        else
                            malt[i] |= 1 << (c[j * 2 + 1] - 1);
                    }
                }
                int res = -1;
                for (int i = 0; i < (1 << N); i++)
                {
                    bool ok = true;
                    for (int j = 0; j < M && ok; j++)
                        ok &= (i & malt[j]) != 0 || (~i & nomalt[j]) != 0;
                    if (!ok) continue;
                    if (countbits(i) < countbits(res))
                        res = i;
                }
                if (res == -1)
                    cout.WriteLine("Case #{0}: IMPOSSIBLE", cn);
                else
                {
                    cout.Write("Case #{0}:", cn);
                    for (int i = 0; i < N; i++)
                        cout.Write(" {0}", (res >> i) % 2);
                    cout.WriteLine();
                }
                
            }
            cout.Close();
        }

        int readInt()
        {
            return int.Parse(cin.ReadLine().Trim());
        }

        int[] readInts()
        {
            return Array.ConvertAll<string, int>(cin.ReadLine().Split(), int.Parse);
        }

        double readDouble()
        {
            return double.Parse(cin.ReadLine().Trim());
        }

        double[] readDoubles()
        {
            return Array.ConvertAll<string, double>(cin.ReadLine().Split(), double.Parse);
        }

        int countbits(int n)
        {
            int res = 0;
            while (n != 0)
            {
                res++;
                n &= n - 1;
            }
            return res;
        }
    }
}
