using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace D
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
                string[] aLine = sLine.Split(' ');
                int K = int.Parse(aLine[0]);
                int C = int.Parse(aLine[1]);
                int S = int.Parse(aLine[2]);

                BigInteger[] s = Solve(K, C, S);
                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);

                if (s == null)
                    oAnswer.Append("IMPOSSIBLE");
                else
                {
                    foreach(BigInteger bi in s)
                    {
                        oAnswer.Append(' ');
                        oAnswer.Append(bi);
                    }
                }
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static BigInteger[] Solve(int K, int C, int S)
        {
            int nMinS = K / C;
            if (K % C > 0)
                nMinS++;

            if (nMinS > S)
                return null; // impossible

            BigInteger[] s = new BigInteger[nMinS];
            int nStartDig = 0;
            for(int i=0; i< nMinS; i++)
            {
                BigInteger x = 0;
                for(int d=C-1; d>=0; d--)
                {
                    x += (nStartDig++) * GetPower(K, d);
                    if (nStartDig == K)
                        nStartDig = 0;
                }
                s[i] = x + 1;
            }

            return s;
        }

        static BigInteger GetPower(int K, int nPower)
        {
            if (nPower == 0)
                return 1;
            if (nPower == 1)
                return K;
            return K * GetPower(K, nPower - 1);
        }
    }
}
