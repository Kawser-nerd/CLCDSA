using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace txtsort
{
    class Program
    {
       static  public int Backtrack(int n, int m, string g)
        {
            int min = int.MaxValue;
            char[] B = new char[g.Length];
            int[] T = new int[n];
            for (int i = 0; i < n; i++)
            {
                T[i] = -1;
            }
            int _p = 0;
            while (_p >= 0)
            {
                T[_p]++;
                if (T[_p] == m)
                {
                    T[_p] = -1;
                    _p--;
                }
                else
                {
                    int _j = 0;
                    while (T[_j] != T[_p])
                        _j++;
                    if (_j == _p)
                    {
                        _p++;
                        if (_p == n)
                        {
                            _p--;
                            for (int i = 0; i < g.Length; i+=n)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    B[i + j] = g[i + T[j]];
                                }
                            }
                            int h=0;
                            for (int i = 1; i < g.Length; i++)
                            {
                                if (B[i] != B[i - 1])
                                    h++;
                            }
                            min = Math.Min(min, h);
                        }
                    }
                }
            }
            return min+1;
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;

                int k = int.Parse(sr.ReadLine());
                int r = Backtrack(k, k, sr.ReadLine());


                string outs = "Case #" + w.ToString() + ": ";
                sw.WriteLine(outs + r.ToString());
            }
            sr.Close();
            sw.Close();
        }
    }
}
