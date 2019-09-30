using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ11Q
{
    class BotTrust : GCJBase
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
                long ret = HowLong(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int HowLong(string s)
        {
            string[] commands = s.Split(' ');
            List<string> moves = new List<string>();
            List<int> BMoves = new List<int>();
            List<int> OMoves = new List<int>();

            for (int i = 1; i < commands.Length; i += 2)
            {
                moves.Add(commands[i] + commands[i + 1]);
                if (commands[i] == "B") BMoves.Add(int.Parse(commands[i + 1]));
                if (commands[i] == "O") OMoves.Add(int.Parse(commands[i + 1]));
            }

            int bloc = 1;
            int oloc = 1;
            int bidx = 0;
            int oidx = 0;
            int secs = 0;
            int idx = 0;
            while (idx < moves.Count)
            {
                secs++;
                bool bmoved = true;
                if (bidx < BMoves.Count)
                {
                    int btarget = BMoves[bidx];
                    if (btarget == bloc)
                    {
                        bmoved = false;
                    }
                    else if (btarget < bloc)
                    {
                        bloc--;
                    }
                    else if (btarget > bloc)
                    {
                        bloc++;
                    }
                }

                bool omoved = true;
                if (oidx < OMoves.Count)
                {
                    int otarget = OMoves[oidx];
                    if (otarget == oloc)
                    {
                        omoved = false;
                    }
                    else if (otarget < oloc)
                    {
                        oloc--;
                    }
                    else if (otarget > oloc)
                    {
                        oloc++;
                    }
                }

                if (moves[idx][0] == 'B' && !bmoved && bloc == BMoves[bidx])
                {
                    bidx++;
                    idx++;
                } else if (moves[idx][0] == 'O' && !omoved && oloc == OMoves[oidx])
                {
                    oidx++;
                    idx++;
                }
            }
            return secs;
        }

    }
}
