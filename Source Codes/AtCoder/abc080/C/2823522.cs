using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    internal static void Main(string[] args) {
        var N = int.Parse(ReadLine());
        var F = new List<string>();
        for (int i = 0; i < N; i++) {
            F.Add(ReadLine().Replace(" ", ""));
        }
        var P = new List<List<long>>();
        for (int i = 0; i < N; i++) {
            P.Add(ReadLine().Split(' ').Select(s => long.Parse(s)).ToList());
        }

        var ans = 0L;
        for (int i = 1; i < 1024; i++) {
            var sum = 0L;
            for (int j = 0; j < N; j++) {
                var and = Convert.ToString(i & Convert.ToInt32(F[j], 2), 2);
                var cnt = and.Length - and.Replace("1", "").Length;
                sum += P[j][cnt];
            }
            if (i == 1) { ans = sum; }
            ans = Math.Max(sum, ans);
        }

        WriteLine(ans);
    }
}