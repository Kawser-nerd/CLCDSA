using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                int N = int.Parse(Console.ReadLine());
                string[] s = Console.ReadLine().Split();
                int[] bffs = s.Select<string, int>(bff => int.Parse(bff)).ToArray();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(N, bffs)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int N, int[] bffs)
        {
            for (int i = 0; i < N; i++)
            {
                bffs[i] = bffs[i] - 1;
            }

            int ret = 0;

            for (int j = 0; j < 1<<N; j++)
            {
                List<int> kids = new List<int>();
                for (int i = 0; i < N; i++)
                {
                    if ((1 << i & j) != 0) kids.Add(i);
                }
                int M = kids.Count;
                int[] kds = kids.ToArray();
                do
                {
                    bool good = true;
                    for (int i = 0; i < M; i++)
                    {
                        int left = (i + M - 1) % M;
                        int right = (i + 1) % M;
                        if (kds[left]!=bffs[kds[i]] && kds[right]!=bffs[kds[i]])
                        {
                            good = false;
                            break;
                        }
                    }

                    if (good) ret = Math.Max(ret, M);
                } while (bNextPermutation(kds));
            }

            return ret.ToString();
        }

        private bool bNextPermutation(int[] a)
        {
            // Find first reversal, return false if there is none
            int i = a.Length - 2;
            if (i < 0) return false;
            while (a[i] >= a[i + 1])
            {
                i -= 1;
                if (i == -1)
                {
                    System.Array.Sort(a);
                    return false;
                }
            }

            // Find first element greater than reversal
            int j = a.Length - 1;
            while (a[j] <= a[i]) { j -= 1; }

            // Swap
            int aTemp = a[j];
            a[j] = a[i];
            a[i] = aTemp;

            // Reverse remainder
            System.Array.Reverse(a, i + 1, a.Length - i - 1);
            return true;
        }

    }
}
