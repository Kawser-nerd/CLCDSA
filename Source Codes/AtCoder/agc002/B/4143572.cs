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
        int M = cin.Int();

        var box = new int[100010]; //??????????
        var flag = new bool[100010]; //???????????
        flag[1] = true;

        for (int i = 1; i <= N; i++) {
            box[i] = 1;
        }
        for (int i = 0; i < M; i++) {
            int x = cin.Int();
            int y = cin.Int();
            if (flag[x]) flag[y] = true;
            if (box[x] == 1) flag[x] = false;
            box[x]--;
            box[y]++;
        }

        Console.WriteLine(flag.Count(x => x == true));
        Console.ReadLine();
    }
}