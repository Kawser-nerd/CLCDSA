using System;
using System.Linq;
using System.Numerics;
using System.Collections;
using System.Collections.Generic;

public class Program {
    static void Main (string[] args) {
        var S = Console.ReadLine();
        var T = int.Parse(Console.ReadLine());
        var U = S.Length - S.Replace("U", "").Length;
        var D = S.Length - S.Replace("D", "").Length;
        var L = S.Length - S.Replace("L", "").Length;
        var R = S.Length - S.Replace("R", "").Length;
        var W = Math.Max(U, D) - Math.Min(U, D);
        var H = Math.Max(L, R) - Math.Min(L, R);
        var N = S.Length - S.Replace("?", "").Length;
        if (T == 1) {
            Console.WriteLine(W + H + N);
        } else {
            if (W + H - N >= 0) {
                Console.WriteLine(W + H - N);
            } else {
                Console.WriteLine(Math.Abs(W + H - N) % 2);
            }
        }
    }
}