using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class LastHit : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int P = int.Parse(s[0]);
                int Q = int.Parse(s[1]);
                int N = int.Parse(s[2]);
                int[] H = new int[N];
                int[] G = new int[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine().Split(' ');
                    H[i] = int.Parse(s[0]);
                    G[i] = int.Parse(s[1]);
                }

                long ret = maxGold(P, Q, N, H, G);

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

        private long maxGold(int playerDamage, int towerDamage, int N, int[] H, int[] G)
        {
            mem = new Dictionary<string, long>();
            
            long ret = maxGold(playerDamage, towerDamage, N, H, G, 0, 1, H[0]);
            return ret;
        }

        private Dictionary<string, long> mem = new Dictionary<string, long>();
        private long maxGold(int playerDamage, int towerDamage, int N, int[] H, int[] G, int curMonster, int shotsSaved, int health)
        {
            if (curMonster == N) return 0;

            string hash = string.Format("{0} {1} {2}", curMonster, shotsSaved, health);
            long ret;
            if (mem.TryGetValue(hash, out ret))
            {
                return ret;
            }

            long best = 0;
            // Bank shot
            int shotsSaved2 = shotsSaved + 1;
            if (health > towerDamage)
            {
                int newhealth = health - towerDamage;
                best = Math.Max(best, maxGold(playerDamage, towerDamage, N, H, G, curMonster, shotsSaved + 1, newhealth));
            }
            else
            {
                int newhealth;
                if (curMonster < N - 1)
                {
                    newhealth = H[curMonster + 1];
                }
                else
                {
                    newhealth = 0;
                }
                best = Math.Max(best, maxGold(playerDamage, towerDamage, N, H, G, curMonster + 1, shotsSaved + 1, newhealth));
            }

            // Kill monster
            int shotsToKill = (health + playerDamage - 1) / playerDamage;
            if (shotsSaved >= shotsToKill)
            {
                int newhealth;
                if (curMonster < N - 1)
                {
                    newhealth = H[curMonster + 1];
                }
                else
                {
                    newhealth = 0;
                }
                best = Math.Max(best, G[curMonster] + maxGold(playerDamage, towerDamage, N, H, G, curMonster + 1, shotsSaved - shotsToKill, newhealth));
            }

            mem[hash] = best;
            return best;
        }
    }
}
