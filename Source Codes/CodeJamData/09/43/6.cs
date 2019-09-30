using System;
using System.Collections.Generic;
using System.Linq;

using System.Text;
using System.IO;

namespace gcj2009
{
    class R2C
    {
        class P : IComparable
        {
            public int[] v;
            public P(int k)
            {
                v = new int[k];
            }

            #region IComparable Members

            public int CompareTo(object obj)
            {
                return v[0] - ((P)obj).v[0];
            }

            #endregion
        }
        public static void f()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\C.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\C.out"))
                {
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        int n, k;
                        String line = sr.ReadLine();
                        n = int.Parse(line.Split(' ')[0]);
                        k = int.Parse(line.Split(' ')[1]);
                        int[,] a = new int[n, n];
                        P[] b = new P[n];
                        for (int i = 0; i < n; i++)
                        {
                            line = sr.ReadLine();
                            String[] strs = line.Split(' ');
                            b[i] = new P(k);
                            for (int j = 0; j < k; j++)
                            {
                                b[i].v[j] = int.Parse(strs[j]);
                            }
                        }
                        Array.Sort(b);
                        for (int i = 0; i < n; i++)
                        {
                            for (int j = 0; j < n; j++)
                            {
                                if (i != j)
                                {
                                    bool flg = true;
                                    for (int x = 0; x < k; x++)
                                    {
                                        if (b[i].v[x] <= b[j].v[x])
                                        {
                                            flg = false;
                                            break;
                                        }
                                    }
                                    if (flg)
                                    {
                                        a[i, j] = -1;
                                        a[j, i] = 1;
                                    }
                                }
                            }
                        }
                        int[] t = new int[n];
                        int ret = 0;
                        ret = g(t, 0, 0, a, n);


                        //while (done < n)
                        {

                        }
                        sw.WriteLine("Case #" + (ci + 1) + ": " + ret);
                    }
                }
            }
        }

        private static int g(int[] t, int ret, int idx, int[,] a, int n)
        {
            if(idx == n)
                return ret;
            bool flg = true;
            int min = int.MaxValue;
            for (int j = 0; j < ret; j++)
            {
                if(a[t[j], idx] == 1)
                {
                    flg = false;
                    int tmp = t[j];
                    t[j] = idx;
                    int v = g(t, ret, idx + 1, a, n);
                    min = Math.Min(v, min);
                    t[j] = tmp;
                }
            }
            if(flg)
            {
                t[ret] = idx;                
                return g(t, ret + 1, idx + 1, a, n);                
            }
            return min;
        }
    }
}
