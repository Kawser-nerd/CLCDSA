using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS
{
    class B
    {
        int AC, AJ;
        List<(int, int)> Cs = new List<(int, int)>();
        List<(int, int)> Js = new List<(int, int)>();

        public static B Parse()
        {
            var pb = new B();
            var parts = Console.ReadLine().Split(' ');
            pb.AC = int.Parse(parts[0]);
            pb.AJ = int.Parse(parts[1]);

            for (int i = 0; i < pb.AC; i++)
            {
                var t = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                pb.Cs.Add((t[0], t[1]));
            }
            for (int i = 0; i < pb.AJ; i++)
            {
                var t = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                pb.Js.Add((t[0], t[1]));
            }
            pb.Cs.Sort();
            pb.Js.Sort();

            return pb;
        }

        public string Solve()
        {
            if (AC == 0 && AJ == 0)
                return "2";
            int minimalChange = 0;
            var potentialC = new List<int>();
            var potentialJ = new List<int>();
            int sureC = 0, sureJ = 0;
            int available = 0;
            int lastC = -1, lastJ = -1;
            int c = 0, j = 0;
            while (c < AC && j < AJ)
            {
                if (Cs[c].Item1 < Js[j].Item1)
                {
                    sureC += Cs[c].Item2 - Cs[c].Item1;
                    if (lastC != -1)
                    {
                        potentialC.Add(Cs[c].Item1 - lastC);
                    }
                    else if (lastJ != -1)
                    {
                        minimalChange++;
                        available += Cs[c].Item1 - lastJ;
                    }
                    lastC = Cs[c].Item2;
                    lastJ = -1;
                    c++;
                }
                else
                {
                    sureJ += Js[j].Item2 - Js[j].Item1;
                    if (lastJ != -1)
                    {
                        potentialJ.Add(Js[j].Item1 - lastJ);
                    }
                    else if (lastC != -1)
                    {
                        minimalChange++;
                        available += Js[j].Item1 - lastC;
                    }
                    lastJ = Js[j].Item2;
                    lastC = -1;
                    j++;
                }
            }
            while (c < AC)
            {
                sureC += Cs[c].Item2 - Cs[c].Item1;
                if (lastC != -1)
                {
                    potentialC.Add(Cs[c].Item1 - lastC);
                }
                else if (lastJ != -1)
                {
                    minimalChange++;
                    available += Cs[c].Item1 - lastJ;
                }
                lastC = Cs[c].Item2;
                lastJ = -1;
                c++;
            }
            while (j < AJ)
            {
                sureJ += Js[j].Item2 - Js[j].Item1;
                if (lastJ != -1)
                {
                    potentialJ.Add(Js[j].Item1 - lastJ);
                }
                else if (lastC != -1)
                {
                    minimalChange++;
                    available += Js[j].Item1 - lastC;
                }
                lastJ = Js[j].Item2;
                lastC = -1;
                j++;
            }
            // the midnight overlap
            if (AC > 0 && (AJ == 0 || Cs[0].Item1 < Js[0].Item1))
            {
                // started with C
                if (lastC != -1)
                {
                    potentialC.Add(Cs[0].Item1 - lastC + 1440);
                }
                else if (lastJ != -1)
                {
                    minimalChange++;
                    available += Cs[0].Item1 - lastJ + 1440;
                }
            }
            else
            {
                // started with J
                if (lastJ != -1)
                {
                    potentialJ.Add(Js[0].Item1 - lastJ + 1440);
                }
                else if (lastC != -1)
                {
                    minimalChange++;
                    available += Js[0].Item1 - lastJ + 1440;
                }
            }
            bool Jneeded = false, Cneeded = false;
            potentialC.Sort();
            for (int i = 0; i < potentialC.Count; i++)
            {
                if (potentialC[i] + sureC <= 720)
                {
                    sureC += potentialC[i];
                }
                else
                {
                    Jneeded = true;
                    minimalChange += 2;
                }
            }
            potentialJ.Sort();
            for (int i = 0; i < potentialJ.Count; i++)
            {
                if (potentialJ[i] + sureJ <= 720)
                {
                    sureJ += potentialJ[i];
                }
                else
                {
                    Cneeded = true;
                    minimalChange += 2;
                }
            }
            Debug.Assert(!(Jneeded && Cneeded));
            return minimalChange.ToString();
        }

        public static void Main(string[] args)
        {
            int nb = int.Parse(Console.ReadLine());
            for (int i = 0; i < nb; i++)
                Console.WriteLine($"Case #{(i + 1)}: {Parse().Solve()}");
        }
    }
}
