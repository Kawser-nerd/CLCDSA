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
        int N = cin.Int();
        var S = new string[N];
        for (int i = 0; i < N; i++) {
            S[i] = Console.ReadLine();
        }

        int m = 0, a = 0, r = 0, c = 0, h = 0;
        foreach (var s in S) {
            if (s[0] == 'M') m++;
            else if (s[0] == 'A') a++;
            else if (s[0] == 'R') r++;
            else if (s[0] == 'C') c++;
            else if (s[0] == 'H') h++;
        }

        var x1 = new int[] { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0 };
        var x2 = new int[] { 1, 1, 1, 0, 0, 1, 1, 0, 1, 0 };
        var x3 = new int[] { 1, 0, 0, 1, 1, 1, 1, 0, 0, 1 };
        var x4 = new int[] { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 };
        var x5 = new int[] { 0, 0, 1, 0, 1, 0, 1, 1, 1, 1 };

        long ans = 0;
        for (int i = 0; i < 10; i++) {
            long tmp = 1;
            if (x1[i] != 0) tmp *= m;
            if (x2[i] != 0) tmp *= a;
            if (x3[i] != 0) tmp *= r;
            if (x4[i] != 0) tmp *= c;
            if (x5[i] != 0) tmp *= h;
            ans += tmp;
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}