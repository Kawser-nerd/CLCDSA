using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2009
{
    class Q1
    {
        public static void f()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\A.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\A.out"))
                {
                    int l, d, n;
                    string line = sr.ReadLine();
                    l = int.Parse(line.Split(' ')[0]);
                    d = int.Parse(line.Split(' ')[1]);
                    n = int.Parse(line.Split(' ')[2]);
                    string[] dict = new string[d];
                    for (int i = 0; i < d; i++)
                    {
                        dict[i] = sr.ReadLine();
                    }
                    bool[, ,] b = new bool[n, l, 26];
                    for (int i = 0; i < n; i++)
                    {
                        line = sr.ReadLine();
                        int idx = 0;
                        for (int j = 0; j < l; j++)
                        {
                            if (line[idx] == '(')
                            {
                                for (idx = idx + 1; line[idx] != ')'; idx++)
                                {
                                    b[i, j, line[idx] - 'a'] = true;
                                }
                                idx++;
                            }
                            else
                            {
                                b[i, j, line[idx] - 'a'] = true;
                                idx++;
                            }
                        }
                    }
                    for (int i = 0; i < n; i++)
                    {
                        int res = 0;
                        for (int j = 0; j < d; j++)
                        {
                            bool ok = true;
                            for (int k = 0; k < l; k++)
                            {
                                if (!b[i, k, dict[j][k] - 'a'])
                                {
                                    ok = false;
                                    break;
                                }
                            }
                            if (ok)
                            {
                                res++;
                            }
                        }
                        sw.WriteLine("Case #" + (i + 1) + ": " + res);
                    }
                }
            }
        }
    }
}
