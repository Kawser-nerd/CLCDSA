using System.Collections.Generic;
using static System.Console;

class Program {
    static string[] maze;
    static int[, ] visited;
    static int[] s;
    static int[] g;

    static void Main() {
        var R = NextInt();
        var C = NextInt();
        var sy = NextInt();
        var sx = NextInt();
        var gy = NextInt();
        var gx = NextInt();
        s = new int[] { sy - 1, sx - 1 };
        g = new int[] { gy - 1, gx - 1 };

        maze = new string[R];
        for (var i = 0; i < R; i++) {
            maze[i] = NextString();
        }

        visited = new int[R, C];
        for (var i = 0; i < R; i++) {
            for (var j = 0; j < C; j++) {
                visited[i, j] = -1;
            }
        }
        WriteLine(bfs());
    }

    static int bfs() {
        var q = new Queue<int[]>();
        q.Enqueue(s);
        visited[s[0], s[1]] = 0;
        while (q.Count != 0) {
            int y = q.Peek()[0];
            int x = q.Dequeue()[1];
            if (g[0] == y && g[1] == x) {
                return visited[y, x];
            }
            for (var i = 0; i < 4; i++) {
                var kx = i % 2;
                var ky = kx ^ 1;
                if (i < 2) {
                    ky *= -1;
                    kx *= -1;
                }
                var y2 = y + ky;
                var x2 = x + kx;

                if (maze[y2][x2] == '.' && visited[y2, x2] < 0) {
                    visited[y2, x2] = visited[y, x] + 1;
                    q.Enqueue(new int[] { y2, x2 });
                }
            }
        }
        return 0;
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