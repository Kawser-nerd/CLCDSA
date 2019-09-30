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
        long N = cin.Long();
        long X = cin.Long();

        Console.WriteLine(burger(N, X));
        Console.ReadLine();
    }

    static long burger(long n, long x) {
        if (x == 1) return 0;
        if (n == 1) {
            if (x == 1) return 0;
            else if (x == 2) return 1;
            else if (x == 3) return 2;
            else return 3;
        }
        else if(x <= Math.Pow(2, n + 1) - 2) {
            return burger(n - 1, x - 1);
        }else if(x == Math.Pow(2, n + 1) - 1) {
            return burger(n - 1, (long)Math.Pow(2, n + 1) - 3) + 1;
        }
        else if(x <= Math.Pow(2, n + 2) - 4){
            return burger(n - 1, (long)Math.Pow(2, n + 1) - 3) + 1 + burger(n - 1, x - (long)Math.Pow(2, n + 1) + 1);
        }
        else {
            return 2 * burger(n - 1, (long)Math.Pow(2, n + 1) - 3) + 1;
        }
    }
}