using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        static void Main(string[] args)
        {
            string notPossibleStr = "NOT POSSIBLE";
            var inStr = File.ReadAllLines("data_in.txt");
            List<string> res = new List<string>();
            int nCases = int.Parse(inStr[0]);
            int cLine = 1;
            for (int cCases=0;cCases<nCases;++cCases)
            {
                var vals = inStr[cLine++].Split(' ').Select(int.Parse).ToArray();
                int nDev = vals[0];
                int txtLen = vals[1];

                var inputCnf = inStr[cLine++].Split(' ').Select(i => Convert.ToInt64(i, 2)).OrderBy(l => l).ToArray();
                var outputCnf = inStr[cLine++].Split(' ').Select(i => Convert.ToInt64(i, 2)).OrderBy(l => l).ToArray();
                int resu = new Calc(nDev, txtLen, inputCnf, outputCnf).Calculate();
                res.Add("Case #" + (cCases + 1) + ": " + ((resu >= int.MaxValue-1000) ? notPossibleStr : resu.ToString()));
            }
            File.WriteAllLines("data_out.txt", res);
        }
    }
}
