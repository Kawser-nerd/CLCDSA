using static System.Console;
using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        int n = int.Parse(ReadLine());
        var a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = int.Parse(ReadLine());
        }
        WriteLine(a.Count() - a.Distinct().Count());
    }
}