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
        int N = cin.Int();
        int M = cin.Int();

        var dic = new Dictionary<int, int>();
        int i = 2;
        int MM = M;
        while(i * i <= M) {
            if(MM % i == 0) {
                if (dic.ContainsKey(i)) dic[i]++;
                else dic[i] = 1;
                MM /= i;
            }
            else i++;
        }
        if (MM > 1) dic[MM] = 1;

        long ans = 1;
        foreach (var val in dic.Values) {
            ans = ans % 1000000007 * mod_combination(val + N - 1, val);
        }
        Console.WriteLine(ans % 1000000007);
        Console.ReadLine();
    }
    static int mod_combination(int n, int r) {
        int mod = 1000000007;
        long res = 1;
        long den = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % mod;
            if (i == n - r || i == r) {
                den = (den * res) % mod;
                if (n - r == r) den = (den * res) % mod;
            }
        }
        long rev = mod_power((int)den, mod - 2);
        return (int)((res * rev) % mod);
    }
    static int mod_power(int n, int m) {
        const int mod = 1000000007;
        long pow = n;
        long res = 1;
        while (m > 0) {
            if ((m & 1) == 1) res = (res * pow) % mod;
            pow = (pow * pow) % mod;
            m >>= 1;
        }
        return (int)res;
    }

}