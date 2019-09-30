using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G3_B
    {
        public static void Main(String[] args)
        {
            string input = @"../../B.in";
            string output = @"../../B.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        sw.WriteLine("Case #{0}: {1}", tc, ls(sr));
                    }
                }
            }
        }

        private static int ls(StreamReader sr)
        {
            string[] ss = sr.ReadLine().Split(' ');
            int n = int.Parse(ss[0]);
            if (n == 0)
                return 0;
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(ss[i + 1]);
            }
            Array.Sort(a);
            for (int c = n; c >= 2; c--)
            {
                if (ch(c, a))
                {
                    return c;
                }
            }
            return 1;
        }

        const int max = 10001;
        private static bool ch(int c, int[] a)
        {
            int[] cnt = new int[max];
            foreach(int v in a)
            {
                cnt[v] ++;
            }
            return ch2(1, a.Length, c, cnt);
        }

        private static bool ch2(int start, int n, int c, int[] cnt)
        {
            if (n == 0)
                return true;
            for (; start < max && cnt[start] == 0; start++) ;
            if (start == max)
                return false;
            if (start + c - 1 >= max)
                return false;
            for (int i = start; i < start + c; i++)
            {
                if (cnt[i] == 0)
                    return false;
                cnt[i]--;
            }
            n -= c;
            for (int i = start + c - 1; i < max; i++)
            {
                if (i != start + c - 1)
                {
                    if (cnt[i] == 0)
                        break;
                    cnt[i]--;
                    n--;
                }
                int[] nc = new int[cnt.Length];
                Array.Copy(cnt, nc, cnt.Length);
                if (ch2(start, n, c, nc))
                    return true;
            }
            return false;
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
