using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            Console.Write("Case #" + CASE + ": ");
            if (!Testcase())
                Console.WriteLine("IMPOSSIBLE");
        }
    }

    static int[] dr = new int[] { 0, 1, 0, -1 };
    static int[] dc = new int[] { 1, 0, -1, 0 };

    public static bool Testcase()
    {
        string[] ps = Console.ReadLine().Split();
        int R = int.Parse(ps[0]);
        int C = int.Parse(ps[1]);

        string[] grid = new string[R];
        for (int r = 0; r < R; r++)
            grid[r] = Console.ReadLine();

        List<int>[,] lasers = new List<int>[R, C];
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] == '.')
                    lasers[r, c] = new List<int>();

        List<int> lfixed = new List<int>();
        int nextlaser = 1;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] == '-' || grid[r][c] == '|')
                {
                    bool horok = true;
                    bool vertok = true;
                    for (int d = 0; d < 4; d++)
                    {
                        int cr = r;
                        int cc = c;
                        int cd = d;
                        while (true)
                        {
                            cr += dr[cd];
                            cc += dc[cd];
                            if (cr < 0 || cr >= R || cc < 0 || cc >= C) break;

                            bool break2 = false;
                            switch (grid[cr][cc])
                            {
                                case '.':
                                    lasers[cr, cc].Add(((d % 2 == 0) ? 1 : -1) * nextlaser);
                                    break;
                                case '#':
                                    break2 = true;
                                    break;
                                case '-':
                                case '|':
                                    if (d % 2 == 0) horok = false;
                                    else vertok = false;
                                    break2 = true;
                                    break;
                                case '/':
                                    cd = (cd + 3) % 4;
                                    break;
                                case '\\':
                                    cd = (cd + 1) % 4;
                                    break;
                                default:
                                    throw new Exception("This is not right!");
                            }
                            if (break2) break;
                        }

                    }
                    if (!horok && !vertok) return false;
                    else if (!horok)
                        lfixed.Add(-nextlaser);
                    else if (!vertok)
                        lfixed.Add(nextlaser);
                    nextlaser++;
                }


        TwoSAT sat = new TwoSAT(nextlaser - 1);
        foreach (int f in lfixed)
            sat.AddClause(f, f);
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (grid[r][c] == '.')
                {
                    if (lasers[r, c].Count == 0) return false;
                    else if (lasers[r, c].Count == 1)
                        sat.AddClause(lasers[r, c][0], lasers[r, c][0]);
                    else if (lasers[r, c].Count == 2)
                        sat.AddClause(lasers[r, c][0], lasers[r, c][1]);
                    else
                        throw new Exception("How could this happen!?");
                }
            }
        }

        if (!sat.Satisfiable()) return false;
        Console.WriteLine("POSSIBLE");

        nextlaser = 1;
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (grid[r][c] == '-' || grid[r][c] == '|')
                {
                    Console.Write(sat.IsTrue(nextlaser++) ? '-' : '|');
                }
                else Console.Write(grid[r][c]);
            }
            Console.WriteLine();
        }
        return true;
    }



    public class Scc
    {
        public int n;
        public int[] component;
        public LinkedList<int>[] Neighbors, NeighborsR;
        public int[] order;
        private int order_num, actnum;

        public Scc(int n)
        {
            this.n = n;
            Neighbors = new LinkedList<int>[n];
            NeighborsR = new LinkedList<int>[n];
            for (int i = 0; i < n; i++)
            {
                Neighbors[i] = new LinkedList<int>();
                NeighborsR[i] = new LinkedList<int>();
            }
        }

        public void AddEdge(int i, int j)
        {
            Neighbors[i].AddLast(j);
            NeighborsR[j].AddLast(i);
        }

        public int FindComponents()
        {
            component = new int[n];
            order = new int[n];
            order_num = 0;

            for (int i = 0; i < n; i++)
                Dfs1(i);

            actnum = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (component[order[i]] == -1)
                {
                    Dfs2(order[i]);
                    actnum++;
                }
            }
            return actnum;
        }

        private void Dfs1(int i)
        {
            if (component[i] != 0) return;
            component[i] = -1;
            foreach (int adj in Neighbors[i])
                Dfs1(adj);
            order[order_num++] = i;
        }

        private void Dfs2(int i)
        {
            if (component[i] != -1) return;
            component[i] = actnum;
            foreach (int adj in NeighborsR[i])
                Dfs2(adj);
        }
    }

    public class TwoSAT
    {
        private int n;
        private Scc scc;

        public TwoSAT(int n)
        {
            this.n = n;
            this.scc = new Scc(2 * n);
        }

        // 1..n for true, -1..-n for false
        // adding clause v1 or v2
        public void AddClause(int v1, int v2)
        {
            scc.AddEdge(getNum(-v1), getNum(v2));
            scc.AddEdge(getNum(-v2), getNum(v1));
        }

        public bool Satisfiable()
        {
            scc.FindComponents();
            for (int i = 1; i <= n; i++)
                if (scc.component[getNum(i)] == scc.component[getNum(-i)])
                    return false;
            return true;
        }

        // Is variable v (1..n) true or not? Call this after Satisfiable()
        public bool IsTrue(int v)
        {
            return scc.component[getNum(v)] > scc.component[getNum(-v)];
        }

        private int getNum(int num)
        {
            return num < 0 ? n - num - 1 : num - 1;
        }
    }
}
