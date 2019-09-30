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
    struct p {
        public int x1, y1, x2, y2; //(x1,y1):???????(x2,y2):??????
        public p(int X1, int Y1, int X2, int Y2) {
            x1 = X1;
            y1 = Y1;
            x2 = X2;
            y2 = Y2;
        }
    }
    static Scanner cin = new Scanner();
    static void Main() {
        int H = cin.Int();
        int W = cin.Int();
        var a = new int[H, W];
        for (int i = 0; i < H; i++) {
            var tmp = cin.ArrayInt(W);
            for (int j = 0; j < W; j++) {
                a[i, j] = tmp[j];
            }
        }

        var list = new List<p>();
        int cnt = 0;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W - 1; j++) {
                if(a[i, j] % 2 != 0) {
                    list.Add(new p(j, i, j + 1, i));
                    a[i, j]--;
                    a[i, j + 1]++;
                    cnt++;
                }
            }
        }

        for (int i = 0; i < H - 1; i++) {
            if(a[i, W - 1] % 2 != 0) {
                list.Add(new p(W - 1, i, W - 1, i + 1));
                a[i, W - 1]--;
                a[i + 1, W - 1]++;
                cnt++;
            }
        }

        Console.WriteLine(cnt);
        foreach (var point in list) {
            Console.WriteLine("{0} {1} {2} {3}", point.y1 + 1, point.x1 + 1, point.y2 + 1, point.x2 + 1);
        }
        Console.ReadLine();
    }
}