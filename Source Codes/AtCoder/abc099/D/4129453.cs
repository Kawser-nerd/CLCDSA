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
        int C = cin.Int();
        var D = new int[35, 35];
        for (int i = 0; i < C; i++) {
            var tmp = cin.ArrayInt(C);
            for (int j = 0; j < C; j++) {
                D[i, j] = tmp[j];
            }
        }
        var c = new int[5, 35];
        for (int i = 0; i < N; i++) {
            var tmp = cin.ArrayInt(N);
            for (int j = 0; j < N; j++) {
                c[(i + j) % 3, tmp[j] - 1]++; //???3?????????????
            }
        }

        int ans = int.MaxValue;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                for (int k = 0; k < C; k++) {
                    if(i != j && j != k && k != i) { //????????????
                        int tmp = 0;
                        for (int l = 0; l < C; l++) {
                            tmp += D[l, i] * c[0, l];
                        }
                        for (int l = 0; l < C; l++) {
                            tmp += D[l, j] * c[1, l];
                        }
                        for (int l = 0; l < C; l++) {
                            tmp += D[l, k] * c[2, l];
                        }
                        ans = Math.Min(ans, tmp);
                    }
                }
            }
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}