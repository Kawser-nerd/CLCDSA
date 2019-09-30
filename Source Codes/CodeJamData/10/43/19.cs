using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    struct Node
    {
        public int x1, x2, y1, y2;
    }

    class Program
    {
        static void Main(string[] args)
        {
            bool[,] a;
            using (var reader = new StreamReader("C.in"))
            using (var writer = new StreamWriter("C.out"))
            {
                int testCount = int.Parse(reader.ReadLine());
                for (int test = 1; test <= testCount; ++test)
                {
                    int r = int.Parse(reader.ReadLine());
                    List<Node> rects = new List<Node>();
                    for (int i = 0; i < r; ++i)
                    {
                        var line = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                        int x1 = line[0], y1 = line[1], x2 = line[2], y2 = line[3];
                        rects.Add(new Node { x1 = x1, x2 = x2, y1 = y1, y2 = y2 });
                    }
                    int n = rects.Max(no => Math.Max(no.y1, no.y2));
                    int m = rects.Max(no => Math.Max(no.x1, no.x2));
                    a = new bool[n + 1, m + 1];
                    for (int i = 0; i < r; ++i)
                        for (int j = rects[i].x1; j <= rects[i].x2; ++j)
                            for (int k = rects[i].y1; k <= rects[i].y2; ++k)
                                a[k, j] = true;

                    int total = 0;
                    for (int i = 0; i <= n; ++i)
                        for (int j = 0; j <= m; ++j)
                            if (a[i, j])
                                ++total;

                    int seconds = 0;
                    for (; total > 0; seconds++ )
                    {
                        for (int i = n; i >= 1; --i)
                            for (int j = m; j >= 1; --j)
                            {
                                if (!a[i, j] && a[i - 1, j] && a[i, j - 1])
                                { a[i, j] = true; ++total; }
                                else if (a[i,j] && !a[i - 1, j] && !a[i,j - 1])
                                { a[i, j] = false; --total; }
                            }

                        /*Console.WriteLine("\r\n{0}", total);
                        for (int i = 1; i <= n; ++i)
                        {
                            for (int j = 1; j <= m; ++j)
                                Console.Write(a[i, j] ? "1" : "0");
                            Console.WriteLine();
                            
                        }
                        Console.ReadKey();*/
                    }
                    writer.WriteLine("Case #{0}: {1}", test, seconds);
                }
            }
        }
    }
}
