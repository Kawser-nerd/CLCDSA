using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var s = NextString();
        var dic = new HashSet<char>[s.Length];
        var flg = false;

        foreach (var i in Enumerable.Range(0, s.Length)) {
            dic[i] = new HashSet<char> { s[i] };
        }

        while (true) {
            for (var c = 'a'; c <= 'z'; c++) {
                foreach (var i in Enumerable.Range(0, dic.Length)) {
                    if (!dic[i].Contains(c)) {
                        goto exitLoop;
                    }
                }
                flg = true;
                exitLoop: ;
            }
            foreach (var i in Enumerable.Range(0, dic.Length - 1)) {
                foreach (var v in dic[i + 1]) {
                    dic[i].Add(v);
                }
            }
            if (flg) {
                break;
            }
            dic = dic.Take(dic.Length - 1).ToArray();
        }
        WriteLine(s.Length - dic.Length);
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