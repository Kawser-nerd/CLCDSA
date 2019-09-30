using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ10R1
{
    class Filefix : GCJBase
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
                int N = int.Parse(s.Split(' ')[0]);
                int M = int.Parse(s.Split(' ')[1]);
                List<string> exist = new List<string>();
                string[] create = new string[M];
                for (int i = 0; i < N; i++)
                {
                    exist.Add(Console.ReadLine());
                }
                for (int i = 0; i < M; i++)
                {
                    create[i] = Console.ReadLine();
                }
                long ret = howmany(exist,create);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int howmany(List<string> startlist, string[] create)
        {
            Dictionary<string, bool> exist = new Dictionary<string,bool>();
            for (int i = 0; i < startlist.Count; i++)
            {
                foreach (string path in allPaths(startlist[i]))
                {
                    if (!exist.ContainsKey(path)) exist.Add(path, true);
                }
            }
            int ret = -exist.Count;

            for (int i = 0; i < create.Length; i++)
            {
                foreach (string path in allPaths(create[i]))
                {
                    if (!exist.ContainsKey(path)) exist.Add(path, true);
                }
            }
            ret += exist.Count;

            return ret;
        }

        private List<string> allPaths(string path)
        {
            List<string> ret = new List<string>();
            do
            {
                ret.Add(path);
                int idx = path.LastIndexOf('/');
                path = path.Substring(0, idx);
            } while (path.Length>0);
            return ret;
        }
    }
}
