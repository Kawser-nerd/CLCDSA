using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ11Q
{
    class Magicka : GCJBase
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
                string[] line = s.Split(' ');
                int idx = 0;
                int count = int.Parse(line[idx++]);
                List<string> pairs = new List<string>();
                for (int i = 0; i < count; i++)
                {
                    pairs.Add(line[idx++]);
                }

                count = int.Parse(line[idx++]);
                List<string> oppose = new List<string>();
                for (int i = 0; i < count; i++)
                {
                    oppose.Add(line[idx++]);
                }
                count = int.Parse(line[idx++]);
                string seq = line[idx];
                System.Diagnostics.Debug.Assert(seq.Length == count);

                char[] result = GetFinalSequence(pairs, oppose, seq);
                string ret = "[";
                for (int i = 0; i < result.Length; i++)
                {
                    ret += result[i];
                    if (i < result.Length - 1) ret += ", ";
                }
                ret += "]";

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private char[] GetFinalSequence(List<string> pairs, List<string> oppose, string seq)
        {
            List<char> cur = new List<char>();
            for (int i = 0; i < seq.Length; i++)
            {
                cur.Add(seq[i]);
                Process(cur, pairs, oppose);
            }

            return cur.ToArray();
        }

        private void Process(List<char> seq, List<string> pairs, List<string> oppose)
        {
            while (seq.Count >= 2)
            {
                char x = seq[seq.Count - 1];
                char y = seq[seq.Count - 2];
                bool changed = false;
                for (int i = 0; i < pairs.Count; i++)
                {
                    if (pairs[i][0] == x && pairs[i][1] == y || pairs[i][0] == y && pairs[i][1] == x)
                    {
                        seq.RemoveRange(seq.Count - 2, 2);
                        seq.Add(pairs[i][2]);
                        changed = true;
                        break;
                    }
                }

                if (changed) continue;

                bool[] appears = new bool[26];
                for (int i = 0; i < seq.Count; i++)
                {
                    appears[seq[i] - 'A'] = true;
                }
                for (int i = 0; i < oppose.Count; i++)
                {
                    if (appears[oppose[i][0] - 'A'] && appears[oppose[i][1] - 'A'])
                    {
                        seq.Clear();
                        return;
                    }
                }
                return;
            }
        }

    }
}
