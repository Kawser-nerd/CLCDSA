using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2009
{
    class Q3
    {
        public static void f()
        {
            string t = "welcome to code jam";
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\C.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\C.out"))
                {
                    int cs = int.Parse(sr.ReadLine());
                    for (int ca = 0; ca < cs; ca++)
                    {
                        string s = sr.ReadLine();
                        int[,] a = new int[s.Length + 1,t.Length + 1];
                        for (int i = 0; i <= s.Length; i++)
                        {
                            for (int j = 0; j <= t.Length; j++)
                            {
                                if (i == 0)
                                {
                                    if (j == 0)
                                    {
                                        a[i, j] = 1;
                                        a[i, j] %= 10000;
                                    }
                                }
                                else
                                {
                                    a[i, j] = a[i - 1, j];
                                    if (j > 0 && s[i - 1] == t[j - 1])
                                    {
                                        a[i, j] += a[i - 1, j - 1];
                                        a[i, j] %= 10000;
                                    }
                                }
                            }
                        }
                        int res = a[s.Length, t.Length];
                        string tmp = res.ToString();
                        while (tmp.Length < 4)
                        {
                            tmp = "0" + tmp;
                        }
                        sw.WriteLine("Case #" + (ca + 1) + ": " + tmp);
                    }
                }
            }
        }
    }
}
