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
        int H = cin.Int();
        int W = cin.Int();
        var S = Enumerable.Repeat(0, H).Select(_ => Console.ReadLine()).ToArray();
        var line = new bool[H];
        var row = new bool[W];
        for (int i = 0; i < H; i++) { 
            for (int j = 0; j < W; j++) {
                if(S[i][j] == '#') {
                    line[i] = true;
                    row[j] = true;
                }
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (line[i] && row[j]) {
                    Console.Write(S[i][j].ToString());
                }
            }
            if(line[i])Console.WriteLine();
        }
        Console.ReadLine();
    }
}