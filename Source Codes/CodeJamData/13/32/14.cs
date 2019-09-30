using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pogo
{
    class Program
    {
        class Move
        {
            public long x, y, jump;

            public Move(long x, long y, long jump)
            {
                this.x = x;
                this.y = y;
                this.jump = jump;
            }
        }

        const long shift = 10000000;

        private static long GetIndex(long x, long y)
        {
            return y*shift + x;
        }

        private static void AddMove(Move move, Queue<Move> moves, Dictionary<long, long> visited)
        {
            long index = GetIndex(move.x, move.y);
            if (!visited.ContainsKey(index))
            {
                moves.Enqueue(move);
                visited[index] = move.jump;
            }
        }

        private static bool UnjumpPossible(long x, long y, long jump, Dictionary<long, long> visited)
        {
            long index = GetIndex(x, y);
            if (visited.ContainsKey(index))
            {
                long previousJump = visited[index];
                return previousJump == (jump - 1);
            }
            else
            {
                return false;
            }
        }

        private static string Path(long x, long y, long jump, Dictionary<long, long> visited)
        {
            char[] path = new char[jump];
            while (jump != 0)
            {
                // try all possible unjumps
                if (UnjumpPossible(x - jump, y, jump, visited))
                {
                    x -= jump;
                    path[jump - 1] = 'E';
                    jump--;
                    continue;
                }

                if (UnjumpPossible(x + jump, y, jump, visited))
                {
                    x += jump;
                    path[jump - 1] = 'W';
                    jump--;
                    continue;
                }

                if (UnjumpPossible(x, y - jump, jump, visited))
                {
                    y -= jump;
                    path[jump - 1] = 'N';
                    jump--;
                    continue;
                }

                if (UnjumpPossible(x, y + jump, jump, visited))
                {
                    y += jump;
                    path[jump - 1] = 'S';
                    jump--;
                    continue;
                }
            }

            return new string(path);
        }

        private static string Search(long x, long y)
        {
            Dictionary<long, long> visited = new Dictionary<long, long>();

            // do BFS here
            Queue<Move> moves = new Queue<Move>();

            AddMove(new Move(0, 0, 0), moves, visited);

            while (true)
            {
                Move move = moves.Dequeue();
                // check if reached destination

                if ((move.x == x) && (move.y == y)) return 
                    Path(x, y, move.jump, visited);

                // do all moves here
                long jump = (move.jump + 1);

                AddMove(new Move(move.x + jump, move.y, jump), moves, visited);
                AddMove(new Move(move.x - jump, move.y, jump), moves, visited);
                AddMove(new Move(move.x, move.y + jump, jump), moves, visited);
                AddMove(new Move(move.x, move.y - jump, jump), moves, visited);
            }

            return null;
        }

        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"..\..\..\..\";
                string filenameIn = "B-small-attempt0.in";
                string filenameOut = "B-small-attempt0.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    Console.WriteLine(t);

                    string[] splitted = sr.ReadLine().Split(' ');
                    int x = Convert.ToInt32(splitted[0]);
                    int y = Convert.ToInt32(splitted[1]);

                    string message = Search(x, y);
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
