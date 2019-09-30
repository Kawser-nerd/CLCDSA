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
        //string X = Console.ReadLine();
        //string tmp = "";
        //long cnt = 0; //??????
        //for (int i = 0; i < X.Length; i++) {
        //    if(X[i] == 'S') {
        //        if (tmp == "") tmp += "S";
        //        else if (tmp[tmp.Length - 1] == 'S') tmp += "S";
        //        else {
        //            cnt += 2 * Math.Min(tmp.ToCharArray().Count(x => x == 'S'), tmp.ToCharArray().Count(x => x == 'T'));
        //            tmp = "S";
        //        }
        //    }
        //    else {
        //        if (tmp != "") tmp += "T";
        //    }
        //}

        //cnt += Math.Min(tmp.ToCharArray().Count(x => x == 'S'), tmp.ToCharArray().Count(x => x == 'T'));
        //Console.WriteLine(X.Length - cnt);

        int N = cin.Int();
        var L = cin.ArrayInt(2*N);
        Array.Sort(L);
        int ans = 0;
        for (int i = L.Length - 2; i >= 0; i -= 2) {
            ans += L[i];
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}