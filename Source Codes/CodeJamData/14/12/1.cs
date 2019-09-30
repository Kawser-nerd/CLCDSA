using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class FullBinaryTree : GCJBase
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
                bool[,] con = new bool[N, N];
                for (int i = 0; i < N-1; i++)
                {
                    string[] s2 = Console.ReadLine().Split(' ');
                    con[int.Parse(s2[0]) - 1, int.Parse(s2[1]) - 1] = true;
                    con[int.Parse(s2[1]) - 1, int.Parse(s2[0]) - 1] = true;
                }
                long ret = MinFixTree(N, con);

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

        Dictionary<int, int> memFix;
        Dictionary<int, int> memCount;
        int MinFixTree(int N, bool[,] con)
        {
            memFix = new Dictionary<int, int>();
            memCount = new Dictionary<int, int>();
            int ret = int.MaxValue;
            for (int i = 0; i < N; i++)
            {
                int ret2 = MinFixTree(N, con, i, -1);
                ret = Math.Min(ret, ret2);
            }
            return ret;
        }

        int MinFixTree(int N, bool[,] con, int node, int parent)
        {
            int npHash = getHash(node, parent);
            int ret;
            if (memFix.TryGetValue(npHash, out ret))
            {
                return ret;
            }

            List<int> children = new List<int>();
            for (int i = 0; i < N; i++)
            {
                if (i != parent && con[i, node])
                {
                    children.Add(i);
                }
            }

            if (children.Count == 0)
            {
                ret = 0;
            }
            else if (children.Count == 1)
            {
                ret = ChildNodeCount(N, con, children[0], node);
            }
            else
            {
                // Count>=2
                List<int> fixSaveCounts = new List<int>();
                int cuttot = 0;
                for (int i = 0; i < children.Count; i++)
                {
                    int fix = MinFixTree(N, con, children[i], node);
                    int cut = ChildNodeCount(N, con, children[i], node);
                    fixSaveCounts.Add(cut - fix);
                    cuttot += cut;
                }
                fixSaveCounts.Sort();
                ret = cuttot;
                ret -= fixSaveCounts[fixSaveCounts.Count - 1] + fixSaveCounts[fixSaveCounts.Count - 2];
            }

            memFix[npHash] = ret;
            return ret;
        }

        int ChildNodeCount(int N, bool[,] con, int node, int parent)
        {
            int npHash = getHash(node, parent);
            int ret;
            if (memCount.TryGetValue(npHash, out ret))
            {
                return ret;
            }

            ret = 1;
            for (int i = 0; i < N; i++)
            {
                if (i != parent && con[i, node])
                {
                    ret += ChildNodeCount(N, con, i, node);
                }
            }

            memCount[npHash] = ret;
            return ret;
        }

        private int getHash(int node, int parent)
        {
            int ret = (node << 12) | (parent+1);
            return ret;
        }

    }
}
