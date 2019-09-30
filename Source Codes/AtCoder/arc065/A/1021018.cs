using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static int ReadInt() { return int.Parse(Console.ReadLine()); }
    static int[] ReadInts() { return Console.ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return Console.ReadLine().Split(); }

    static bool Match(int p, string s, string t) {
        if (p < 0 || p + t.Length > s.Length) return false;

        for (int i = 0; i < t.Length; i++) {
            if (s[p + i] != t[i])
                return false;
        }
        return true;
    }

    static bool Calc(string s) {
        var dream = "dream";
        var dreamer = "dreamer";
        var erase = "erase";
        var eraser = "eraser";

        int p = s.Length-1;
        while (p >= 0) {
            if (s[p] == 'r') {
                if (Match(p - dreamer.Length + 1, s, dreamer)) {
                    p -= dreamer.Length;
                }
                else if (Match(p - eraser.Length + 1, s, eraser)) {
                    p -= eraser.Length;
                }
                else return false;
            }
            else if (s[p] == 'e') {
                if (Match(p - erase.Length + 1, s, erase)) {
                    p -= erase.Length;
                }
                else return false;
            }
            else if (s[p] == 'm') {
                if (Match(p - dream.Length + 1, s, dream)) {
                    p -= dream.Length;
                }
                else return false;
            }
            else return false;
        }
        return true;
    }

    static void Main() {
        var s = Console.ReadLine();

        if (Calc(s))
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}