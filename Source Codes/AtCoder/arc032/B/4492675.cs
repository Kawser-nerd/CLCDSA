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
public class UnionFind {
    private int[] data;

    public UnionFind(int size) { //???
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = -1;
    }

    public bool Unite(int x, int y) { //x???????????y???????????????
        x = Root(x);
        y = Root(y);

        if (x != y) {
            if (data[y] < data[x]) {
                var tmp = y;
                y = x;
                x = tmp;
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    public bool IsSameGroup(int x, int y) { //x?y?????????????????
        return Root(x) == Root(y);
    }

    public int Root(int x) { //???x??????
        return data[x] < 0 ? x : data[x] = Root(data[x]);
    }

    public int Size(int x) => -data[Root(x)];
}

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int M = cin.Int();
        var uf = new UnionFind(N + 10);

        var A = new int[M];
        var B = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = cin.Int();
            B[i] = cin.Int();
            if(!uf.IsSameGroup(A[i], B[i])) {
                uf.Unite(A[i], B[i]);
            }
        }

        var hash = new HashSet<int>();
        for (int i = 1; i <= N; i++) {
            hash.Add(uf.Root(i));
        }
        Console.WriteLine(hash.Count - 1);
        Console.ReadLine();
    }
}