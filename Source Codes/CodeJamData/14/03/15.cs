using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    char[][] Solve(int R, int C, int M)
    {
        var ret = Enumerable.Range(0, R).Select(r => Enumerable.Repeat('.', C).ToArray()).ToArray();
        ret[R - 1][C - 1] = 'c';
        if (R == 1 || C == 1)
        {
            for (int i = 0; i < M; i++)
            {
                if (R == 1) ret[0][i] = '*';
                else ret[i][0] = '*';
            }
            return ret;
        }

        for (int r = 1; r <= R; r++)
        {
            int m = M - C * (R - r);
            if (m < 0) continue;
            int c = C - m / r;
            if (c < 1) continue;
            m = m % r;

            if ((r == 1 && c != 1) || (r != 1 && c == 1) || (m != 0 && (c == 2 || r == 2 || r + c - 1 - m < 4))) continue;

            for (int i = 0; i < R - r; i++) for (int j = 0; j < C; j++) ret[i][j] = '*';
            for (int i = 0; i < R; i++) for (int j = 0; j < C - c; j++) ret[i][j] = '*';

            for (int i = R - r; i < R - 2 && m > 0; i++)
            {
                ret[i][C - c] = '*';
                m--;
            }
            for (int i = C - c + 1; i < C - 2 && m > 0; i++)
            {
                ret[R - r][i] = '*';
                m--;
            }
            return ret;
        }

        return null;
    }

    static IEnumerable<string> Output()
    {
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var result = new C().Solve(line[0], line[1], line[2]);
        yield return "";
        if (result == null) yield return "Impossible";
        else foreach (var r in result) yield return new string(r);
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}