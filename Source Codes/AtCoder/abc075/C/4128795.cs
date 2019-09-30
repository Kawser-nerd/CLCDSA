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
    static bool[] visited = new bool[55];
    static bool[,] graph = new bool[55, 55]; //????
    static int N = cin.Int();
    static int M = cin.Int();
  
    static void Main() {
        var a = new int[M];
        var b = new int[M];

        for (int i = 0; i < M; i++) {
            a[i] = cin.Int();
            b[i] = cin.Int();
            graph[a[i], b[i]] = true;
            graph[b[i], a[i]] = true;
        }

        int ans = 0;
        for (int i = 0; i < M; i++) {
            //i??????????????????
            graph[a[i], b[i]] = false;
            graph[b[i], a[i]] = false;

            //?????????????
            for (int j = 1; j <= N; j++) {
                visited[j] = false;
            }

            dfs(1);

            bool bridge = false;
            for (int j = 1; j <= N; j++) {
                if (visited[j] == false) bridge = true; //1???????????????????????
            }
            if (bridge) ans++;

            //?????
            graph[a[i], b[i]] = true;
            graph[b[i], a[i]] = true;
        }

        Console.WriteLine(ans);
        Console.ReadLine();
    }

    static void dfs(int v) {
        visited[v] = true; //??v????????
        for (int i = 1; i <= N; i++) {
            if (graph[v, i] == false) continue; //??v???i?????????????
            if (visited[i] == true) continue; //??i???????????????
            dfs(i);
        }
    }
}