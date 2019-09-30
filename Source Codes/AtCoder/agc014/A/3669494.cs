using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var a = NextInt();
        var b = NextInt();
        var c = NextInt();
        var ans = 0;
        var dic = new List<int[]>();
        var flg = false;

        while (true) {
            var abc = new int[] { a, b, c };
            Array.Sort(abc);
            if (Contains(dic, abc)) {
                ans = -1;
            }
            foreach (var v in abc) {
                if (v % 2 != 0) {
                    flg = true;
                }
            }
            if (flg || ans < 0) {
                break;
            }
            ans++;
            dic.Add(abc);
            var x = b / 2 + c / 2;
            var y = c / 2 + a / 2;
            var z = a / 2 + b / 2;
            a = x;
            b = y;
            c = z;
        }
        WriteLine(ans);
    }

    static bool Contains(List<int[]> dic, int[] abc) {
        foreach (var dic_i in dic) {
            var flg = false;
            var j = 0;
            foreach (var dic_ij in dic_i) {
                if (dic_ij != abc[j]) {
                    flg = true;
                }
                j++;
            }
            if (!flg) {
                return true;
            }
        }
        return false;
    }

    static int NextInt() {
        return int.Parse(NextString());
    }

    static string NextString() {
        var result = new List<char>();
        while (true) {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}