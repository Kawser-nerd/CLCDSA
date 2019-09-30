using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                int n = sLine.Length;
                bool[] S = new bool[n];
                int j = 0;
                foreach (char c in sLine)
                {
                    S[j] = c == '+';
                    j++;
                }

                int s = Solve(S);
                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                oAnswer.Append(s);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve(bool[] S)
        {
            return Solve(S, S.Length, 0, true);
        }

        static int Solve(bool[] S, int nDepth, int nSteps, bool bTarget)
        {
            bool b = S[nDepth - 1];
            int l = 1;
            for(int i = nDepth - 2; i>=0; i--)
            {
                if (S[i] == b)
                {
                    l++;
                    continue;
                }
                else break;
            }

            nDepth -= l;
            if(nDepth == 0)
            {
                if (bTarget == b)
                    return nSteps;
                else
                    return nSteps + 1;
            }

            if(bTarget == b)
            {
                return Solve(S, nDepth, nSteps, bTarget);
            }
            else
            {
                return Solve(S, nDepth, nSteps + 1, !bTarget);
            }
        }
    }
}
