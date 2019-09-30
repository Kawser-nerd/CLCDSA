using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1B_B
{
    class ProgramB
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"d:\Devel\X\GoogleCodeJamPractice\00_ProblemData\B2.in"))
            using (StreamWriter sw = new StreamWriter(@"d:\Devel\X\GoogleCodeJamPractice\00_ProblemData\B2.out"))
            {
                string line;
                string[] parts;

                line = sr.ReadLine();
                int T = int.Parse(line);
                
                for (int testcase = 0; testcase < T; testcase++)
                {
                    line = sr.ReadLine();
                    parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int C = int.Parse(parts[0]);
                    int D = int.Parse(parts[1]);

                    int[] P = new int[C];
                    int[] V = new int[C];
                    int remainingVendors = 0;
                    for (int i = 0; i < C; i++)
                    {
                        line = sr.ReadLine();
                        parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int p = int.Parse(parts[0]);
                        int v = int.Parse(parts[1]);

                        P[i] = p;
                        V[i] = v;
                        remainingVendors += v;
                    }

                    double duration = 0.0;

                    int sptr = 0;

                    sptr = 0;

                    int localsum = V[sptr];
                    for (int i = sptr + 1; i < C; i++)
                    {
                        if (P[i] - P[sptr] > D * localsum)
                        {
                            Calculate(C, D, P, V, remainingVendors, ref duration, sptr, i - 1);
                            sptr = i;
                            localsum = V[i];
                        }
                        else
                        {
                            localsum += V[i];
                        }
                    }
                    Calculate(C, D, P, V, remainingVendors, ref duration, sptr, C - 1);
                    
                    sw.WriteLine("Case #{0}: {1:N}", testcase + 1, duration);
                    Console.WriteLine("Case #{0}: {1:N}", testcase + 1, duration);
                }
            }

        }

        private static void Calculate(int C, int D, int[] P, int[] V, 
            int remainingVendors, ref double duration, int sptr_orig, int eptr_orig)
        {
            int localRemaining = 0;

            int sptr = sptr_orig;
            int eptr = eptr_orig;

            Console.WriteLine( "Start stop: {0} {1}", sptr, eptr );

            for (int i = sptr; i <= eptr; i++)
            {
                localRemaining += V[i];
            }
            while (localRemaining > 1)
            {
                int distance = Math.Abs(P[sptr] - P[eptr]);
                int neededdistance = (localRemaining - 1) * D;

                double time = (double)(neededdistance - distance) / 2.0;

                if (time >= 0)
                {
                    if (time >= duration)
                    {
                        duration = time;
                    }
                }

                double sd, ed;

                if (V[sptr] > 1) sd = 0;
                else sd = Math.Abs(P[sptr + 1] - P[sptr]);

                if (V[eptr] > 1) ed = 0;
                else ed = Math.Abs(P[eptr - 1] - P[eptr]);

                if (sd > ed)
                {
                    V[sptr]--;
                    if (V[sptr] == 0) sptr++;
                }
                else
                {
                    V[eptr]--;
                    if (V[eptr] == 0) eptr--;
                }

                localRemaining -= 1;

                if (sptr >= eptr && (sptr == C || V[sptr] == 0)) break;
            }
        }
    }
}
