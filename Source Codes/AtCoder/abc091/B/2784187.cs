using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;


class Program
{
    internal static void Main(string[] args)
    {
        var N = int.Parse(ReadLine());
        var dic = new Dictionary<String, int>();

        for (int i = 0; i < N; i++) {
            var S = ReadLine();
            if (dic.ContainsKey(S)) {
                dic[S]++;
            } else {
                dic.Add(S, 1);
            }
        }

        var M = int.Parse(ReadLine());

        for (int i = 0; i < M; i++) {
            var T = ReadLine();
            if (dic.ContainsKey(T)) {
                dic[T]--;
            } else {
                dic.Add(T, -1);
            }
        }

        if (dic.Values.Max() > 0) {
            WriteLine(dic.Values.Max());
        } else {
            WriteLine(0);
        }
    }
}