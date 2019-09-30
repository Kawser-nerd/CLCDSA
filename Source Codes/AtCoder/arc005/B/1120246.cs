using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC005B
{
    class Program
    {
        static void Main(string[] args)
        {
            Solver sol = new Solver();
            sol.Solve();
#if DEBUG
            Console.ReadLine();
#endif
        }
    }
    class Solver
    {
        int x, y;
        string direction;
        string[] C = new string[RandomNumberTable.N];
        RandomNumberTable rnt;

        public void Solve()
        {
            rnt = new RandomNumberTable(x, y, direction, C);
            Console.WriteLine(rnt.GetNumbers());
        }

        public Solver()
        {
            string[] str = rsa();
            x = int.Parse(str[0]);
            y = int.Parse(str[1]);
            direction = str[2];
            
            for(int i=0; i < RandomNumberTable.N; i++)
            {
                C[i] = rs();
            }
        }

        static String rs() { return Console.ReadLine(); }
        static int ri() { return int.Parse(Console.ReadLine()); }
        static long rl() { return long.Parse(Console.ReadLine()); }
        static double rd() { return double.Parse(Console.ReadLine()); }
        static String[] rsa() { return Console.ReadLine().Split(' '); }
        static int[] ria() { return Console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray(); }
        static long[] rla() { return Console.ReadLine().Split(' ').Select(e => long.Parse(e)).ToArray(); }
        static double[] rda() { return Console.ReadLine().Split(' ').Select(e => double.Parse(e)).ToArray(); }
    }
    class RandomNumberTable
    {
        string[] table= new string[N];
        int lx, ly, dx, dy;
        public static int N = 9;
        static int ReadN = 4;

        public RandomNumberTable(int sx, int sy, string direction, string[] table)
        {
            lx = sx-1;
            ly = sy-1;
            foreach (char c in direction)
            {
                switch (c)
                {
                    case 'R':
                        dx = 1;
                        break;
                    case 'L':
                        dx = -1;
                        break;
                    case 'D':
                        dy = 1;
                        break;
                    case 'U':
                        dy = -1;
                        break;
                    default:
                        break;
                }
            }
            table.CopyTo(this.table,0);
        }
        public string GetNumbers()
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < ReadN; i++)
            {
                sb.Append(Read());
                Move();
            }
            return sb.ToString();
        }
        char Read()
        {
            int tx = Convert(lx);
            int ty = Convert(ly);
            return table[ty][tx];
        }
        void Move()
        {
            lx += dx;
            ly += dy;
        }
        int Convert(int t)
        {
            if (t < 0)
            {
                return -t;
            }
            else if (t < N)
            {
                return t;
            }
            else
            {
                return 2 * N - t - 2;
            }
        }
    }
}