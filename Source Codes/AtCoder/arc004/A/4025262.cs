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
        var x = new int[N];
        var y = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = cin.Int();
            y[i] = cin.Int();
        }
        var distance = new List<double>();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if(i != j) {
                    double tmp = Math.Sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                    distance.Add(tmp);
                }
            }
        }
        distance.Sort();
        Console.WriteLine(distance[distance.Count - 1]);
        Console.ReadLine();
    }
}