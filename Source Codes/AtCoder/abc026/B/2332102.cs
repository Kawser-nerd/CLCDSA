using static System.Math;
using static System.Console;
using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        int n = int.Parse(ReadLine());
        long sum = 0;
        var a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = int.Parse(ReadLine());
        }
        var sorted = a.OrderByDescending(x => x).Select(x => x * x).ToArray();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sum += sorted[i];
            } else {
                sum -= sorted[i];
            }
        }
        WriteLine(sum * PI);
    }
}