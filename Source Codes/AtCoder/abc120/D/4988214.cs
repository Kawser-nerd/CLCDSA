using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static MyUtil;

class MyUtil {
    public static void Swap<T>(ref T a, ref T b){
        var t = a;
        a = b;
        b = t;
    }

    public static int[] ReadIntArray(){
        return ReadLine().Split().Select(x => int.Parse(x)).ToArray();
    }

    public static long[] ReadLongArray(){
        return ReadLine().Split().Select(x => long.Parse(x)).ToArray();
    }
}

class UnionFind {
    private int[] d;

    public UnionFind(int n){
        d = new int[n];
        for (int i = 0; i < n; i++){ d[i] = -1; }
    }

    public int find(int x){
        if (d[x] < 0){ return x; }
        return d[x] = find(d[x]);
    }

    public void unite(int x, int y){
        x = find(x); y = find(y);
        if (x == y){ return; }
        if (d[x] > d[y]){ Swap(ref x, ref y); }
        d[x] += d[y];
        d[y] = x;
    }

    public bool same(int x, int y){ return find(x) == find(y); }
    public int size(int x){ return -d[find(x)]; }
}

class Program {
    public static void Main(){
        Solve();
    }

    private static void Solve(){
        var t = ReadIntArray();
        int n = t[0];
        int m = t[1];

        var v = new Tuple<int, int>[m];
        for (int i = 0; i < m; i++){
            int a, b;
            var tt = ReadIntArray();
            a = tt[0]; b = tt[1];
            v[i] = Tuple.Create(a-1, b-1);
        }

        var uf = new UnionFind(n);

        var ans = new long[m];
        long curr = (long) n * (n - 1) / 2;
        int j = 0;
        ans[j++] = curr;

        for (int i = m - 1; i > 0; i--){
            int a = v[i].Item1;
            int b = v[i].Item2;
            if (! uf.same(a, b)){
                curr -= (long) uf.size(a) * uf.size(b);
                uf.unite(a, b);
            }
            ans[j++] = curr;
        }

        for (int i = m - 1; i >= 0; i--){
            WriteLine(ans[i]);
        }
    }
}