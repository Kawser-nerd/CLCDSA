using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class EmtryCards : GCJBase
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
                long stops = long.Parse(s.Split(' ')[0]);
                long lines = long.Parse(s.Split(' ')[1]);
                SortedList<long, long> enterCount = new SortedList<long, long>();
                SortedList<long, long> exitCount = new SortedList<long, long>();
                long expected = 0;
                for (int i = 0; i < lines; i++)
                {
                    string[] people = Console.ReadLine().Split(' ');
                    long enter = long.Parse(people[0]);
                    long exit = long.Parse(people[1]);
                    long count = long.Parse(people[2]);

                    expected += Cost(stops, exit - enter) * count;

                    if (!enterCount.ContainsKey(enter)) enterCount.Add(enter, 0);
                    enterCount[enter] += count;

                    if (!exitCount.ContainsKey(exit)) exitCount.Add(exit, 0);
                    exitCount[exit] += count;
                }
                long ret = MaxLoss(stops, enterCount, exitCount, expected);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long MaxLoss(long stops, SortedList<long, long> enterCount, SortedList<long, long> exitCount, long expected)
        {
            List<long> enterPoints = new List<long>(enterCount.Keys);
            List<long> exitPoints = new List<long>(exitCount.Keys);
            Stack<long> tickets = new Stack<long>();

            int enterIdx = 0;
            int exitIdx = 0;

            long totalcost = 0;

            while (enterIdx < enterPoints.Count || exitIdx < exitPoints.Count)
            {
                bool exit;
                if (enterIdx >= enterPoints.Count)
                {
                    exit = true;
                }
                else if (exitIdx >= exitPoints.Count)
                {
                    exit = false;
                }
                else
                {
                    if (enterPoints[enterIdx] <= exitPoints[exitIdx])
                    {
                        exit = false;
                    }
                    else
                    {
                        exit = true;
                    }
                }

                if (!exit)
                {
                    tickets.Push(enterPoints[enterIdx]);
                    tickets.Push(enterCount[enterPoints[enterIdx]]);
                    enterIdx++;
                }
                else
                {
                    long exitLoc = exitPoints[exitIdx];
                    long exitcount = exitCount[exitPoints[exitIdx]];
                    while (exitcount > 0)
                    {
                        long entercount = tickets.Pop();
                        long entertic = tickets.Pop();

                        long ticcost = Cost(stops, exitLoc - entertic);
                        long count = Math.Min(exitcount, entercount);

                        totalcost += count * ticcost;
                        exitcount -= count;
                        entercount -= count;

                        if (entercount > 0)
                        {
                            tickets.Push(entertic);
                            tickets.Push(entercount);
                        }
                    }

                    exitIdx++;
                }
            }

            return expected - totalcost;
        }

        private long Cost(long stops, long dis)
        {
            if (dis == 0) return 0;
            long P = dis - 1;
            return stops * dis - (P * P + P) / 2;
        }

    }
}
