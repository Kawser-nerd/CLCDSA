using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace Round_2
{
    class ProblemB
    {
        static string[] text;
        static int at;
        static void Main(string[] args)
        {
            text = File.ReadAllLines("B.in");
            at = 0;
            int n=ReadInt(text[at++]);
            for (int i = 1; i <= n; i++)
                ProblemSolve(i);
        }

        static void ProblemSolve(int cas)
        {
            string[] rcf = text[at++].Split(' ');
            int r = ReadInt(rcf[0]);
            int c = ReadInt(rcf[1]);
            int f = ReadInt(rcf[2]);
            bool[,] rock = new bool[r, c];
            for (int i = 0; i < r; i++)
            {
                String row = text[at++];
                for (int j = 0; j < c; j++)
                    rock[i, j] = row[j] == '#';
            }
            State state = new State(rock);
            State endState = DownTheRabbitHole(state, null, r - 1, f);

            if(endState!=null)
                Console.WriteLine("Case #" + cas + ": Yes " + endState.dug);
            else
                Console.WriteLine("Case #" + cas + ": No ");

        }

        static State DownTheRabbitHole(State state, State best, int maxR, int maxF)
        {
            if (state.playerR == maxR) return state;
            if(best!=null && state.dug>=best.dug) return best;
            foreach (State newState in state.GetSubsequentStates(maxF))
            {
                State nState=DownTheRabbitHole(newState, best, maxR, maxF);
                if (nState != null && best == null) best = nState;
                else if (best != null && nState.dug < best.dug) best = nState;
            }
            return best;
        }

        static int ReadInt(String text) { return Int32.Parse(text); }
    }

    class State
    {
        public bool[,] Rocks;
        public int playerR, playerC;
        public int dug;

        public State(bool[,] rocks)
        {
            Rocks = new bool[rocks.GetLength(0), rocks.GetLength(1)];
            for (int i = 0; i < rocks.GetLength(0); i++)
                for (int j = 0; j < rocks.GetLength(1); j++)
                    Rocks[i, j] = rocks[i, j];
        }

        public List<State> GetSubsequentStates(int maxFall)
        {
            //player can dig along the space
            //or player can jump off a cliff
            List<State> states=new List<State>();
            
            //these are the spaces that can be stood on
            int firstSpace = playerC;
            int lastSpace = playerC;
            for (firstSpace = playerC; CanBeIn(firstSpace - 1); firstSpace--) ;
            for (lastSpace = playerC; CanBeIn(lastSpace + 1); lastSpace++) ;

            //a player can dig a trench equal to space he can walk, -1.
            int maxTrenchLength = (lastSpace-firstSpace);
            for (int length = 1; length <= maxTrenchLength; length++)
            {
                //firstspace=0,lastspace=10, max=10,first+10=10, good
                for (int startC = firstSpace; startC + length <= lastSpace; startC++)
                {
                    State nState = new State(Rocks);
                    for (int at = startC + 1; at <= startC + length; at++)
                        nState.Rocks[playerR + 1, at] = false;
                    nState.dug = dug + length;
                    nState.playerC = startC + 1;
                    nState.playerR = nState.NextRow(startC + 1, playerR);
                    if (nState.playerR - playerR <= maxFall)
                        states.Add(nState);
                }
                for (int startC = lastSpace; startC - length >= firstSpace; startC--)
                {
                    State nState = new State(Rocks);
                    for (int at = startC - 1; at >= startC - length; at--)
                        nState.Rocks[playerR + 1, at] = false;
                    nState.dug = dug + length;
                    nState.playerC = startC - 1;
                    nState.playerR = nState.NextRow(startC - 1, playerR);
                    if (nState.playerR - playerR <= maxFall)
                        states.Add(nState);
                }

            }
            if (!IsRock(firstSpace - 1, playerR))
            {
                int nc = firstSpace - 1;
                State st = new State(Rocks);
                st.dug = dug;
                st.playerC = nc;
                st.playerR = st.NextRow(nc, playerR);
                if (st.playerR - playerR <= maxFall)
                    states.Add(st);
            }

            if (!IsRock(lastSpace + 1, playerR))
            {
                int nc = lastSpace + 1;
                State st = new State(Rocks);
                st.dug = dug;
                st.playerC = nc;
                st.playerR = st.NextRow(nc, playerR);
                if (st.playerR - playerR <= maxFall)
                    states.Add(st);
            }
            return states;
        }

        public bool CanBeIn(int newC)
        {
            //if (newC < 0 || newC >= Rocks.GetLength(1)) return false;
            return IsRock(newC, playerR + 1) && !IsRock(newC, playerR);
        }

        public bool IsRock(int c, int r)
        {
            if (c < 0 || c >= Rocks.GetLength(1)) return true;
            if (r < 0 || r >= Rocks.GetLength(0)) return true;
            return Rocks[r, c];
        }

        public int NextRow(int c, int r)
        {
            for (int i = 0; ; i++)
                if (IsRock(c, r + i + 1) && !IsRock(c, r + i))
                    return r + i;
        }
    }
}
