using System.Linq;
using System;
class Program
{
    static void Main()
    {
        // ??
        var NMQ = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var N = NMQ[0];
        var M = NMQ[1];
        var Q = NMQ[2];
        var S = new int[N + 1, M + 1];
        for (int i = 1; i <= N; i++)
        {
            var s = Console.ReadLine();
            for (int j = 1; j <= M; j++)
            {
                S[i, j] = s[j - 1] - '0';
            }
        }
        var XY = new int[Q, 4];
        for (int i = 0; i < Q; i++)
        {
            var line = Console.ReadLine().Split(' ');
            XY[i, 0] = int.Parse(line[0]);
            XY[i, 1] = int.Parse(line[1]);
            XY[i, 2] = int.Parse(line[2]);
            XY[i, 3] = int.Parse(line[3]);
        }

        // ??
        var cell = new int[N + 1, M + 1];
        var edgeX = new int[N + 1, M + 1];
        var edgeY = new int[N + 1, M + 1];
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cell[i, j] += cell[i - 1, j] + cell[i, j - 1] - cell[i - 1, j - 1] + S[i, j];
                edgeX[i, j] += edgeX[i - 1, j] + edgeX[i, j - 1] - edgeX[i - 1, j - 1] + (S[i, j] & S[i - 1, j]);
                edgeY[i, j] += edgeY[i - 1, j] + edgeY[i, j - 1] - edgeY[i - 1, j - 1] + (S[i, j] & S[i, j - 1]);
            }
        }
        for (int q = 0; q < Q; q++)
        {
            int x1 = XY[q, 0], y1 = XY[q, 1], x2 = XY[q, 2], y2 = XY[q, 3];
            var edgesX = edgeX[x2, y2] - edgeX[x1, y2] - edgeX[x2, y1 - 1] + edgeX[x1, y1 - 1];
            var edgesY = edgeY[x2, y2] - edgeY[x1 - 1, y2] - edgeY[x2, y1] + edgeY[x1 - 1, y1];
            var cells = cell[x2, y2] - cell[x1 - 1, y2] - cell[x2, y1 - 1] + cell[x1 - 1, y1 - 1];
            Console.WriteLine(cells - edgesX - edgesY);
        }
    }
}