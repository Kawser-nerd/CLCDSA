using System;
using System.Collections.Generic;
using System.Linq;
class Scanner //????
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
    static void Main(string[] args) {
        int N = cin.Int();
        long M = cin.Long();
        var A = cin.ArrayLong(N);

        var sum = new long[100010];
        for (int i = 1; i <= N; i++) {
            sum[i] = A[i - 1] + sum[i - 1];
        }
        for (int i = 1; i <= N; i++) {
            sum[i] %= M;
        }

        var dic = new Dictionary<long, long>();
        dic[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (dic.ContainsKey(sum[i])) dic[sum[i]]++;
            else dic[sum[i]] = 1;
        }

        long ans = 0;
        foreach (var k in dic.Values) { 
           ans += k * (k - 1) / 2;
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}