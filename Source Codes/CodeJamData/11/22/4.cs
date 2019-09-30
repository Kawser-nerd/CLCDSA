using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Diagnostics;


namespace _1B_B
{

    class Program
    {

        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int C;
                Int64 D;
                int[] P, V;
                str = Console.ReadLine();
                strs = str.Split(' ');
                C = int.Parse(strs[0]);
                D = Int64.Parse(strs[1]);

                P = new int[C];
                V = new int[C];
                for (int i = 0; i < C; i++)
                {
                    str = Console.ReadLine();
                    strs = str.Split(' ');
                    P[i] = int.Parse(strs[0]);
                    V[i] = int.Parse(strs[1]);
                }


                //準備完了

                double count = 0;
                double d;

                for (int i = 0; i < C; i++)
                {
                    for (int j = i; j < C; j++)
                    {
                        Int64 Vsum = -1;
                        for (int k = i; k <= j; k++)
                        {
                            Vsum += V[k];
                        }
                        d = ((Vsum * D) - (P[j] - P[i])) / (double)2;
                        if (d > count) { count = d; }
                    }
                }
                            


                Console.WriteLine("Case #" + caseNumber + ": " + count);


            }
            Debug.WriteLine("fin");

            Console.ReadLine();

        }
    }
}
