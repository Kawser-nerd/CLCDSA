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
        int x = cin.Int();
        if(N == 2 && x == 2) {
            Console.WriteLine("Yes");
            for (int i = 1; i <= 3; i++) {
                Console.WriteLine(i);
            }
        }
        else if (2 <= x && x <= 2 * N - 2) {
            Console.WriteLine("Yes");
            var list = new List<int>();
            for (int i = 1; i < 2 * N; i++) list.Add(i);
            if(x == 2) {
                for (int j = x - 1; j <= x + 2; j++) {
                    list.Remove(j);
                }
                for (int j = 0; j < N - 2; j++) {
                    Console.WriteLine(list[j]);
                }
                Console.WriteLine(x + 1);
                Console.WriteLine(x);
                Console.WriteLine(x - 1);
                Console.WriteLine(x + 2);
                for (int j = N - 2; j < 2 * N - 5; j++) {
                    Console.WriteLine(list[j]);
                }
            }
            else {
                for (int j = x - 2; j <= x + 1; j++) {
                    list.Remove(j);
                }
                for (int j = 0; j < N - 2; j++) {
                    Console.WriteLine(list[j]);
                }
                Console.WriteLine(x - 1);
                Console.WriteLine(x);
                Console.WriteLine(x + 1);
                Console.WriteLine(x - 2);
                for (int j = N - 2; j < 2 * N - 5; j++) {
                    Console.WriteLine(list[j]);
                }
            }
        }
        else Console.WriteLine("No");
        Console.ReadLine();
    }
}