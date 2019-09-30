using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Ugly_Numbers
{
    class Program
    {
        static int G(string s)
        {
            int r = 0;
            for (int i = 0; i < s.Length; i++)
            {
                r += (s[s.Length - 1 - i] - '0') * GG[i];
                r %= 210;
            }
        }
        static int[] GG = new int[50];
        static void Main(string[] args)
        {
            int oo=1;
            for (int i = 0; i < 50; i++)
            {
                GG[i] = oo;
                oo *= 10;
                oo %= 210;
            }
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;

                string s = sr.ReadLine();
                int n = s.Length;
                long[,] T = new long[n, 210];
                for (int i = n - 1; i >= 0; i--)
                {
                    for (int j = 1; i + j < n; j++)
                    {
                        int t = G(s.Substring(i, j)) + 210;
                        for (int k = 0; k < 210; k++)
                        {
                            T[i, (t + k) % 210] += T[i + j, k];
                            T[i, (t - k) % 210] += T[i + j, k];
                        }
                    }
                    {
                        int ll = G(s.Substring(i));
                        T[i, ll]++;
                    }
                }
                string outs = "Case #" + w.ToString() + ": ";
                long r = 0;
                for (int i = 0; i < 210; i++)
                {
                    if (i % 2 == 0 || i % 5 == 0 || i % 3 == 0 || i % 7 == 0)
                        r += T[0, i];
                }
                sw.WriteLine(outs + r.ToString());
            }
            sr.Close();
            sw.Close();
        }
    }
}
