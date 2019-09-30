using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MakingChessBoards
{
    class Program
    {
        static void Main(string[] args)
        {
            var tasks = int.Parse(Console.ReadLine());
            var t = new Task[tasks];
            var answers = new Dictionary<int, int>[tasks + 1];
            for (int task = 1; task <= tasks; ++task)
            {

                var x = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var n = x[0];
                var board = new string[n];
                for (int i = 0; i < n; ++i)
                    board[i] = Console.ReadLine();
                //t[task] = Task.Factory.StartNew(() => { answers[task] = new Solver(board).Solve(); });
                answers[task] = new Solver(board).Solve();
            }
            //Task.WaitAll(t);
            for (int task = 1; task <= tasks; ++task)
            {
                Console.WriteLine("Case #{0}: {1}", task, answers[task].Count);
                foreach(var kvp in answers[task])
                    Console.WriteLine("{0} {1}", kvp.Key, kvp.Value);
            }
        }
    }

    class Solver
    {
        int[,] board;
        int nn;
        int mm;
        Dictionary<int, int> sizes = new Dictionary<int,int>();


        int ToInt(char c)
        {
            if ('0' <= c && c <= '9')
                return c - '0';
            return c - 'A' + 10;
        }

        public Solver(string[] a)
        {
            nn = a.Length;
            mm = a[0].Length * 4;
            board = new int[nn, mm];
            for (int i = 0; i < nn; ++i)
            {
                for (int j = 0; j < mm / 4; ++j)
                {
                    int x = ToInt(a[i][j]);
                    board[i, j * 4 + 3] = (x >> 0) & 1;
                    board[i, j * 4 + 2] = (x >> 1) & 1;
                    board[i, j * 4 + 1] = (x >> 2) & 1;
                    board[i, j * 4 + 0] = (x >> 3) & 1;
                }
            }
        }

        public Dictionary<int, int> Solve()
        {
            sizes.Clear();
            for (int i = PlaceBiggest(); i > 0; i = PlaceBiggest())
            {
                int prev;
                sizes.TryGetValue(i, out prev);
                sizes[i] = prev + 1;

            }
            return sizes;
        }

        int[,] a;

        public int PlaceBiggest()
        {
            a = new int[nn, mm];
            for (int i = 0; i < nn; ++i)
            {
                a[i, 0] = board[i, 0] == 2 ? -1 : 1;
            }
            for (int i = 0; i < mm; ++i)
            {
                a[0, i] = board[0, i] == 2 ? -1 : 1;
            }
            for (int i = 1; i < nn; ++i)
                for (int j = 1; j < mm; ++j)
                {
                    if (board[i, j] == 2) a[i, j] = -1;
                    else if (board[i-1, j] == 2) a[i, j] = 1;
                    else if (board[i, j-1] == 2) a[i, j] = 1;
                    else if (board[i-1, j-1] == 2) a[i, j] = 1;
                    else if (board[i,j] != board[i-1, j-1] || board[i,j] == board[i-1, j] || board[i,j] == board[i, j-1]) 
                        a[i, j] = 1;
                    else {
                        var t = a[i-1, j];
                        var t2 = a[i, j-1];
                        if (t2 < t) t = t2;
                        var t3 = a[i-1, j-1];
                        if (t3 < t) t = t3;
                        a[i,j] = t + 1;
                    }
                }

            var maxt = -1;
            var maxi = -1;
            var maxj = -1;
            for (int i = 0; i < nn; ++i)
                for (int j = 0; j < mm; ++j)
                {
                    if (a[i, j] > maxt)
                    {
                        maxt = a[i, j];
                        maxi = i;
                        maxj = j;
                    }
                }

            if (maxt == -1)
                return -1;

            for (int i = maxi; i > maxi - maxt; --i)
                for (int j = maxj; j > maxj - maxt; --j)
                    board[i, j] = 2;

            return maxt;
        }
    }
}
