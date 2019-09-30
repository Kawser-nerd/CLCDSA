using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class CrossingRoad
    {
        private int[] specs;
        private int n, m;
        int minutes(int n, int m, int[] specs)
        {
            this.specs = specs;
            this.n = n;
            this.m = m;

            bool[,,] visit = new bool[n,m,4];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        visit[i, j, k] = false;
                    }
                }
            }


            Node start = new Node();
            start.Time = 0;
            start.Row = n - 1;
            start.Col = 0;
            start.Place = 1;

            SortedDictionary<Node, object> queue = new SortedDictionary<Node, object>();

            queue.Add(start, null);

            while (queue.Count > 0)
            {
                Node upper = new Node();
                foreach (Node key in queue.Keys)
                {
                    upper = key;
                    break;
                }
                queue.Remove(upper);

                if (upper.Row < 0 || upper.Row >= n || upper.Col < 0 || upper.Col >= m)
                    continue;

                if (visit[upper.Row, upper.Col, upper.Place])
                    continue;

                if (upper.Col == m-1 && upper.Row == 0 && upper.Place == 3)
                {
                    return upper.Time;
                }

                visit[upper.Row, upper.Col, upper.Place] = true;

                int minutes1, minutes2;
                Node n1, n2, n3, n4;

                minutes1 = calc(upper.Row, upper.Col, upper.Time, true);
                minutes2 = calc(upper.Row, upper.Col, upper.Time, false);

                switch (upper.Place)
                {
                    case 0:
                        n1 = new Node(){Time = upper.Time+2,Col=upper.Col+1,Row=upper.Row,Place = 1};
                        n2 = new Node(){Time = upper.Time+2,Col=upper.Col,Row=upper.Row+1,Place = 3};
                        n3 = new Node() { Time = upper.Time + minutes1+1, Col = upper.Col, Row = upper.Row, Place = 3 };
                        n4 = new Node() { Time = upper.Time + minutes2+1, Col = upper.Col, Row = upper.Row, Place = 1 };
                        break;
                    case 1:
                        n1 = new Node() { Time = upper.Time + 2, Col = upper.Col - 1, Row = upper.Row, Place = 0 };
                        n2 = new Node() { Time = upper.Time + 2, Col = upper.Col, Row = upper.Row + 1, Place = 2 };
                        n3 = new Node() { Time = upper.Time + minutes1 + 1, Col = upper.Col, Row = upper.Row, Place = 2 };
                        n4 = new Node() { Time = upper.Time + minutes2 + 1, Col = upper.Col, Row = upper.Row, Place = 0 };
                        break;
                    case 2:
                        n1 = new Node() { Time = upper.Time + 2, Col = upper.Col - 1, Row = upper.Row, Place = 3 };
                        n2 = new Node() { Time = upper.Time + 2, Col = upper.Col, Row = upper.Row - 1, Place = 1 };
                        n3 = new Node() { Time = upper.Time + minutes1 + 1, Col = upper.Col, Row = upper.Row, Place = 1 };
                        n4 = new Node() { Time = upper.Time + minutes2 + 1, Col = upper.Col, Row = upper.Row, Place = 3 };
                        break;
                    default:
                        n1 = new Node() { Time = upper.Time + 2, Col = upper.Col + 1, Row = upper.Row, Place = 2 };
                        n2 = new Node() { Time = upper.Time + 2, Col = upper.Col, Row = upper.Row - 1, Place = 0 };
                        n3 = new Node() { Time = upper.Time + minutes1 + 1, Col = upper.Col, Row = upper.Row, Place = 0 };
                        n4 = new Node() { Time = upper.Time + minutes2 + 1, Col = upper.Col, Row = upper.Row, Place = 2 };
                        break;
   
                }
                queue[n1] = null;
                queue[n2] = null;
                queue[n3] = null;
                queue[n4] = null;

            }
            return -1;
        }

        int calc(int row, int col, int time, bool dir)
        {
            int ind = row*m + col;
            int s = specs[ind*3 + 0];
            int w = specs[ind*3 + 1];
            int t = specs[ind*3 + 2];

            int shift = t%(s + w);

            time -= shift;
            if (time < 0)
                time += s + w;

            int interval = time%(s + w);

            if (dir)
            {
                if (interval < s)
                    return 0;
                return s + w - interval;
            }
            else
            {
                if (interval >= s)
                    return 0;
                return s - interval;
            }
        }

        class Node : IComparable<Node>
        {
            public int Time { get; set; }
            public int Row { get; set; }
            public int Col { get; set; }
            public int Place { get; set; }

            #region IComparable<Cell> Members

            public int CompareTo(Node other)
            {
                int cmp = Time.CompareTo(other.Time);
                if (cmp == 0) cmp = -Row.CompareTo(other.Row);
                if (cmp == 0) cmp = Col.CompareTo(other.Col);
                if (cmp == 0) cmp = Place.CompareTo(other.Place);
                return cmp;
            }

            #endregion
        }

        public static void Main()
        {
            StreamReader sr = new StreamReader("B-large.in");
            StreamWriter sw = new StreamWriter("CrossingRoad.out");

            var obj = new CrossingRoad();

            int testsCount = int.Parse(sr.ReadLine());

            for (int i = 0; i < testsCount; i++)
            {
                string[] nm = sr.ReadLine().Split(' ');
                int n = int.Parse(nm[0]);
                int m = int.Parse(nm[1]);

                string s = "";
                for (int j = 0; j < n; j++)
                {
                    s += sr.ReadLine() + " ";
                }
                s = s.Trim();
                string[] specs = s.Split(' ');

                int result = obj.minutes(n, m, specs.Select(str => int.Parse(str)).ToArray());
                sw.WriteLine("Case #{0}: {1}", i + 1, result);
            }

            sr.Close();
            sw.Close();
        }
    }
}
