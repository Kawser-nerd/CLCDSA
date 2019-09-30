using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace ManyPrizes
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt1.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt1.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');


                long N = Convert.ToInt64(str[0]);
                long P = Convert.ToInt64(str[1]);

                long guaranteed = GetGuaranteedTeam(N, P);

                long possible = Power(2, N) - GetGuaranteedTeam(N, Power(2, N) - P) - 2; ;

                if (P == Power(2, N))
                {
                    guaranteed = Power(2, N)-1;
                    possible = guaranteed;
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(guaranteed.ToString() + " " + possible);
                sw.WriteLine();

            }
            sw.Close();
        }

        static long Power(long num, long N)
        {
            long p = 1;

            for (int j = 0; j < N; j++)
            {
                p *= num;
            }

            return p;
        }

        static long GetGuaranteedTeam(long N, long P)
        {
            long guaranteed = 0;

            long numTeams = Power(2, N);


            for (long j = N; j > 0; j--)
            {
                long tempPower = Power(2, j);

                if (P > numTeams - tempPower)
                {
                    guaranteed = N - j;
                }
                else break;
            }


            guaranteed = Power(2, guaranteed + 1) - 2;

            return guaranteed;
        }
    }
}
