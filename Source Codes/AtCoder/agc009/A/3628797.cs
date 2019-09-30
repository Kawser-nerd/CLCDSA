using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var N = NextInt();
        var A = new long[N];
        var B = new long[N];
        var ans = 0L;

        for (var i = 0; i < N; i++) {
            A[i] = NextInt();
            B[i] = NextInt();
        }

        for (var i = N - 1; i >= 0; i--) {
            A[i] += ans;
            if (A[i] % B[i] != 0) {
                ans += Math.Abs(A[i] % B[i] - B[i]);
            }
        }
        WriteLine(ans);
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