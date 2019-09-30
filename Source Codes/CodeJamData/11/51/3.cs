using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R3ProblemA
{
    class Program
    {
        static int w, l, u, g;
        static int[] lpx, lpy, upx, upy;

        static decimal calc(decimal w)
        {
            List<decimal> x1 = new List<decimal>();
            List<decimal> y1 = new List<decimal>();
            List<decimal> x2 = new List<decimal>();
            List<decimal> y2 = new List<decimal>();
            for (int i = 0; i < l; ++i)
            {
                if (lpx[i] <= w)
                {
                    x1.Add(lpx[i]);
                    y1.Add(lpy[i]);
                }
                if (lpx[i] >= w)
                {
                    if (i != 0)
                    {
                        x1.Add(w);
                        y1.Add((lpy[i] - lpy[i - 1]) * (w - lpx[i - 1]) / (lpx[i] - lpx[i - 1]) + lpy[i - 1]);
                    }
                    break;
                }
            }
            for (int i = 0; i < u; ++i)
            {
                if (upx[i] <= w)
                {
                    x2.Add(upx[i]);
                    y2.Add(upy[i]);
                }
                if (upx[i] >= w)
                {
                    if (i != 0)
                    {
                        x2.Add(w);
                        y2.Add((upy[i] - upy[i - 1]) * (w - upx[i - 1]) / (upx[i] - upx[i - 1]) + upy[i - 1]);
                    }
                    break;
                }
            }
            for (int i = x2.Count - 1; i >= 0; --i)
            {
                x1.Add(x2[i]);
                y1.Add(y2[i]);
            }
            x1.Add(x1[0]);
            y1.Add(y1[0]);
            decimal ret = 0;
            for (int i = 0; i + 1 < x1.Count; ++i)
            {
                ret += x1[i] * y1[i + 1] - x1[i + 1] * y1[i];
            }
            return ret;
        }

        static decimal solve(decimal s)
        {
            decimal lower = 0;
            decimal upper = w;
            while (Math.Abs(upper - lower) > (decimal)1e-8)
            {
                decimal mid = (upper + lower) / 2;
                if (calc(mid) < s) lower = mid;
                else upper = mid;
            }
            return lower;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                w = Convert.ToInt32(str[0]);
                l = Convert.ToInt32(str[1]);
                u = Convert.ToInt32(str[2]);
                g = Convert.ToInt32(str[3]);
                lpx = new int[l];
                lpy = new int[l];
                upx = new int[u];
                upy = new int[u];
                for (int i = 0; i < l; ++i)
                {
                    str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    lpx[i] = Convert.ToInt32(str[0]);
                    lpy[i] = Convert.ToInt32(str[1]);
                }
                for (int i = 0; i < u; ++i)
                {
                    str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    upx[i] = Convert.ToInt32(str[0]);
                    upy[i] = Convert.ToInt32(str[1]);
                }
                decimal s = calc(w);
                Console.WriteLine("Case #{0}:", curCase + 1);
                for (int i = 1; i < g; ++i)
                {
                    Console.WriteLine(solve(s / g * i));
                }
            }
        }
    }
}
