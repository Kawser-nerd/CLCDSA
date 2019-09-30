using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            return Array().Select(int.Parse).ToArray();
        }
        public long[] LongArray()
        {
            return Array().Select(long.Parse).ToArray();
        }
    }

    class Program
    {
        private int N;
        private int[] T, X, Y;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            T = new int[N];
            X = new int[N];
            Y = new int[N];
            for (int i = 0; i < N; i++)
            {
                T[i] = sc.NextInt();
                X[i] = sc.NextInt();
                Y[i] = sc.NextInt();
            }
        }

        public void Solve()
        {
            Scan();
            int xx = 0;
            int yy = 0;
            int tt = 0;
            for (int i = 0; i < N; i++)
            {
                int dist = Math.Abs(X[i] - xx) + Math.Abs(Y[i] - yy);
                int time = T[i] - tt;
                if (dist > time || (time - dist) % 2 == 1)
                {
                    Console.WriteLine("No");
                    return;
                }
                xx = X[i];
                yy = Y[i];
                tt = T[i];
            }
            Console.WriteLine("Yes");
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}