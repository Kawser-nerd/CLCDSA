using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Program {

    static public long DivLower(long x, long y) {
        if (y < 0) return DivLower(-x, -y);
        if (x >= 0) return x / y;
        return x / y - (x % y == 0 ? 0 : 1);
    }

    static public long DivUpper(long x, long y) {
        if (y < 0) return DivUpper(-x, -y);
        if (x <= 0) return x / y;
        return x / y + (x % y == 0 ? 0 : 1);
    }

    static public long LowerTime(long hhmm) {
        var mm = DivLower(hhmm % 100, 5) * 5;
        var hh = hhmm / 100;
        if (mm == 60) { hh++; mm = 0; }
        return 100 * hh + mm;
    }

    static public long UpperTime(long hhmm) {
        var mm = DivUpper(hhmm % 100, 5) * 5;
        var hh = hhmm / 100;
        if (mm == 60) { hh++; mm = 0; }
        return 100 * hh + mm;
    }

    public static void Main(string[] args) {
        int N = int.Parse(Console.ReadLine());
        var data = Enumerable.Range(0, N)
            .Select(_ => Console.ReadLine())
            .Select(s => s.Split(new[] { '-' }))
            .Select(a => new { from = LowerTime(int.Parse(a[0])), to = UpperTime(int.Parse(a[1])) })
            .OrderBy(v => v.from)
            .ThenBy(v => v.to)
            .ToArray();

        for (int i = 0; i < data.Length; ) {
            long minTime = data[i].from;
            long maxTime = data[i].to;
            int j = i;
            while (j + 1 < data.Length && data[j + 1].from <= maxTime) {
                maxTime = Math.Max(data[j + 1].to, maxTime);
                j++;
            }
            Console.WriteLine(String.Format("{0:0000}-{1:0000}", minTime, maxTime));
            i = j + 1;
        }
    }
}