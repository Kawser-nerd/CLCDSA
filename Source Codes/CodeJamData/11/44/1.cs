using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G2_D
    {        
        public static void Main(String[] args)
        {
            string input = @"../../D.in";
            //genTest(input);
            string output = @"../../D.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        string res = ls(sr);
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        private static void genTest(string input)
        {
            using (StreamWriter sw = new StreamWriter(input))
            {
                sw.WriteLine(1);
                int p = 36;
                int w = 0;
                int mw = 630;
                bool[,] a = new bool[p, p];
                Random r = new Random();
                List<string> list = new List<string>();
                for(int i=0; i<mw; i++)
                {
                    int x = r.Next(p);
                    int y = r.Next(p);
                    //Console.WriteLine(x + " " + y);
                    if (x != y)
                    {
                        if (x + y < 10)
                        {
                            continue;
                        }
                        if (!a[x, y])
                        {
                            w++;
                            a[x, y] = true;
                            a[y, x] = true;
                            list.Add(x + "," + y);
                        }
                    }
                }
                sw.WriteLine(p + " " + w);
                sw.WriteLine(String.Join(" ", list));
                Console.WriteLine("done");
            }

        }

        private static string ls(StreamReader sr)
        {
            string[] ss = sr.ReadLine().Split(' ');
            int p = int.Parse(ss[0]);
            int w = int.Parse(ss[1]);
            List<int>[] a = new List<int>[p];
            for (int i = 0; i < p; i++)
            {
                a[i] = new List<int>();
            }
            int[,] b = new int[p, p];
            int inf = 10000;
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    b[i, j] = inf;
                }
                b[i, i] = 0;
            }
            ss = sr.ReadLine().Split(' ');
            for (int i = 0; i < w; i++)
            {
                int i1 = int.Parse(ss[i].Split(',')[0]);
                int i2 = int.Parse(ss[i].Split(',')[1]);
                a[i1].Add(i2);
                a[i2].Add(i1);
                b[i1, i2] = 1;
                b[i2, i1] = 1;
            }
            for (int k = 0; k < p; k++)
            {
                for (int i = 0; i < p; i++)
                {
                    for (int j = 0; j < p; j++)
                    {
                        b[i, j] = Math.Min(b[i, j], b[i, k] + b[k, j]);
                    }
                }
            }
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    assert(b[i, j] == b[j, i]);
                }
            }
            int dis = b[0, 1];
            assert(dis < inf && dis > 0);
            string ret = (dis - 1) + " " + ls2(a, b, p, w, new int[dis], 0, dis);
            Console.WriteLine(ret);
            return ret;
        }

        private static int ls2(List<int>[] a, int[,] b, int p, int w, int[] path, int cur, int dis)
        {
            if (cur == dis - 1)
            {
                bool[] ch = new bool[p];
                for (int i = 0; i < dis; i++)
                {
                    foreach (int v in a[path[i]])
                    {
                        ch[v] = true;
                    }
                }
                for (int i = 0; i < dis; i++)
                {
                    ch[path[i]] = false;
                }
                int cnt = 0;
                for (int i = 0; i < p; i++)
                {
                    if (ch[i])
                        cnt++;
                }
                //Console.WriteLine(cnt);
                return cnt;
            }
            int max = -1;
            int curAt = path[cur];
            foreach (int v in a[curAt])
            {
                if (b[0, v] == cur + 1 && b[v, 1] == dis - 1 - cur)
                {
                    path[cur + 1] = v;
                    int val = ls2(a, b, p, w, path, cur + 1, dis);
                    max = Math.Max(val, max);
                }
            }
            assert(max >= 0);
            return max;
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
