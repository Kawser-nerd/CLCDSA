using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace A
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
                BigInteger N = BigInteger.Parse(sLine);

                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                if (N != 0)
                {
                    BigInteger nResult = Solve(N);
                    oAnswer.Append(nResult);
                }
                else
                {
                    oAnswer.Append("INSOMNIA");
                }

                // write answer
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static BigInteger Solve(BigInteger N)
        {
            bool[] aSeen = new bool[10];
            BigInteger i = new BigInteger(0);

            BigInteger? s;
            do
            {
                i++;
                s = Solve(N, i, aSeen);
            }
            while (!s.HasValue);

            return s.Value;
        }

        static BigInteger? Solve(BigInteger bN, BigInteger i, bool[] aSeen)
        {
            BigInteger x = bN * i;
            string s = x.ToString();

            foreach(char c in s)
            {
                int n = c - '0';
                aSeen[n] = true;
            }

            foreach (bool b in aSeen)
                if (!b)
                    return null;

            return x;
        }
    }
}
