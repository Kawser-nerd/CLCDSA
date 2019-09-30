using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2009
{
    class R2A
    {
        public static void f()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\A.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\A.out"))
                {
                    //bool[] b = new bool[1 << 24];
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        int n = int.Parse(sr.ReadLine());
                        int[] a = new int[n];
                        for (int i = 0; i < n; i++)
                        {
                            string line = sr.ReadLine();
                            int max = 0;
                            for (int j = 0; j < n; j++)
                            {
                                if (line[j] == '1')
                                {
                                    max = j;
                                }
                            }
                            Console.WriteLine(line);
                            a[i] = max;
                        }
                        int v = fix(ref a, ref n);
                        //int k = v + calc(b, n, a);
                        Console.WriteLine("Case #" + (ci + 1) + ": " + v);
                        sw.WriteLine("Case #" + (ci + 1) + ": " + v);
                    }
                }
            }
        }

        private static int fix(ref int[] a, ref int n)
        {
            int ret = 0;
            while (n > 1)
            {
                int v = fix3(ref a, ref n);
                if (v >= 0)
                {
                    ret += v;
                }
            }
            return ret;
        }

        private static int fix3(ref int[] a, ref int n)
        {
            int i1 = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 0)
                {
                    i1 = i;
                    break;
                }
            }
            int v = -1;
            v = i1;
            int[] b = new int[n - 1];
            for (int i = 0; i < i1; i++)
            {
                b[i] = Math.Max(a[i] - 1, 0);
            }
            for (int i = i1 + 1; i < n; i++)
            {
                b[i - 1] = Math.Max(a[i] - 1, 0);
            }
            a = b;
            n--;
            return v;
        }

        //private static int fix2(ref int[] a, ref int n)
        //{
        //    int c1 = 0;
        //    int c2 = 0;
        //    int i1 = 0;
        //    int i2 = 0;
        //    for (int i = 0; i < n; i++)
        //    {
        //        if (a[i] == 0)
        //        {
        //            c1++;
        //            i1 = i;
        //        }
        //        else if (a[i] == n - 1)
        //        {
        //            c2++;
        //            i2 = i;
        //        }
        //    }
        //    int v = -1;
        //    if (c1 == 1)
        //    {
        //        v = i1;
        //        int[] b = new int[n - 1];
        //        for (int i = 0; i < i1; i++)
        //        {
        //            b[i] = a[i] - 1;
        //        }
        //        for (int i = i1 + 1; i < n; i++)
        //        {
        //            b[i - 1] = a[i] - 1;
        //        }
        //        a = b;
        //        n--;
        //    }
        //    else if (c2 == 1)
        //    {
        //        v = n - 1 - i2;
        //        int[] b = new int[n - 1];
        //        for (int i = 0; i < i2; i++)
        //        {
        //            b[i] = a[i];
        //        }
        //        for (int i = i2 + 1; i < n; i++)
        //        {
        //            b[i - 1] = a[i];
        //        }
        //        a = b;
        //        n--;
        //    }
        //    return v;
        //}

        //private static int calc(bool[] b, int n, int[] a)
        //{
        //    Console.WriteLine(n);
        //    for (int i = 0; i < b.Length; i++)
        //        b[i] = false;
        //    int k = -1;
        //    Queue<int[]> q = new Queue<int[]>();
        //    int[] na = new int[n + 1];
        //    for (int i = 0; i < n; i++)
        //        na[i] = a[i];
        //    q.Enqueue(na);
        //    if (check(na, n))
        //    {
        //        k = 0;
        //    }
        //    b[g(na, n)] = true;
        //    while (q.Count > 0)
        //    {
        //        int[] p = q.Dequeue();
        //        for (int i = 0; i < n - 1; i++)
        //        {
        //            int[] y = new int[n + 1];
        //            y[n] = p[n] + 1;
        //            for (int j = 0; j < n; j++)
        //            {
        //                y[j] = p[j];
        //            }
        //            y[i] = p[i + 1];
        //            y[i + 1] = p[i];
        //            if (check(y, n))
        //            {
        //                k = y[n];
        //                break;
        //            }
        //            int x = g(y, n);
        //            if (!b[x])
        //            {
        //                q.Enqueue(y);
        //            }
        //        }
        //        if (k >= 0)
        //            break;
        //    }
        //    q.Clear();
        //    GC.Collect();
        //    return k;
        //}

        //private static bool check(int[] y, int n)
        //{
        //    for (int i = 0; i < n; i++)
        //    {
        //        if (y[i] > i)
        //            return false;
        //    }
        //    return true;
        //}

        //private static int g(int[] a, int n)
        //{
        //    int ret = 0;
        //    for (int i = 0; i < n; i++)
        //    {
        //        ret *= n;
        //        ret += a[i];
        //    }
        //    return ret;
        //}
    }
}
