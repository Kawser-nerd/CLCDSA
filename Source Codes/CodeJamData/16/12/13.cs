using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                int N = int.Parse(Console.ReadLine());
                int[,] vals = new int[2 * N - 1, N];
                for (int a = 0; a < 2 * N - 1; a++)
                {
                    string[] s = Console.ReadLine().Split();
                    for (int i = 0; i < N; i++)
                    {
                        vals[a, i] = int.Parse(s[i]);
                    }
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(N, vals)
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int N, int[,] vals)
        {
            Dictionary<int, int> mem = new Dictionary<int, int>();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < 2 * N - 1; j++)
                {
                    int val = vals[j, i];
                    if (!mem.ContainsKey(val))
                    {
                        mem.Add(val, 0);
                    }
                    mem[val]++;
                }
            }

            List<int> ret = new List<int>();
            foreach (var kvp in mem)
            {
                if (kvp.Value % 2 == 1)
                {
                    ret.Add(kvp.Key);
                }
            }

            ret.Sort();

            string sret = "";
            for (int i = 0; i < ret.Count; i++)
            {
                sret += ret[i].ToString();
                if (i < ret.Count - 1) sret += " ";
            }
            return sret;
        }
    }
}
