using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cs_console
{
    class GQ_A
    {
        public static void Main(String[] args)
        {
            string input = @"C:\Documents and Settings\int\桌面\A.in";
            string output = @"C:\Documents and Settings\int\桌面\A.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    int tn = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= tn; tc++)
                    {
                        string s = sr.ReadLine();
                        int res = ls(s);
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        private static int ls(string s)
        {
            string[] ss = s.Split(' ');
            int n = int.Parse(ss[0]);
            int ret = 0;
            int[] p = new int[]{1, 1};
            int st = 0;
            int lastidx = 0;
            for (int i = 0; i < n; i++)
            {
                char c = ss[i * 2 + 1][0];
                int v = int.Parse(ss[i * 2 + 2]);
                int idx = (c == 'O') ? 0 : 1;
                int t1 = Math.Abs(p[idx] - v) + 1;
                if (idx == lastidx)
                {
                    ret += t1;
                    st += t1;
                    p[idx] = v;
                }
                else
                {
                    if (st >= t1 - 1)
                    {
                        ret += 1;
                        st = 1;
                        p[idx] = v;
                    }
                    else
                    {
                        ret += t1 - st;
                        st = t1 - st;
                        p[idx] = v;
                    }
                }
                lastidx = idx;
            }
            return ret;
        }
    }
}
