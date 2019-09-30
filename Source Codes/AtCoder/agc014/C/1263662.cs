using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AGC014
{
    public class C
    {
        private void Run()
        {
            var input = Console.ReadLine().Trim().Split();
            var H = int.Parse(input[0]);
            var W = int.Parse(input[1]);
            var K = int.Parse(input[2]);
            var field = Enumerable.Range(0, H).Select(_ => Console.ReadLine().Trim().ToCharArray()).ToArray();

            var beginY = Array.FindIndex(field, line => line.Contains('S'));
            var beginX = Array.IndexOf<char>(field[beginY], 'S');

            var q = new Queue<Tuple<int, int, int>>(); // [x, y, rest]
            q.Enqueue(Tuple.Create(beginX, beginY, K));
            field[beginY][beginX] = '#';

            var minX = beginX;
            var maxX = beginX;
            var minY = beginY;
            var maxY = beginY;

            var dist = new[] { 1, 0, -1, 0, 1 };
            while (q.Count > 0)
            {
                var t = q.Dequeue();
                var x = t.Item1;
                var y = t.Item2;
                var rest = t.Item3;
                minX = Math.Min(minX, x);
                maxX = Math.Max(maxX, x);
                minY = Math.Min(minY, y);
                maxY = Math.Max(maxY, y);

                if (rest == 0) { continue; }
                for (int i = 0; i < 4; i++)
                {
                    var nx = x + dist[i];
                    var ny = y + dist[i + 1];

                    if (nx < 0 || nx >= W || ny < 0 || ny >= H) { continue; }
                    if (field[ny][nx] == '#') { continue; }
                    field[ny][nx] = '#';
                    q.Enqueue(Tuple.Create(nx, ny, rest - 1));
                }
            }

            var d = int.MaxValue;
            d = Math.Min(d, minX);
            d = Math.Min(d, minY);
            d = Math.Min(d, W - 1 - maxX);
            d = Math.Min(d, H - 1 - maxY);

            Console.WriteLine(1 + (d + K - 1) / K);
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}