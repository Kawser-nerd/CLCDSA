using System;
using System.Collections.Generic;
using System.Linq;
class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner() {
        s = new string[0];
        i = 0;
    }

    public string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int Int() {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0) {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long() {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0) {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Long() + add;
        }
        return Array;
    }
}
class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        string S = Console.ReadLine();
        const int mod = 1000000007;

        var dp = new long[100010, 5];
        for (int i = S.Length; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                if (i == S.Length) dp[i, j] = j == 3 ? 1 : 0;
                else {
                    dp[i, j] = dp[i + 1, j] * (S[i] == '?' ? 3 : 1);
                    if (j < 3 && (S[i] == '?' || S[i] == "ABC"[j])) {
                        dp[i, j] += dp[i + 1, j + 1];
                    }
                    dp[i, j] %= mod;
                }
            }
        }
        Console.WriteLine(dp[0, 0]);
        Console.ReadLine();
    }
}