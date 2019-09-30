using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cs_console
{
    class GQ_B
    {
        public static void Main(String[] args)
        {
            string input = @"C:\Documents and Settings\int\桌面\B.in";
            string output = @"C:\Documents and Settings\int\桌面\B.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    int tn = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= tn; tc++)
                    {
                        string s = sr.ReadLine();
                        string res = ls(s);
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        private static string ls(string s)
        {
            string[] ss = s.Split(' ');
            int pos = 0;
            int c = int.Parse(ss[pos]);
            pos++;

            char[,] cm = new char[cnt, cnt];
            for (int i = 0; i < c; i++)
            {
                string t = ss[pos];
                pos++;
                assert(t.Length == 3);
                int i1 = find(t[0]);
                int i2 = find(t[1]);
                cm[i1, i2] = t[2];
                cm[i2, i1] = t[2];
            }

            int d = int.Parse(ss[pos]);
            pos++;
            List<int>[] op = new List<int>[cnt];
            for (int i = 0; i < op.Length; i++)
            {
                op[i] = new List<int>();
            }
            for (int i = 0; i < d; i++)
            {
                string t = ss[pos];
                pos++;
                assert(t.Length == 2);
                int i1 = find(t[0]);
                int i2 = find(t[1]);
                op[i1].Add(i2);
                op[i2].Add(i1);
            }
            int n = int.Parse(ss[pos]);
            pos++;
            string a = ss[pos];
            pos++;
            assert(a.Length == n);

            //Console.WriteLine();
            //bool[] has = new bool[cnt];
            List<char> res = new List<char>();
            for (int i = 0; i < n; i++)
            {
                char b = a[i];
                int idx = find(b);
                assert(idx >= 0);
                bool toAdd = true;
                if (res.Count > 0)
                {
                    char last = res[res.Count - 1];
                    int lastidx = find(last);
                    if (lastidx != -1 && cm[lastidx, idx] != 0)
                    {
                        res[res.Count - 1] = cm[lastidx, idx];
                        //Console.WriteLine("CM!");
                        toAdd = false;
                    }
                }
                if (toAdd)
                {
                    foreach (char x in res)
                    {
                        if (op[idx].Contains(find(x)))
                        {
                            assert(res.Count > 0);
                            res.Clear();
                            toAdd = false;
                            //Console.WriteLine("Clear!");
                            break;
                        }
                    }

                    //foreach (int o in op[idx])
                    //{
                    //    if (has[o])
                    //    {
                    //        assert(res.Count > 0);
                    //        assert(o != idx);
                    //        res.Clear();
                    //        for (int j = 0; j < has.Length; j++)
                    //        {
                    //            has[j] = false;
                    //        }
                    //        toAdd = false;
                    //        //Console.WriteLine("Clear!");
                    //        break;
                    //    }
                    //}
                }

                if (toAdd)
                {
                    res.Add(b);
                    //Console.WriteLine("Add " + b);
                    //has[idx] = true;
                }
                //Console.WriteLine("[" + String.Join(", ", res) + "]");
            }

            string ret = "[" + String.Join(", ", res) + "]";
            return ret;
        }
        const int cnt = 8;
        private static int find(char b)
        {
            string s = "QWERASDF";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == b)
                    return i;
            }
            return -1;
        }

        static void assert(bool v)
        {
            if (false)
            {
                throw new Exception();
            }
        }
    }
}
