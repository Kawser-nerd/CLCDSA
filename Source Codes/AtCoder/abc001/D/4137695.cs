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
        var time = new int[1445];
        for (int i = 0; i < N; i++) {
            var input = Console.ReadLine().Split('-').Select(int.Parse).ToArray();

            
            if (input[0] % 5 != 0) input[0] -= input[0] % 5;
            if (input[1] % 5 != 0) input[1] += 5 - input[1] % 5;
            time[60 * (input[0] / 100) + input[0] % 100]++;
            time[60 * (input[1] / 100) + input[1] % 100]--;
        }

        var sum = new int[1445];
        for (int i = 1; i <= 1441; i++) {
            sum[i] = sum[i - 1] + time[i - 1];
        }
        var list = new List<int>();
        for (int i = 1; i <= 1441; i++) {
            if ((sum[i] == 0 && sum[i - 1] > 0) || (sum[i] > 0 && sum[i - 1] == 0)) list.Add(i - 1);
        }

        if (list.Count % 2 != 0) list.Add(2400);
        for (int i = 0; i <= list.Count - 1; i += 2) {
            Console.WriteLine("{0:0000}-{1:0000}", list[i] / 60 * 100 + list[i] % 60, list[i + 1] / 60 * 100 + list[i + 1] % 60);
        }
        Console.ReadLine();
    }
}