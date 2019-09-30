using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class DeceitfulWar : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int N = int.Parse(s);
                string[] s2 = Console.ReadLine().Split(' ');
                List<double> dNaomi = s2.ToList().ConvertAll<double>(sval => double.Parse(sval));
                s2 = Console.ReadLine().Split(' '); 
                List<double> dKen = s2.ToList().ConvertAll<double>(sval => double.Parse(sval));
                string ret = MaxWins(N, dNaomi, dKen);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }


        private Dictionary<string, int> mem = new Dictionary<string, int>();
        private string MaxWins(int N, List<double> dNaomi, List<double> dKen)
        {
            //mem = new Dictionary<string, int>();
            char[] state = new char[N*2];
            dNaomi.Sort();
            dKen.Sort();
            int n=0;
            int k=0;

            while (N > n && N > k)
            {
                if (dNaomi[n] > dKen[k])
                {
                    state[n + k++] = 'K';
                }
                else
                {
                    state[n++ + k] = 'N';
                }
            }

            while (N > n)
            {
                state[n++ + k] = 'N';
            }
            while (N > k)
            {
                state[n + k++] = 'K';
            }

            int ret = getmax(new string(state));
            int naive = getnaivemax(new string(state));
            return string.Format("{0} {1}", ret, naive);
        }

        private int getnaivemax(string state)
        {
            int ret = 0;
            while (state.Length>0)
            {
                int highestN = state.LastIndexOf('N');
                if (highestN == state.Length - 1)
                {
                    int lowestK = state.IndexOf('K');
                    state = state.Remove(highestN, 1).Remove(lowestK, 1);
                    ret++;
                }
                else
                {
                    int nextK = state.IndexOf('K', highestN);
                    state = state.Remove(nextK, 1).Remove(highestN, 1);
                }
            }
            return ret;
        }

        private int getmax(string state)
        {
            int ret = 0;
            if (mem.TryGetValue(state, out ret))
            {
                return ret;
            }

            // Win a point, there must exist K..N. Use lowest K, next N.
            int lowestK = state.IndexOf('K');
            int nextN = state.IndexOf('N', lowestK + 1);
            if (nextN > lowestK)
            {
                //string nextstate = state.Substring(0, lowestK) + state.Substring(lowestK + 1, nextN - lowestK - 1) + state.Substring(nextN + 1);
                string nextstate = state.Remove(nextN, 1).Remove(lowestK, 1);
                int winmax = 1 + getmax(nextstate);
                ret = winmax;
            }

            // Lose a point. There must exist N..K. Use highest K, lowest N.
            int highestK = state.LastIndexOf('K');
            int lowestN = state.IndexOf('N');
            if (lowestN < highestK && ret==0)
            {
                //string nextstate = state.Substring(0, lowestN) + state.Substring(lowestN + 1, highestK - lowestN - 1) + state.Substring(highestK + 1);
                string nextstate = state.Remove(highestK, 1).Remove(lowestN, 1);
                int losemax = getmax(nextstate);
                if (losemax > ret && ret > 0) System.Diagnostics.Debugger.Break();
            }

            mem[state] = ret;
            return ret;
        }

    }
}
