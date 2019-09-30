using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class DiggingProblem
    {
        int digs(string[] cave, int maxFall)
        {
            int w = cave[0].Length;
            int h = cave.Length;

            int[,,] visit = new int[w,h,2];
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    visit[i, j, 0] = 100000;
                    visit[i, j, 1] = 100000;
                }
            }

            Node initial = new Node{Pos = new Point(0, 0), Digs = new List<Point>()};

            SortedDictionary<Node, int> q = new SortedDictionary<Node, int>();
            SortedDictionary<Node, int> visited = new SortedDictionary<Node, int>();

            q[initial] = 1;

            while (q.Count > 0)
            {
                Node n = new Node();
                foreach (Node nn in q.Keys)
                {
                    n = nn;
                    break;
                }
                q.Remove(n);

                if (n.Pos.X < 0 || n.Pos.X >= w) continue;
                if (cave[n.Pos.Y][n.Pos.X] == '#' && !n.Digs.Contains(n.Pos)) continue;

                if (n.Pos.Y == h - 1) 
                    return n.Digs.Count;

                /*int digged = 0;
                Point down = new Point(n.Pos.X, n.Pos.Y + 1);
                if (cave[down.Y][down.X] == '.' || n.Digs.Contains(down))
                    digged = 1;

                if (visit[n.Pos.X, n.Pos.Y, digged] <= n.Digs.Count) continue;
                visit[n.Pos.X, n.Pos.Y, digged] = n.Digs.Count;*/

                if (visited.ContainsKey(n)) continue;
                visited[n] = 1;

                int fall = 0;
                for (int i = n.Pos.Y+1; i < h; i++)
                {
                    Point p = new Point(n.Pos.X, i);
                    if (cave[p.Y][p.X] == '.' || n.Digs.Contains(p))
                        fall++;
                    else
                    {
                        break;
                    }
                }
                if (fall > maxFall) continue;

                n.Pos.Y += fall;
                if (n.Pos.Y == h - 1) 
                    return n.Digs.Count;

                Node left = n.Copy();
                left.Pos.X--;
                Node right = n.Copy();
                right.Pos.X++;

                q[left] = 1;
                q[right] = 1;

                Point p1 = new Point(n.Pos.X-1, n.Pos.Y+1);
                Point p11 = new Point(n.Pos.X-1, n.Pos.Y);
                if (p1.X >= 0 && (cave[p11.Y][p11.X] == '.' || n.Digs.Contains(p11)) && cave[p1.Y][p1.X] == '#' && !n.Digs.Contains(p1))
                {
                    Node digLeft = n.Copy();
                    digLeft.Digs.Add(p1);
                    digLeft.Pos.X--;
                    Node digLeft2 = digLeft.Copy();
                    digLeft2.Pos.X += 2;
                    q[digLeft] = 1;
                    q[digLeft2] = 1;
                }

                Point p2 = new Point(n.Pos.X + 1, n.Pos.Y + 1);
                Point p22 = new Point(n.Pos.X + 1, n.Pos.Y);
                if (p2.X < w && (cave[p22.Y][p22.X] == '.' || n.Digs.Contains(p22)) && cave[p2.Y][p2.X] == '#' && !n.Digs.Contains(p2))
                {
                    Node digRight = n.Copy();
                    digRight.Digs.Add(p2);
                    digRight.Pos.X++;
                    Node digRight2 = digRight.Copy();
                    digRight2.Pos.X -= 2;
                    q[digRight] = 1;
                    q[digRight2] = 1;
                }

            }

            return -1;
        }

        struct Node : IComparable<Node>
        {
            public Point Pos;
            public List<Point> Digs;

            #region IComparable<Node> Members

            public int CompareTo(Node other)
            {
                int cmp = Digs.Count - other.Digs.Count;
                if (cmp == 0) cmp = Pos.X - other.Pos.X;
                if (cmp == 0) cmp = Pos.Y - other.Pos.Y;
                if (cmp != 0) return cmp;
                bool same = true;
                foreach (Point dig in Digs)
                {
                    if (!other.Digs.Contains(dig))
                    {
                        return -1;
                    }
                }
                return 0;
            }

            #endregion

            public Node Copy()
            {
                return new Node{Pos = Pos, Digs = new List<Point>(Digs)};
            }
        }

        public static void Main()
        {
            StreamReader sr = new StreamReader("B-small-attempt0.in");
            FileStream fs = new FileStream("DiggingProblem.out", FileMode.Create, FileAccess.Write, FileShare.Read);
            StreamWriter sw = new StreamWriter(fs);

            var obj = new DiggingProblem();

            int testsCount = int.Parse(sr.ReadLine());

            for (int i = 0; i < testsCount; i++)
            {
                string[] bases = sr.ReadLine().Split(' ');
                int rows = int.Parse(bases[0]);
                string[] cave = new string[rows];
                for (int j = 0; j < rows; j++)
                {
                    cave[j] = sr.ReadLine();
                }

                int result = obj.digs(cave, int.Parse(bases[2]));
                
                sw.Write("Case #{0}: ", i + 1);
                if (result == -1)
                {
                    sw.WriteLine("No");
                }
                else
                {
                    sw.WriteLine("Yes {0}", result);
                }
                sw.Flush();
            }

            sr.Close();
            sw.Close();
        }
    }
}
