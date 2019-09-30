using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;


class Program {
    internal static void Main(string[] args)
    {
        var N = int.Parse(ReadLine());
        int[] inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        var D = inp[0];
        var X = inp[1];
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            var Ai = int.Parse(ReadLine());
            cnt++;

            int hoge = Ai;
            while (hoge + 1 <= D) {
                cnt++;
                hoge += Ai;
            }
        }

        WriteLine(cnt + X);
    } 
}