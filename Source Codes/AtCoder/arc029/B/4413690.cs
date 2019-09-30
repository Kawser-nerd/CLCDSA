using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class P
{
    static void Main()
    {
        var ab = Console.ReadLine().Split().Select(int.Parse).ToList();
        int h = ab[0];
        int w = ab[1];
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            var cd = Console.ReadLine().Split().Select(int.Parse).ToList();
            //90????????
            Console.WriteLine(
                (ab[0] <= cd[0] && ab[1] <= cd[1]) || (ab[1] <= cd[0] && ab[0] <= cd[1]) ||
                Judge(h, w, cd[0], cd[1]) || Judge(h, w, cd[1], cd[0]) || Judge(w, h, cd[0], cd[1]) || Judge(w, h, cd[1], cd[0]) ? "YES" : "NO");
        }
    }

    static bool Judge(double h, double w, double bh, double bw)
    {
        const double EPS = 0.0001;

        if (bh < w) return false;
        //      ?s?
        //l?|  ???
        //? |????
        // ?|???
        //s?|??
        //?  ?l   
        //??????????
        //l = sqrt(w^2 - s^2)???
        //???????????????s : w = w : sqrt(w^2 + h^2)??????
        double invalid = w * w / Sqrt(h * h + w * w);
        //w???????(????????)?????????????????(??????????????)
        double valid = w;
        for (int _ = 0; _ < 100; _++)
        {
            var mid = (invalid + valid) / 2;
            //???????????? ???s + l???l?= l * (h / w) ??(?????)
            if (mid + h * Sqrt(w * w - mid * mid) / w <= bh) valid = mid;
            else invalid = mid;
        }
        //????????????? ??l + s???s?= s * (h / w) ??(?????)
        return valid * h / w + Sqrt(w * w - valid * valid) < bw + EPS;
    }
}