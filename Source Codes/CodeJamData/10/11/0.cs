using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2010
{
    class a
    {
        private static Tuple<int, int> readIntInt()
        {
            int[] arr = readInts(2);
            return Tuple.Create(arr[0], arr[1]);
        }

        private static Tuple<int, int, int> readIntIntInt()
        {
            int[] arr = readInts(3);
            return Tuple.Create(arr[0], arr[1], arr[2]);
        }

        private static int[] readInts(int count)
        {
            int[] result = readInts();
            if (result.Length != count)
                throw new Exception(String.Format("input length mismatch: {0} numbers instead of {1}", result.Length, count));
            return result;
        }
        
        static void Main(string[] args)
        {
            int casesCount = Int32.Parse(Console.ReadLine());
            for (int cid = 0; cid < casesCount; cid++)
                Console.WriteLine("Case #{0}: {1}", cid + 1, readAndSolveCase());
        }

        private static int[] readInts()
        {
            return Console.ReadLine().Split(' ').Select(item => int.Parse(item)).ToArray();
        }

        private static String readAndSolveCase()
        {
            var nk = readIntInt();

            var N = nk.Item1;
            var k = nk.Item2;

            Char[,] board = new Char[N, N];

            for (int i = 0; i < N; i++)
            {
                String s = Console.ReadLine();
                if (s.Length != N)
                    throw new Exception();
                for (int j = 0; j < N; j++)
                    board[i, j] = s[j];
            }
           for (int i = 0; i < N; i++)
            {
                int freeJ = N - 1;
                for (int j = N - 1; j >= 0; j--)
                {
                    if (board[i, j] != '.')
                    {
                        board[i, freeJ] = board[i, j];
                        freeJ--;
                    }
                }
                while (freeJ >= 0)
                {
                    board[i, freeJ] = '.';
                    freeJ--;
                }
            }

            int r = calc(board, 'R');
            int b = calc(board, 'B');
           // Console.WriteLine("R: {0}, B: {1}", r, b);

            bool rw = r >= k;
            bool bw = b >= k;

            return rw?(bw?"Both":"Red"):(bw?"Blue":"Neither");
        }

        private static int calc<T>(IEnumerable<T> seq, T p)
        {
            //Console.WriteLine("calc: {0}", String.Join("", seq.Select(s =>s.ToString()).ToArray()));
            int max = 0;
            int cur = 0;
            foreach(T t in seq)
            {
                if (p.Equals(t))
                { cur++; max = Math.Max(max, cur); }
                else
                    cur = 0;
            }
            return max;
        }
        private static int calc(char[,] board, char p)
        {
            int N = board.GetLength(0);

            int max = 0;

            //Console.WriteLine("straight:");
            for (int i = 0; i < N; i++)
            {
                max = Math.Max(max, calc(Enumerable.Range(0, N).Select(j => board[i,j]), p));
                max = Math.Max(max, calc(Enumerable.Range(0, N).Select(j => board[j,i]), p));
            }

            //Console.WriteLine("diagonal:");
            for (int i = -N+1; i < N; i++)
            {
                max = Math.Max(max, calc(Enumerable.Range(0, N).Select(j => new { x = j, y = j + i }).Where(coord => coord.y >= 0 && coord.y < N).Select(coord => board[coord.x, coord.y]), p));
                max = Math.Max(max, calc(Enumerable.Range(0, N).Select(j => new { x = N-1-j, y = j + i }).Where(coord => coord.y >= 0 && coord.y < N).Select(coord => board[coord.x, coord.y]), p));
            }
            return max;
        }
    }
}
