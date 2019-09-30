using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2010
{
    class R1C_C
    {
        public static void Main(String[] args)
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\C.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\C.out"))
                {
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        string[] strs = sr.ReadLine().Split(' ');
                        int m = int.Parse(strs[0]);
                        int n = int.Parse(strs[1]);
                        int[,] a = new int[m, n];
                        for (int i = 0; i < m; i++)
                        {
                            string s = sr.ReadLine();
                            for (int j = 0; j < n / 4; j++)
                            {
                                int v = s[j] - '0';
                                if (s[j] <= 'F' && s[j] >= 'A')
                                    v = s[j] - 'A' + 10;
                                for (int k = 0; k < 4; k++)
                                {
                                    a[i, j * 4 + k] = (((1 << (3 - k)) & v) != 0) ? 0 : 1;
                                }
                            }
                        }
                        bool flag = true;
                        int upper = Math.Min(m, n);
                        int[] z = new int[upper + 1];
                        while (flag)
                        {
                            flag = false;
                            int large = 0;
                            int mi = 0, mj = 0;
                            for (int i = 0; i < m; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    int v = check(a, i, j, m, n, upper);
                                    if (v > 0)
                                    {
                                        flag = true;
                                        if (v > large)
                                        {
                                            large = v;
                                            mi = i;
                                            mj = j;
                                        }
                                    }
                                }
                            }
                            if (large > 0)
                            {
                                fill(a, mi, mj, large);
                                upper = Math.Min(upper, large);
                                z[large]++;
                            }
                        }
                        int r = 0;
                        for (int i = 0; i < z.Length; i++)
                        {
                            if (z[i] > 0)
                                r++;
                        }
                        Console.WriteLine("Case #" + (ci + 1) + ": " + r);
                        sw.WriteLine("Case #" + (ci + 1) + ": " + r);
                        for (int i = z.Length - 1; i >= 0; i--)
                        {
                            if (z[i] > 0)
                            {
                                sw.WriteLine(i + " " + z[i]);
                            }
                        }

                    }
                }
            }
        }

        private static void fill(int[,] a, int mi, int mj, int size)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    a[i + mi, j + mj] = 2;
                }
            }
        }

        private static int check(int[,] a, int i, int j, int m, int n, int upper)
        {
            if (a[i, j] == 2)
                return 0;
            int v = a[i, j];
            int idx = 1;
            bool ok = true;
            while (ok)
            {
                for (int x = 0; x <= idx; x++)
                {
                    if (!ch(a, i + x, j + idx, (x + idx + v) % 2, m, n))
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int x = 0; x < idx; x++)
                    {
                        if (!ch(a, i + idx, j + x, (x + idx + v) % 2, m, n))
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok)
                {
                    idx++;
                    if (idx > upper)
                        break;
                }
            }
            return idx;
        }

        private static bool ch(int[,] a, int x, int y, int v, int m, int n)
        {
            if (0 <= x && x < m && 0 <= y && y < n)
            {
                return a[x, y] == v;
            }
            return false;
        }
    }
}
