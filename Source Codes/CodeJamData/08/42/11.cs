using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                string[] buf = Input();
                long n = long.Parse(buf[0]);
                long m = long.Parse(buf[1]);
                long A = long.Parse(buf[2]);

                bool flag = false;
                long x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
                
                x1 = y2 = 0;
                for (y1 = 0; y1 <= m && !flag; y1++)
                {
                    for (x2 = 0; x2 <= n && !flag; x2++)
                    {
                        long c = x1 * y2 - x2 * y1;
                        long a = y1 - y2;
                        long b = x2 - x1;
                        for (x3 = 0; x3 <= n && !flag; x3++)
                        {
                            long p = A - c - x3 * a;
                            y3 = Calc(b, p, m);
                            if (y3 >= 0)
                            {
                                flag = true;
                                break;
                            }
                            if (!flag)
                            {
                                p = -A - c - x3 * a;
                                y3 = Calc(b, p, m);
                                if (y3 >= 0)
                                {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if (flag) break;
                    }
                    if (flag) break;
                }

                if (!flag)
                {
                    x1 = y1 = 0;
                    for (x2 = 0; x2 <= n && !flag; x2++)
                    {
                        for (y2 = 0; y2 <= m && !flag; y2++)
                        {
                            long c = x1 * y2 - x2 * y1;
                            long a = y1 - y2;
                            long b = x2 - x1;
                            for (x3 = x2 + 1; x3 <= n && !flag; x3++)
                            {
                                long p = A - c - x3 * a;
                                y3 = Calc(b, p, m);
                                if (y3 >= 0)
                                {
                                    flag = true;
                                    break;
                                }
                                if (!flag)
                                {
                                    p = -A - c - x3 * a;
                                    y3 = Calc(b, p, m);
                                    if (y3 >= 0)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                            }
                            if (flag) break;
                        }
                        if (flag) break;
                    }
                }

                string output = "IMPOSSIBLE";
                if (flag) output = string.Format("{0} {1} {2} {3} {4} {5}", x1, y1, x2, y2, x3, y3);
                Console.WriteLine("Case #{0}: {1}", casen, output);
            }
        }

        static long Calc(long a, long b, long range)
        {
            long res = -1;
            if (a == 0)
            {
                if (b == 0) { res = 0; }
            }
            else if( b % a == 0)
            {
                res = b / a;
                if (res < 0 || res > range) res = -1;
            }
            return res;
        }

        static string[] Input()
        {
            return Console.ReadLine().Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
        }
    }

    class Node
    {
        public int GateType;
        public int Changable;
        public int Value;
    }
}
