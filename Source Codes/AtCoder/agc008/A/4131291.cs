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
        int x = cin.Int();
        int y = cin.Int();

        if(Math.Abs(x) < Math.Abs(y)) {
            if(y > 0) {
                if (x >= 0) Console.WriteLine(y - x);
                else Console.WriteLine(1 + y - (-x));
            }
            else {
                if (x >= 0) Console.WriteLine(1 + (-y) - x);
                else Console.WriteLine(1 + (-y) - (-x) + 1);
            }
        }
        else {
            if(y > 0) {
                if (x >= 0) Console.WriteLine(1 + (-y) - (-x) + 1);
                else Console.WriteLine((-y) - x + 1);
            }
            else if(y == 0) {
                if (x >= 0) Console.WriteLine(1 + x);
                else Console.WriteLine(-x);
            }
            else {
                if (x >= 0) Console.WriteLine(1 + y - (-x));
                else Console.WriteLine(y - x);
            }
        }
        Console.ReadLine();
    }
}