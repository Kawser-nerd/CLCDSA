using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Template
{
    class Program
    {
        class Solver
        {
            int nTribes;
            Tribe[] tribes;
            Dictionary<Int64, UInt64> wall;
            Int64 firstDay = 0;
            UInt64 successfulAttacks = 0;
            class Tribe
            {
                public Int64 d, n, w, e, s, delta_d, delta_p, delta_s;
                public Tribe(string desc)
                {
                    var parameters = desc.Split(' ');
                    d = Convert.ToInt64(parameters[0]);
                    n = Convert.ToInt64(parameters[1]);
                    w = Convert.ToInt64(parameters[2]);
                    e = Convert.ToInt64(parameters[3]);
                    s = Convert.ToInt64(parameters[4]);
                    delta_d = Convert.ToInt64(parameters[5]);
                    delta_p = Convert.ToInt64(parameters[6]);
                    delta_s = Convert.ToInt64(parameters[7]);
                }
                public Int64 updateTribe()
                {
                    d = d + delta_d;
                    e = e + delta_p;
                    w = w + delta_p;
                    s = s + delta_s;
                    n--;
                    if (n == 0) { d = -1; }
                    return d;
                }
                public Int64 getNextDay()
                {
                    return d;
                }
                public uint attack(Dictionary<Int64,UInt64> wall, Dictionary<long,ulong> repairs)
                {
                    uint success = 0;
                    for (Int64 p = w; p < e; p++)
                    {
                        if (!wall.ContainsKey(p)) { wall[p] = 0; }
                        if (wall[p] < (ulong)s)
                        {
                            success++;
                            if (repairs.ContainsKey(p))
                            {
                                repairs[p] = repairs[p] > (ulong)s ? repairs[p] : (ulong)s;
                            }
                            else
                            {
                                repairs[p] = (ulong)s;
                            }
                        }
                    }
                    return success>(uint)0 ? (uint)1:(uint)0;
                }
            }
            public Solver(int n, String[] tribeDesc)
            {
                nTribes = n;
                tribes = new Tribe[n];
                for (int i = 0; i < n; i++)
                {
                    tribes[i] = new Tribe(tribeDesc[i]);
                    Int64 tribeDays = Convert.ToInt64(tribeDesc[i].Split(' ')[0]);
                    firstDay = ((firstDay < tribeDays) && i>0) ? firstDay : tribeDays;
                }
                wall = new Dictionary<long,ulong>();
            }

            public void Solve()
            {
                Int64 day = firstDay;
                while (true)
                {
                    Int64 nextDay=Int64.MaxValue;
                    Dictionary<long, ulong> repairs = new Dictionary<long, ulong>();
                    for (int i = 0; i < nTribes; i++)
                    {
                        if (tribes[i] != null && tribes[i].d == day)
                        {
                            // This tribes attacks today

                            // Do the attack
                            successfulAttacks += tribes[i].attack(wall,repairs);

                            // Update d,e,w,s
                            Int64 nextDayT = tribes[i].updateTribe();
                            if (nextDayT == -1)
                            {
                                tribes[i] = null;
                            }
                            else
                            {
                                nextDay = nextDay > nextDayT ? nextDayT : nextDay;
                            }
                        }
                        else if(tribes[i] != null)
                        {
                            Int64 nextDayT = tribes[i].getNextDay();
                            nextDay = nextDay > nextDayT ? nextDayT : nextDay;
                        }
                    }
                    foreach (var kvp in repairs)
                    {
                        wall[kvp.Key] = kvp.Value;
                    }
                    day = nextDay;
                    if (day == Int64.MaxValue) { break; }
                }
            }

            public String Solution()
            {
                return successfulAttacks.ToString();
            }
        }

        static void Main(string[] args)
        {
            // Create solvers
            int testCases = Convert.ToInt32(Console.ReadLine());
            Solver[] solvers = new Solver[testCases];
            for (int t = 1; t <= testCases; t++)
            {
                int nTribes = Convert.ToInt32(Console.ReadLine());
                String[] tribeDesc = new String[nTribes];
                for (int nt = 0; nt < nTribes; nt++)
                {
                    tribeDesc[nt] = Console.ReadLine();
                }
                solvers[t - 1] = new Solver(nTribes,tribeDesc);
            }

            // Wait for solvers to finish
            Parallel.For(0, testCases, (t) =>
            {
                Console.Error.WriteLine("Starting {0}...", t+1);
                solvers[t].Solve();
                Console.Error.WriteLine("Finished {0}!", t+1);
            });

            // Output results
            for (int t = 1; t <= testCases; t++)
            {
                Console.WriteLine("Case #{0}: {1}", t, solvers[t - 1].Solution());
            }
            Console.ReadLine();
        }
    }
}