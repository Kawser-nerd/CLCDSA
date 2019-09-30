using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    const int mod = 1000000007;

    static void Main() {
#if USE_IDE
        var exStdIn = new System.IO.StreamReader("./../../TestStdin.txt");
        Console.SetIn(exStdIn);
#endif
        var args = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        var N = args[0];
        var M = args[1];
        var cakes = new List<Cake>();
        for (int i = 0; i < N; i++) {
            var a = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
            cakes.Add(new Cake() {x = a[0], y = a[1], z = a[2]});
        }

        var sums = new long[8][];
        for (int i = 0; i < 8; i++) {
            sums[i] = new long[N];
        }

        for (int i = 0; i < N; i++) {
            sums[0][i] = cakes[i].x + cakes[i].y + cakes[i].z;
            sums[1][i] = cakes[i].x + cakes[i].y - cakes[i].z;
            sums[2][i] = cakes[i].x - cakes[i].y + cakes[i].z;
            sums[3][i] = cakes[i].x - cakes[i].y - cakes[i].z;
            sums[4][i] = -cakes[i].x + cakes[i].y + cakes[i].z;
            sums[5][i] = -cakes[i].x + cakes[i].y - cakes[i].z;
            sums[6][i] = -cakes[i].x - cakes[i].y + cakes[i].z;
            sums[7][i] = -cakes[i].x - cakes[i].y - cakes[i].z;
        }

        for (int i = 0; i < 8; i++) {
            Array.Sort(sums[i]);
            Array.Reverse(sums[i]);
        }

        var anss = new long[8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < M; j++) {
                anss[i] += sums[i][j];
            }
        }

        Console.WriteLine(anss.Max());
    }

    class Cake {
        public long x;
        public long y;
        public long z;
    }
}