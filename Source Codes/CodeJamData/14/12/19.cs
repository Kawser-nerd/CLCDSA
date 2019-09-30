using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FullBinaryTree
{
    class Program
    {
        static void Main(string[] args)
        {
            var inStr = File.ReadAllLines("data_in.txt");
            int cLines = 1;
            List<string> res = new List<string>();
            int nCases = int.Parse(inStr[0]);
            for (int cCases=0;cCases<nCases;++cCases)
            {
                int nNodes = int.Parse(inStr[cLines]);
                int bestAnswer = int.MaxValue;
                for (int considerNode=0;considerNode<nNodes;++considerNode)
                {
                    Calc calc = new Calc(nNodes);
                    for (int cNode = 0; cNode < nNodes - 1; ++cNode)
                    {
                        int[] vals = inStr[cLines + 1 + cNode].Split(' ').Select(int.Parse).ToArray();
                        calc.Connect(vals[0] - 1, vals[1] - 1);
                    }
                    int resu = calc.GetResu(considerNode);
                    bestAnswer = Math.Min(bestAnswer, resu);
                }
                cLines += 1 + nNodes-1;
                res.Add("Case #" + (cCases + 1) + ": " + bestAnswer);
            }
            File.WriteAllLines("data_out.txt", res);
        }
    }
}
