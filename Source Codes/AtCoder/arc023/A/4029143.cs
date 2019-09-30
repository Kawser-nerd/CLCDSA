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
        int y = cin.Int();
        int m = cin.Int();
        int d = cin.Int();
        int now = 365 * 2014 + 2014 / 4 - 2014 / 100 + 2014 / 400 + 306 * (5 + 1) / 10 + 17 - 429;
        if(m <= 2) {
            m += 12;
            y -= 1;
        }
        int before = 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
        Console.WriteLine(now - before);
        Console.ReadLine();
    }
}