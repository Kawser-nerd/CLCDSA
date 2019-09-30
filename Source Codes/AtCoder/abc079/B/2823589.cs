using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    internal static void Main(string[] args) {
        var N = int.Parse(ReadLine());
        var lst = new List<long>();
        lst.Add(2);
        lst.Add(1);

        for (int i = 2; i <= 86; i++) {
            lst.Add(lst[i - 1] + lst[i - 2]);
        }

        WriteLine(lst[N]);
     }
}