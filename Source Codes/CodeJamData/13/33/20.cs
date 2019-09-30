using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Specialized;
using System.IO;

namespace pb1C_c_greatwallofchina
{
    class Program
    {
        static void Main(string[] args)
        {
            //string filename = "test";
            string filename = "C-small-attempt0";
            //string filename = "A-large";

            string inputFile = filename + ".in";
            //string inputFile = "test.in";
            string outputFile = filename + ".out";
            List<long> res = new List<long>();
            using (StreamReader reader = new StreamReader(inputFile))
            {
                string s = reader.ReadLine();
                int nbProblem = int.Parse(s);
                for (int i = 0; i < nbProblem; i++)
                {
                    string l1 = reader.ReadLine();
                    var split = l1.Split(' ');
                    int nbTribes = int.Parse(split[0]);
                    List<Tribes> tribes = new List<Tribes>(nbTribes);
                    for (int j = 0; j < nbTribes; j++)
                    {
                        l1 = reader.ReadLine();
                        split = l1.Split(' ');
                        tribes.Add(new Tribes(split));
                    }

                    res.Add(Solve(tribes));

                }
            }
            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                for (int i = 0; i < res.Count; i++)
                {
                    writer.WriteLine("Case #{0}: {1}", i + 1, res[i]);
                }
            }
        }

        static long Solve(List<Tribes> tribes)
        {
            long res = 0;
            Dictionary<long, long> defenses = new Dictionary<long, long>();
            var allAttacks = tribes.SelectMany(t => t.GetAllAttacks());
            var orderedAttacks = allAttacks.GroupBy(o => o.d).OrderBy(o => o.Key);
            foreach (var dayAttacks in orderedAttacks)
            {
                foreach (Attack attack in dayAttacks)
                {
                    bool success = false;
                    for (long i = attack.w; i < attack.e; i++)
                    {
                        long def;
                        success = success || !defenses.TryGetValue(i, out def) || def < attack.s;
                    }
                    if (success)
                    {
                        res++;
                    }
                }

                foreach (Attack attack in dayAttacks)
                {
                    for (long i = attack.w; i < attack.e; i++)
                    {
                        long def;
                        if (!defenses.TryGetValue(i, out def) || def < attack.s)
                        {
                            defenses[i] = attack.s;
                        }
                    }
                }
            }
            return res;
        }

    }

    class Tribes
    {
        long di;
        long ni;
        long wi;
        long ei;
        long si;
        long delta_di;
        long delta_pi;
        long delta_si;

        public Tribes(string[] line)
        {
            di = long.Parse(line[0]);
            ni = long.Parse(line[1]);
            wi = long.Parse(line[2]);
            ei = long.Parse(line[3]);
            si = long.Parse(line[4]);
            delta_di = long.Parse(line[5]);
            delta_pi = long.Parse(line[6]);
            delta_si = long.Parse(line[7]);
        }

        public List<Attack> GetAllAttacks()
        {
            List<Attack> res = new List<Attack>();
            for (int i = 0; i < ni; i++)
            {
                Attack a = new Attack();
                a.d = di + i * delta_di;
                a.w = wi + i * delta_pi;
                a.e = ei + i * delta_pi;
                a.s = si + i * delta_si;
                res.Add(a);
            }
            return res;
        }

    }

    class Attack
    {
        public long d;
        public long w;
        public long e;
        public long s;
    }
}
