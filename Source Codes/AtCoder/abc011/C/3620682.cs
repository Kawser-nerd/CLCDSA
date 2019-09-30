using System.Collections.Generic;
using static System.Console;

class Program {
    static int n0;
    static int[] visited;
    static int[] ng = new int[3];

    static void Main() {
        n0 = NextInt();

        visited = new int[n0 + 1];
        for (var i = 0; i <= n0; i++) {
            visited[i] = -1;
        }

        for (var i = 0; i < 3; i++) {
            ng[i] = NextInt();
        }
        WriteLine(BFS());
    }

    static string BFS() {
        visited[n0] = 0;
        var q = new Queue<int>();
        q.Enqueue(n0);

        while (q.Count > 0 && !Contains(ng, n0)) {
            var n = q.Dequeue();

            if (visited[n] > 100) {
                break;
            } else if (n == 0) {
                return "YES";
            }

            for (var v = 1; v <= 3; v++) {
                var n2 = n - v;
                if (n2 >= 0 && !Contains(ng, n2) && visited[n2] < 0) {
                    visited[n2] = visited[n] + 1;
                    q.Enqueue(n2);
                }
            }
        }
        return "NO";
    }

    static bool Contains(int[] s, int e) {
        foreach (var v in s) {
            if (v == e) { return true; }
        }
        return false;
    }

    static int NextInt() {
        return int.Parse(NextString());
    }

    static string NextString() {
        var result = new List<char>();
        while (true) {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}