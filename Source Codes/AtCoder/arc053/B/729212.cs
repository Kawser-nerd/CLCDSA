using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static int Calc(string s) {
        var xs = new int[26];
        foreach (char c in s) {
            xs[c - 'a']++;
        }

        int odd = 0;
        int pairs = 0;
        foreach (int x in xs) {
            if (x % 2 == 0) {
                pairs += x / 2;
            }
            else {
                odd++;
                pairs += (x - 1) / 2;
            }
        }

        if (odd == 0) {
            return pairs * 2;
        }
        int d = pairs / odd;
        return d * 2 + 1;
    }

    static void Main() {
        var s = ReadLine(); 
        Console.WriteLine(Calc(s));
    }
}