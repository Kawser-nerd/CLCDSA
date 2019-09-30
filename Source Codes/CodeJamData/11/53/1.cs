using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class CCCC : GCJBase
    {
        public override void Solve()
        {
            cDirI.Add('-', new int[] { 0, 0 });
            cDirJ.Add('-', new int[] { -1, 1 });

            cDirI.Add('|', new int[] { -1, 1 });
            cDirJ.Add('|', new int[] { 0, 0 });

            cDirI.Add('/', new int[] { -1, 1 });
            cDirJ.Add('/', new int[] { 1, -1 });

            cDirI.Add('\\', new int[] { -1, 1 });
            cDirJ.Add('\\', new int[] { -1, 1 });

            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                R = int.Parse(s.Split(' ')[0]);
                C = int.Parse(s.Split(' ')[1]);

                map = new char[R, C];
                for (int r = 0; r < R; r++)
                {
                    s = Console.ReadLine();
                    for (int c = 0; c < C; c++)
                    {
                        map[r, c] = s[c];
                    }
                }
                long ret = mapways();

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        long MOD = 1000003;
        int[] aDirI = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] aDirJ = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };
        Dictionary<char, int[]> cDirI = new Dictionary<char, int[]>();
        Dictionary<char, int[]> cDirJ = new Dictionary<char, int[]>();
        Dictionary<State, long> mem = new Dictionary<State, long>();
        char[,] map;
        int R;
        int C;

        private long mapways()
        {
            bool[,] inPointer = new bool[R, C];
            bool[,] chosen = new bool[R, C];
            mem = new Dictionary<State, long>();

            State state = new State();
            state.inPointer = inPointer;
            state.chosen = chosen;
            state.R = R;
            state.C = C;
            long ret = waysfromhere(state);
            return ret;
        }

        private long waysfromhere(State state)
        {
            long val;
            if (mem.TryGetValue(state, out val))
            {
                return val;
            }

            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    if (!state.chosen[r, c])
                    {
                        long ret = 0;
                        //state.chosen[r, c] = true;
                        for (int dir = 0; dir < 2; dir++)
                        {
                            int nextr = (r + cDirI[map[r, c]][dir] + R) % R;
                            int nextc = (c + cDirJ[map[r, c]][dir] + C) % C;
                            if (!state.inPointer[nextr, nextc])
                            {
                                State newState = state.Clone();
                                newState.chosen[r, c] = true;
                                newState.inPointer[nextr, nextc] = true;
                                if (Effects(nextr, nextc,newState))
                                {
                                    ret += waysfromhere(newState);
                                    ret %= MOD;
                                }
                            }
                        }
                        mem.Add(state, ret);
                        return ret;
                    }
                }
            }
            mem.Add(state, 1);
            return 1;
        }

        private bool Effects(int r, int c, State state)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nextr = (r + aDirI[dir] + R) % R;
                int nextc = (c + aDirJ[dir] + C) % C;
                if (!state.chosen[nextr, nextc])
                {
                    bool atOrigin = false;
                    int freecellr=-1;
                    int freecellc=-1;
                    for (int newdir = 0; newdir < 2; newdir++)
                    {
                        int nextr2 = (nextr + cDirI[map[nextr,nextc]][newdir] + R) % R;
                        int nextc2 = (nextc + cDirJ[map[nextr,nextc]][newdir] + C) % C;
                        if (nextr2 == r && nextc2 == c) atOrigin = true;
                        if (!state.inPointer[nextr2, nextc2])
                        {
                            freecellr = nextr2;
                            freecellc = nextc2;
                        }
                    }
                    if (atOrigin)
                    {
                        if (freecellr > -1)
                        {
                            state.chosen[nextr, nextc] = true;
                            state.inPointer[freecellr, freecellc] = true;
                            if (!Effects(freecellr, freecellc, state))
                            {
                                return false;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        private class State
        {
            public bool[,] inPointer;
            public bool[,] chosen;
            public int R;
            public int C;

            public override int GetHashCode()
            {
                int l = 0;
                int idx = 0;
                for (int r = 0; r < R; r++)
                {
                    for (int c = 0; c < C; c++)
                    {
                        if (inPointer[r, c]) l ^= (1 << idx++);
                        if (chosen[r, c]) l ^= (1 << idx++);
                        if (idx >= 30) idx -= 30;
                    }
                }
                return l;
            }

            public override bool Equals(object obj)
            {
                State o = obj as State;
                for (int r = 0; r < R; r++)
                {
                    for (int c = 0; c < C; c++)
                    {
                        if (o.inPointer[r, c] != this.inPointer[r, c]) return false;
                        if (o.chosen[r, c] != this.chosen[r, c]) return false;
                    }
                }
                return true;
            }

            public State Clone()
            {
                State o = new State();
                o.R = this.R;
                o.C = this.C;
                o.inPointer = new bool[R, C];
                o.chosen = new bool[R, C];
                for (int r = 0; r < R; r++)
                {
                    for (int c = 0; c < C; c++)
                    {
                        o.inPointer[r, c] = this.inPointer[r, c];
                        o.chosen[r, c] = this.chosen[r, c];
                    }
                }

                return o;
            }
        }
    }
}
