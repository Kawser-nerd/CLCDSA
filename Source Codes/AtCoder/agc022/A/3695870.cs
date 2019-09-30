using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var s = NextString();
        var t = new char[s.Length];
        for (var i = 0; i < s.Length; i++) {
            t[i] = s[i];
        }

        for (var v = 'a'; v <= 'z'; v++) {
            if (!s.Contains(v.ToString())) {
                WriteLine(s + v);
                return;
            }
        }
        if (!NextPermutation(t)) {
            WriteLine(-1);
        } else {
            var i = 0;
            while (s[i] == t[i]) {
                Write(s[i]);
                i++;
            }
            WriteLine(t[i]);
        }
    }

    static bool NextPermutation(char[] t) {
        var n = t.Length;
        var i = n - 2;
        while (i >= 0 && t[i] >= t[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        var j = i + 1;
        while (j < n && t[j] > t[i]) {
            j++;
        }
        j--;
        var tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;

        var left = i + 1;
        var right = n - 1;

        while (left < right) {
            tmp = t[left];
            t[left] = t[right];
            t[right] = tmp;

            left++;
            right--;
        }
        return true;
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