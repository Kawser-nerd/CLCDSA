using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class DescendingDark : GCJBase
    {
        char[] moves = new char[] { 'D', 'L', 'R' };
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string s = Console.ReadLine();
                int N = int.Parse(s.Split(' ')[0]);
                int M = int.Parse(s.Split(' ')[1]);
                char[,] map = new char[N, M];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine();
                    for (int j = 0; j < M; j++)
                    {
                        map[i, j] = s[j];
                    }
                }

                string[] sOut = SolveMountain(N, M, map);
                Console.WriteLine("Case #{0}:", iCase);
                for (int j = 0; j < sOut.Length; j++)
                {
                    Console.WriteLine(sOut[j]);
                }
            }

            if (bManual) Console.ReadKey();
        }

        private string[] SolveMountain(int N, int M, char[,] map)
        {
            List<string> ret = new List<string>();
            for (int cave = 0; cave <= 9; cave++)
            {
                bool cavefound = false;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (map[i, j] == (char)('0' + cave))
                        {
                            cavefound = true;
                            string s = SolveCave(N, M, i, j, map);
                            ret.Add(string.Format("{0}: {1}", cave, s));
                        }
                    }
                }
                if (!cavefound) return ret.ToArray();
            }
            return ret.ToArray();
        }

        private string SolveCave(int N, int M, int cavei, int cavej, char[,] map)
        {
            bool[,] poss = new bool[N, M];
            poss[cavei, cavej] = true;
            Queue<int> oQ = new Queue<int>();
            oQ.Enqueue(cavei);
            oQ.Enqueue(cavej);
            while (oQ.Count > 0)
            {
                int i = oQ.Dequeue();
                int j = oQ.Dequeue();

                int i2;
                int j2;

                // UP
                i2 = i - 1;
                j2 = j;

                if (!poss[i2, j2] && map[i2, j2] != '#')
                {
                    poss[i2, j2] = true;
                    oQ.Enqueue(i2);
                    oQ.Enqueue(j2);
                }

                // LEFT
                i2 = i;
                j2 = j-1;

                if (!poss[i2, j2] && map[i2, j2] != '#')
                {
                    poss[i2, j2] = true;
                    oQ.Enqueue(i2);
                    oQ.Enqueue(j2);
                }

                // RIGHT
                i2 = i;
                j2 = j+1;

                if (!poss[i2, j2] && map[i2, j2] != '#')
                {
                    poss[i2, j2] = true;
                    oQ.Enqueue(i2);
                    oQ.Enqueue(j2);
                }
            }

            KnownStates good = new KnownStates();
            good.N = N;
            good.M = M;
            good.poss = new long[N];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (poss[i,j]) {
                        good.AddPoss(i, j);
                    }
                }
            }

            Queue<KnownStates> q = new Queue<KnownStates>();
            HashSet<KnownStates> visited = new HashSet<KnownStates>();
            bool lucky=false;
            if (good.NumStates == 1)
            {
                lucky = true;
            }
            else
            {
                q.Enqueue(good);
                visited.Add(good);
                while (q.Count > 0)
                {
                    KnownStates cur = q.Dequeue();


                    for (int i = 0; i < moves.Length; i++)
                    {
                        KnownStates next = cur.Move(moves[i], good, map);
                        if (next != null && !visited.Contains(next))
                        {
                            if (next.NumStates == 1)
                            {
                                lucky = true;
                                break;
                            }
                            visited.Add(next);
                            q.Enqueue(next);
                        }
                    }
                }
            }

            return string.Format("{0} {1}", good.NumStates, lucky ? "Lucky" : "Unlucky");
        }

        private class KnownStates
        {
            private long l1 = 1;

            public long[] poss;
            public int N;
            public int M;

            public bool isPoss(int i, int j)
            {
                return (this.poss[i] & l1 << j) > 0;
            }

            public KnownStates Move(char dir, KnownStates good, char[,] map)
            {
                KnownStates afterMove = new KnownStates();
                afterMove.N = this.N;
                afterMove.M = this.M;
                afterMove.poss = new long[N];

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (this.isPoss(i, j))
                        {
                            int i2 = i;
                            int j2 = j;
                            if (dir == 'D')
                            {
                                i2++;
                            }
                            if (dir == 'L')
                            {
                                j2--;
                            }
                            if (dir == 'R')
                            {
                                j2++;
                            }
                            if (map[i2, j2] == '#')
                            {
                                i2 = i;
                                j2 = j;
                            }
                            if (!good.isPoss(i2, j2)) return null;
                            afterMove.AddPoss(i2, j2);
                        }
                    }
                }
                return afterMove;
            }

            public void AddPoss(int i, int j)
            {
                poss[i] = poss[i] | (l1 << j);
            }

            public override bool Equals(object obj)
            {
                KnownStates o = (KnownStates)obj;
                for (int i = 0; i < this.N; i++)
                {
                    if (this.poss[i] != o.poss[i]) return false;
                }
                return true;
            }

            public override int GetHashCode()
            {
                long h = 0;
                for (int i = 0; i < this.N; i++)
                {
                    h ^= this.poss[i];
                    h *= 1007;
                }
                return (int)h;
            }

            public override string ToString()
            {
                StringBuilder sb = new StringBuilder();
                char[] c = new char[M];
                for (int i = 0; i < this.N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        c[j] = ((this.poss[i] & l1 << j) > 0) ? '*' : ' ';
                    }
                    sb.AppendLine(new string(c));
                }
                return sb.ToString();
            }

            public int NumStates
            {
                get
                {
                    int ret = 0;
                    for (int i = 0; i < this.N; i++)
                    {
                        for (int j = 0; j < M; j++)
                        {
                            if ((this.poss[i] & l1 << j) > 0) ret++;
                        }
                    }
                    return ret;
                }
            }
        }
    }
}
