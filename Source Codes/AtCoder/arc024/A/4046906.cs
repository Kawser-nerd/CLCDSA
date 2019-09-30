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
        int L = cin.Int();
        int R = cin.Int();
        var l = cin.ArrayInt(L);
        var r = cin.ArrayInt(R);

        var l_dic = new Dictionary<int, int>();
        var r_dic = new Dictionary<int, int>();
        for (int i = 0; i < L; i++) {
            if (l_dic.ContainsKey(l[i])) l_dic[l[i]]++;
            else l_dic[l[i]] = 1;
        }
        for (int i = 0; i < R; i++) {
            if (r_dic.ContainsKey(r[i])) r_dic[r[i]]++;
            else r_dic[r[i]] = 1;
        }

        int ans = 0;
        foreach (var key in l_dic.Keys) {
            if (r_dic.ContainsKey(key)) ans += Math.Min(l_dic[key], r_dic[key]);
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}