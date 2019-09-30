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
    private int[] par, rank; //??????

    public UnionFind(int size) { //???
        par = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    public void Unite(int x, int y) { //x???????????y???????????????
        //???????????
        x = Find(x);
        y = Find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }    
    }

    public bool Same(int x, int y) { //x?y?????????????????
        return Find(x) == Find(y);
    }

    public int Find(int x) { //???x??????
        if(par[x] == x) {
            return x;
        }
        else {
            return par[x] = Find(par[x]);
        }
    }

    public int Size(int x) => par[Find(x)];
}

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int M = cin.Int();

        var uf = new UnionFind(N);
        for (int i = 0; i < M; i++) {
            int a = cin.Int() - 1;
            int b = cin.Int() - 1;
            uf.Unite(a, b);
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if(!uf.Same(i, 0)) {
                uf.Unite(i, 0);
                ans++;
            }
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}