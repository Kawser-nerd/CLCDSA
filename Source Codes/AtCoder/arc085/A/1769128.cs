using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public sealed class Program
{
    public static void Main(string[] args)
    {
        string line = Console.ReadLine();
        string[] words = line.Split(new[] { ' ' });
        int n = int.Parse(words[0]);
        int m = int.Parse(words[1]);

        // 1???????????
        int t = m * 1900 + (n - m) * 100;

        // ??????
        double p = 1.0 / Math.Pow(2, m);

        // ????????
        double q = 1 - p; 

        // ???1????????? x ??????????????????
        // x
        // = 1 * p * t + 2 * q * p * t + 3 * q^2 * p * t + ...
        // = p * t * (1 + 2 * q + 3 * q^2 + ...)

        // ?????100?????????
        double y = 0;
        double r = 1; // = q^i
        for (int i = 1; i < 1000000; i++)
        {
            y += i * r;
            r *= q;
        }

        // ????????????
        double x = p * t * Math.Round(y);

        Console.WriteLine("{0}", x);
        return;
    }
}