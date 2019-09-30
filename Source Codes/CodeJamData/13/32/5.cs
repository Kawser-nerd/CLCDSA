using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        class Item
        {
            public int X;
            public int Y;
            public string Dir;
            public int Prev;
            public int Jump;

            
            public override bool Equals(object obj)
            {
                Item other = obj as Item;
                if (other == null) return false;

                return other.X == X && other.Y == Y;
            }

            public override int GetHashCode()
            {
                unchecked
                {
                    return X * 17 + Y;
                }
            }
        }


        private static void Go(List<Item> q, HashSet<Item> hs, int x1, int y1, string dir, int prev)
        {
            var it = new Item { X = x1, Y = y1 };
            if (hs.Contains(it)) return;

            it.Dir = dir;
            it.Prev = prev;
            it.Jump = q[prev].Jump + 1;

            q.Add(it);
            hs.Add(it);
        }


        private static string Solve(int x, int y)
        {
            HashSet<Item> hs = new HashSet<Item>();
            List<Item> q = new List<Item>();

            var it = new Item { X = 0, Y = 0, Jump = 0 };
            q.Add(it);
            hs.Add(it);

            int i = 0;
            while (i < q.Count)
            {
                int x0 = q[i].X;
                int y0 = q[i].Y;

                int x1, y1;
                int jump = q[i].Jump + 1;

                x1 = x0;
                y1 = y0 + jump;
                Go(q, hs, x1, y1, "N", i);
                if (x1 == x && y1 == y) break;

                x1 = x0;
                y1 = y0 - jump;
                Go(q, hs, x1, y1, "S", i);
                if (x1 == x && y1 == y) break;

                x1 = x0 + jump;
                y1 = y0;
                Go(q, hs, x1, y1, "E", i);
                if (x1 == x && y1 == y) break;

                x1 = x0 - jump;
                y1 = y0;
                Go(q, hs, x1, y1, "W", i);
                if (x1 == x && y1 == y) break;

                i++;
            }

            List<string> path = new List<string>();
            it = q[q.Count - 1];
            
            while (it.X != 0 || it.Y != 0)
            {
                path.Add(it.Dir);
                it = q[it.Prev];
            }

            path.Reverse();

            return string.Join(string.Empty, path);
        }


        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            for (int caseNum = 1; caseNum <= T; caseNum++)
            {
                string[] line = Console.ReadLine().Trim().Split();
                int x = int.Parse(line[0]);
                int y = int.Parse(line[1]);

                string res = Solve(x, y);
                Console.WriteLine("Case #{0}: {1}", caseNum, res);
            }
        }
    }
}
