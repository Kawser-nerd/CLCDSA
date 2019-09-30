using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    static Boolean[] visited;
    static Boolean[,] con;
    static int N;

    internal static void Main(string[] args) {
        var inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
        N = inp[0];
        var M = inp[1];
        con = new Boolean[N + 1, N + 1];
        var a = new List<int>();
        var b = new List<int>();
        for (int i = 0; i < M;i++) {
            inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
            inp[0]--;
            inp[1]--;
            a.Add(inp[0]);
            b.Add(inp[1]);
            con[inp[0], inp[1]] = true;
            con[inp[1], inp[0]] = true;
        }

        int ans = 0;
        for (int i = 0; i < M; i++) {
            Change(a[i], b[i], false);
            visited = new Boolean[N];
            DFS(0);
            if (visited.Any(boo => boo == false)) {
                ans++;
            }
            Change(a[i], b[i], true);
        }
        WriteLine(ans);
    }

    static void DFS(int x) {
        visited[x] = true;
        for (int i = 0; i < N; i++) {
            if (con[x,i] == false) { continue; }
            if (visited[i] == true) { continue; }
            DFS(i);
        }
    }

    static void Change(int a, int b, Boolean boo) {
        con[a, b] = boo;
        con[b, a] = boo;
    }
}