using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
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
                string[] s = Console.ReadLine().Split();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(int.Parse(s[0]), int.Parse(s[1]))
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}:\r\n{1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}:\r\n{1}", iCase, ret);
            }
        }

        private string DoWork(int len, int num)
        {
            long MAX = (long)1e+3;
            bool[] comp = new bool[MAX];
            StringBuilder sb = new StringBuilder();

            List<BigInteger> primes = new List<BigInteger>();

            for (long i = 2; i < MAX; i++)
            {
                if (!comp[i])
                {
                    primes.Add(i);
                    for (long j = i + i; j < MAX; j += i)
                    {
                        comp[j] = true;
                    }
                }
            }

            long l1 = 1;
            int realdigits = len - 2;
            BigInteger[] realnumbers = new BigInteger[11];
            BigInteger[] proofs = new BigInteger[11];
            int answers = 0;
            for (long binseed = 0; binseed < l1 << realdigits; binseed++)
            {
                bool allComp = true;
                for (int ibase = 2; ibase <= 10; ibase++)
                {
                    BigInteger col = ibase;
                    realnumbers[ibase] = 1;
                    for (int i = 0; i < realdigits; i++)
                    {
                        if ((binseed & l1 << i) != 0) realnumbers[ibase] += col;
                        col *= ibase;
                    }
                    realnumbers[ibase] += col;
                    proofs[ibase] = 0;

                    for (int p = 0; p < primes.Count && primes[p] * primes[p] <= realnumbers[ibase]; p++)
                    {
                        if (realnumbers[ibase] % primes[p] == 0)
                        {
                            proofs[ibase] = primes[p];
                        }
                    }

                    if (proofs[ibase] == 0)
                    {
                        allComp = false;
                        break;
                    }
                }

                if (allComp)
                {
                    sb.Append(realnumbers[10].ToString());
                    for (int ibase = 2; ibase <= 10; ibase++)
                    {
                        sb.AppendFormat(" {0}", proofs[ibase]);
                    }
                    sb.AppendLine();
                    answers++;
                    System.Diagnostics.Debug.WriteLine(realnumbers[10].ToString());
                    if (answers == num) return sb.ToString();
                }
            }

            return sb.ToString();
        }
    }
}
