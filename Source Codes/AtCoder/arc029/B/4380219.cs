using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        double EPS = 0.000001;

        var ab = Console.ReadLine().Split().Select(int.Parse).ToList();
        int h = ab.Max();
        int w = ab.Min();
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            ab = Console.ReadLine().Split().Select(int.Parse).ToList();
            int nh = ab.Max();
            int nw = ab.Min();
            var verdict = Judge(h, w, nh, nw) || Judge(h, w, nw, nh);
            Console.WriteLine(verdict ? "YES" : "NO");
        }
    }
    static bool Judge(double h, double w,double nh,double nw)
    {
        if (w <= nw && h <= nh)
        {
            return true;
        }
        const double EPS = 0.000001;

        double mid = 0, low = 0, invalid, valid;
        invalid = w * w / Sqrt(h * h + w * w);
        valid = 0;
        for (int _ = 0; _ < 1000; _++)
        {
            mid = (invalid + valid) / 2;
            low = Sqrt((w * w) - (mid * mid));
            if (h * (low / w) + mid <= nh) valid = mid;
            else invalid = mid;
        }

        if (h * (low / w) + mid <= nh + EPS && h * (mid / w) + low <= nw + EPS)
        {
            return true;
        }

        invalid = w * w / Sqrt(h * h + w * w);
        valid = w;
        for (int _ = 0; _ < 1000; _++)
        {
            mid = (invalid + valid) / 2;
            low = Sqrt((w * w) - (mid * mid));
            if (h * (low / w) + mid <= nh) valid = mid;
            else invalid = mid;
        }

        if (h * (low / w) + mid <= nh + EPS && h * (mid / w) + low <= nw + EPS)
        {
            return true;
        }
        return false;
    }
}