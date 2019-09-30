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
        var S = new string[4,4];
        for (int i = 0; i < 4; i++) {
            var tmp = Console.ReadLine().Split().ToArray();
            for (int j = 0; j < 4; j++) {
                S[i, j] = tmp[j];
            }
        }
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (S[i, j] == S[i, j + 1]) flag = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (S[i, j] == S[i + 1, j]) flag = true;
            }
        }
        Console.WriteLine(flag ? "CONTINUE" : "GAMEOVER");
        Console.ReadLine();
    }
}