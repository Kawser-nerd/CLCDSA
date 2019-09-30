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
        int n = cin.Int();
        int m = cin.Int();
        int l = cin.Int();
        int p = cin.Int();
        int q = cin.Int();
        int r = cin.Int();
        var ans = new int[] { (n / p) * (m / q) * (l / r), (n / p) * (m / r) * (l / q), (n / q) * (m / p) * (l / r), (n / q) * (m / r) * (l / p), (n / r) * (m / p) * (l / q), (n / r) * (m / q) * (l / p) };
        Console.WriteLine(ans.Max());
        Console.ReadLine();
    }
}