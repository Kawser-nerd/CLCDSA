using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice
{
    class Program
    {
        private static int ReadAndParseInt()
        {
            return int.Parse(Console.ReadLine());
        }
        private static int[] ReadAndParseIntArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        }
        private static long ReadAndParseLong()
        {
            return long.Parse(Console.ReadLine());
        }
        private static long[] ReadAndParseLongArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
        }
        static void Main(string[] args)
        {
            SolveA(args);
            //SolveB(args);
            //SolveC(args);
            //SolveD(args);


        }
        private struct Pos
        {
            public int row;
            public int col;
        }
        private const long MOD = 1000000007;
        static void SolveA(string[] args)
        {
            var hwd = ReadAndParseIntArr();
            int h = hwd[0];
            int w = hwd[1];
            int d = hwd[2];
            int[,] A = new int[h, w];
            for (int i = 0; i < h; ++i)
            {
                var a = ReadAndParseIntArr();
                for (int j = 0; j < w; ++j)
                {
                    A[i, j] = a[j];
                }
            }
            var coordinate = new Pos[h * w + 1];
            for(int i=0;i<h;++i)
            {
                for(int j=0;j<w;++j)
                {
                    coordinate[A[i, j]] = new Pos() { row = i, col = j };
                }
            }
            // ???????
            var table = new long[h * w + 1];
            for(int i=d+1;i<=h*w;++i)
            {
                Pos spos = coordinate[i - d];
                Pos dpos = coordinate[i];
                table[i] = table[i - d] + Math.Abs(dpos.row - spos.row) + Math.Abs(dpos.col - spos.col);
            }

            int q = ReadAndParseInt();
            int[] L = new int[q];
            int[] R = new int[q];
            for(int i=0;i<q;++i)
            {
                var lr = ReadAndParseIntArr();
                L[i] = lr[0];
                R[i] = lr[1];
            }

            for(int i=0;i<q;++i)
            {
                long cost = 0;
                int l = L[i];
                int r = R[i];

                int idx = l % d;
                cost = table[r] - table[l];
                Console.WriteLine(cost);
            }
        }
        private static void Find(int x, Pos[] coordinate, out int row, out int col)
        {
            row = coordinate[x].row;
            col = coordinate[x].col;
        }
    }
}