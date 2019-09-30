using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
    static int[] dr = { 1, 0, -1, 0 };
    static int[] dc = { 0, 1, 0, -1 };

    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE + " / " + CASES);
            string[] parts = Console.ReadLine().Split();
            int R = int.Parse(parts[0]);
            int C = int.Parse(parts[1]);
            string[] map = new string[R];
            for (int i = 0; i < R; i++)
                map[i] = Console.ReadLine();
            LinkedList<int> br = new LinkedList<int>();
            LinkedList<int> bc = new LinkedList<int>();
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (map[i][j] == 'o' || map[i][j] == 'w')
                    {
                        br.AddLast(i);
                        bc.AddLast(j);
                    }
                }
            }

            int nboxes = bc.Count;
            Queue<State> Q = new Queue<State>();
            HashSet<State> done = new HashSet<State>();
            int ret = -1;
            Q.Enqueue(new State(br.ToArray(), bc.ToArray(), 0));
            while (Q.Count > 0)
            {
                State top = Q.Dequeue();
                if (done.Contains(top))
                    continue;
                done.Add(top);

                bool end = true;
                for (int i = 0; end && i < nboxes; i++)
                    if (map[top.r[i]][top.c[i]] != 'x' && map[top.r[i]][top.c[i]] != 'w')
                        end = false;
                if (end)
                {
                    ret = top.steps;
                    break;
                }

                bool stable = isConnected(top);
                for (int i = 0; i < nboxes; i++)
                {
                    for (int j = 0; j < dr.Length; j++)
                    {
                        int nr = top.r[i] + dr[j];
                        int nc = top.c[i] + dc[j];
                        int fr = top.r[i] - dr[j];
                        int fc = top.c[i] - dc[j];
                        if (isEmpty(nr, nc, top, R, C, map) && isEmpty(fr, fc, top, R, C, map))
                        {
                            int[] rcopy = (int[])top.r.Clone();
                            int[] ccopy = (int[])top.c.Clone();
                            rcopy[i] = nr;
                            ccopy[i] = nc;
                            State newState = new State(rcopy, ccopy, top.steps + 1);
                            if (stable || isConnected(newState))
                            {
                                Q.Enqueue(newState);
                            }
                        }
                    }
                }
            }

            Console.WriteLine("Case #" + CASE + ": " + ret);
        }
    }

    static bool isConnected(State s)
    {
        int n = s.c.Length;
        bool[,] conn = new bool[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Math.Abs(s.c[i] - s.c[j]) + Math.Abs(s.r[i] - s.r[j]) <= 1)
                {
                    conn[i, j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    conn[j, k] |= conn[j, i] && conn[i, k];
        for (int i = 1; i < n; i++)
            if (!conn[0, i])
                return false;
        return true;
    }

    static bool isEmpty(int r, int c, State s, int R, int C, string[] map)
    {
        if (r < 0 || r >= R || c < 0 || c >= C)
            return false;
        if (map[r][c] == '#')
            return false;
        for (int i = 0; i < s.r.Length; i++)
            if (s.r[i] == r && s.c[i] == c)
                return false;
        return true;
    }

    public class State
    {
        public int[] r, c;
        public int steps;
        bool[,] done = new bool[12, 12];

        public State(int[] r, int[] c, int steps)
        {
            this.r = r;
            this.c = c;
            this.steps = steps;
            for (int i = 0; i < r.Length; i++)
                done[r[i], c[i]] = true;
        }

        public override int GetHashCode()
        {
            int rr = 1, rc = 1;
            for (int i = 0; i < r.Length; i++)
            {
                rr *= r[i];
                rc *= c[i];
            }
            return rr ^ rc;
        }

        public override bool Equals(object obj)
        {
            return Equals(obj as State);
        }

        public bool Equals(State other)
        {
            for (int i = 0; i < r.Length; i++)
                if (!done[other.r[i], other.c[i]])
                    return false;
            return true;
        }
    }
}
