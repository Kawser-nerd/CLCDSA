using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ20121CA {
    class Program {
        int N;
        int[][] arrowTo;
        HashSet<int>[] allArrows;
        void AllDescendantsOf(int index) {
            if (allArrows[index] != null) return;
            allArrows[index] = new HashSet<int>();
            allArrows[index].Add(index);
            foreach (int to in arrowTo[index]) {
                allArrows[index].Add(to);
                if (allArrows[to] == null) AllDescendantsOf(to);
                allArrows[index].UnionWith(allArrows[to]);
            }
        }
        void AllDesc() {
            for (int i = 0; i < N; ++i)
                AllDescendantsOf(i);
        }
        string Solve() {
            AllDesc();
            bool[] HaveChecked = new bool[N];
            for (int i = 0; i < N; ++i) {
                if (HaveChecked[i]) continue;
                // need to check allArrows[i1],allArrows[i2], where i1 & i2 are from arrowTo[i]
                for (int k1 = 0; k1 < arrowTo[i].Length; ++k1) {
                    for (int k2 = k1 + 1; k2 < arrowTo[i].Length; ++k2) {
                        int i1 = arrowTo[i][k1];
                        int i2 = arrowTo[i][k2];
                        HashSet<int> inter = new HashSet<int>(allArrows[i1]);
                        inter.IntersectWith(allArrows[i2]);
                        if (inter.Count > 0) return "Yes";
                    }
                    foreach (int kk in allArrows[k1])
                        HaveChecked[k1] = true;
                }
            }
            return "No";
        }
        Program() {
            int T = int.Parse(Console.ReadLine());
            for (int dd = 0; dd < T; ++dd) {
                N = int.Parse(Console.ReadLine());
                allArrows = new HashSet<int>[N];
                arrowTo = new int[N][];
                for (int i = 0; i < N; ++i) {
                    arrowTo[i] = Console.ReadLine().Split().Skip(1).Select(p => int.Parse(p)-1).ToArray();
                }
                Console.WriteLine("Case #{0}: {1}",dd+1,Solve());
            }
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
