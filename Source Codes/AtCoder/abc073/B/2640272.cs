using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main(string[] args) {
        var N = int.Parse(ReadLine());
        int res = 0;

        for (int i = 0; i < N; i++) {
            int[] inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            for (int j = inp[0]; j <= inp[1]; j++) {
                res++;
            }
        }

        WriteLine(res);
    }
}