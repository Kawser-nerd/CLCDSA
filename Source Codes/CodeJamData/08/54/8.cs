using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace D
{
    class Program
    {
        static int?[,] map;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("D-small.in"))
            {
                using (StreamWriter sw = new StreamWriter("D-small.out"))
                {
                    int TC = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= TC; tc++)
                    {
                        string[] elem = sr.ReadLine().Split(' ');
                        int H = int.Parse(elem[0]);
                        int W = int.Parse(elem[1]);
                        int R = int.Parse(elem[2]);
                        map = new int?[H + 1, W + 1];
                        for (int i = 0; i < R; i++)
                        {
                            elem = sr.ReadLine().Split(' ');
                            int r = int.Parse(elem[0]);
                            int c = int.Parse(elem[1]);

                            map[r, c] = 0;
                        }
                        map[1, 1] = 1;
                        sw.WriteLine("Case #{0}: {1}", tc, rec(H, W));
                    }
                    sw.Close(); sr.Close();
                }
            }
        }

        private static int rec(int r, int c)
        {
            if (r < 1 || c < 1) return 0;
            if (map[r, c].HasValue) return map[r, c].Value;

            map[r,c] = ((rec(r - 1, c - 2)) + rec(r - 2, c - 1))% 10007 ;
            return (int)map[r,c] ;
        }
    }
}
