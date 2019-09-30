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
        long A = cin.Long();
        long B = cin.Long();
        long C = cin.Long();

        int cnt = 0;
        if (A % 2 == 0 && B % 2 == 0 && C % 2 == 0 && A == C && B == C) Console.WriteLine(-1);
        else {
            while (true) {
                long tmpa = A, tmpb = B, tmpc = C;
                if (tmpa % 2 != 0 || tmpb % 2 != 0 || tmpc % 2 != 0) break;
                A = tmpb / 2 + tmpc / 2;
                B = tmpc / 2 + tmpa / 2;
                C = tmpa / 2 + tmpb / 2;
                cnt++;
            }
            Console.WriteLine(cnt);
        }
        Console.ReadLine();
    }
}