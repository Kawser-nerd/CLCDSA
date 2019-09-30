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
    static Dictionary<int, int> dic = new Dictionary<int, int>();
    static void Main() {
        int N = cin.Int();
        prime_factorization(N);

        int n74 = 0, n24 = 0, n14 = 0, n4 = 0, n2 = 0;
        foreach (var v in dic.Values) {
            if (v >= 74) n74++;
            if (v >= 24) n24++;
            if (v >= 14) n14++;
            if (v >= 4) n4++;
            if (v >= 2) n2++;
        }

        long ans = 0;

        ans += n74;
        ans += n24 * (n2 - 1);
        ans += n14 * (n4 - 1);
        if (n4 >= 2 && n2 >= 2) ans += n4 * (n4 - 1) / 2 * (n2 - 2);
        Console.WriteLine(ans);
        Console.ReadLine();
    }

    static void prime_factorization(int n) //Key:??, Value:??
    {
        for (int j = 1; j <= n; j++) {
            int i = 2, tmp = j;
            while (i * i <= j) {
                if (tmp % i == 0) {
                    if (dic.ContainsKey(i)) dic[i]++;
                    else dic[i] = 1;
                    tmp /= i;
                }
                else i++;
            }
            if (tmp > 1) {
                if (dic.ContainsKey(tmp)) dic[tmp]++;
                else dic[tmp] = 1;
            }
        }
    }

}