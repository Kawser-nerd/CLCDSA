using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace _2012Q
{
    class _1C_B
    {

        static void Main(string[] args)
        {

            int Tc;

            string str;
            str = Console.ReadLine();
            Tc = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= Tc; caseNumber++)
            {
                double D;
                int N,A;
                str = Console.ReadLine();
                string[] strs = str.Split(' ');
                D = double.Parse(strs[0]);
                N = int.Parse(strs[1]);
                A = int.Parse(strs[2]);

                List<double> T = new List<double>(N);
                List<double> X = new List<double>(N);
                double[] acc = new double[A];

                bool ff = false;
                for (int i = 0; i < N; i++)
                {
                    str = Console.ReadLine();
                    if (ff) { continue; }
                    strs = str.Split(' ');

                    T.Add(double.Parse(strs[0]));
                    X.Add(double.Parse(strs[1]));

                    //CHECK
                    if (X[i] >= D)
                    {
                        if (i == 0) { ff = true; continue; }
                        T[i] = T[i - 1] + (T[i] - T[i - 1]) * (D - X[i - 1]) / (X[i] - X[i - 1]); 
                        X[i] = D;
                        ff = true;
                    }
                }

                str = Console.ReadLine();
                strs = str.Split(' ');

                Console.WriteLine("Case #" + caseNumber + ":");

                for (int i = 0; i < A; i++)
                {
                    acc[i] = double.Parse(strs[i]);

                    double ReqDelay = X.Select((x, id) => T[id] -  Math.Sqrt(2 * x/ acc[i]) ).Max();
                    
                    if (ReqDelay < 0) { ReqDelay = 0; }

                    Console.WriteLine(ReqDelay + Math.Sqrt(2 * D / acc[i]));
                }

            }

            Console.ReadLine();
        }


    }
}
