using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, t;
            String[] strs;
            long P, Q;
            int c;
            long p2;

            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large.out"))
                {
                    T = Convert.ToInt32(sr.ReadLine());

                    for (t = 1; t <= T; t++)
                    {
                        strs = sr.ReadLine().Split(new char[] { '/' });
                        P = Convert.ToInt64(strs[0]);
                        Q = Convert.ToInt64(strs[1]);

                        c = 0;
                        p2 = Q / Get2Pow(Q);
                        if (p2 > 1)
                        {
                            if (P % p2 == 0)
                            {
                                P = P / p2;
                                Q = Q / p2;
                            }
                            else
                            {
                                c = -1;
                            }
                        }

                        if (c == 0)
                            c = Calc(P, Q, 0);
                        if (c < 0)
                            sw.WriteLine(String.Format("Case #{0}: impossible", t));
                        else
                            sw.WriteLine(String.Format("Case #{0}: {1}", t, c));
                    }

                    sw.Flush();
                    sw.Close();
                }

                sr.Close();
            }
        }

        static int Calc(long p, long q, int count)
        {
            if (count == 40)
                return -1;

            if (2L * p >= q)
                return count + 1;
            else
                return Calc(2L * p, q, count + 1);                
        }

        static long Get2Pow(long l)
        {
            long p = 1;

            while (l % 2 == 0)
            {
                p *= 2;
                l /= 2;
            }

            return p;
        }
    }
}
