using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static int ReadInt() { return int.Parse(Console.ReadLine()); }
    static int[] ReadInts() { return Console.ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return Console.ReadLine().Split(); }

    static void Calc(string s) {
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            if (i+1 < n) {
                if (s[i] == s[i+1]) {
                    Console.WriteLine("{0} {1}", i+1, i+2);
                    return;
                }
            }
            if (i+2 < n) {
                if (s[i] == s[i+2]) {
                    Console.WriteLine("{0} {1}", i+1, i+3);
                    return;
                }
            }
        }
        Console.WriteLine("-1 -1");
    }

    static void Main() {
        var s = Console.ReadLine();
        Calc(s);
    }
}