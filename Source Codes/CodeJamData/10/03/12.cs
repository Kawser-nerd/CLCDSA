using System;
using System.IO;
using System.Collections.Generic;

public class Q3
{
    static void Main(string[] args)
    {
        try
        {
            using (StreamReader sr = new StreamReader(args[0]))
            using (StreamWriter sw = new StreamWriter(args[1]))
            {
                long t = long.Parse(sr.ReadLine().Trim());
                for (int i = 0; i < t; ++i)
                {
                    // get values
                    string[] strs = sr.ReadLine().Trim().Split(' ');
                    long r = long.Parse(strs[0]);
                    long k = long.Parse(strs[1]);
                    long n = long.Parse(strs[2]);
                    strs = sr.ReadLine().Trim().Split(' ');
                    long[] gs = new long[n];
                    long[] partsum = new long[n];
                    for (int j = 0; j < n; ++j)
                    {
                        gs[j] = long.Parse(strs[j]);
                        partsum[j] = (j > 0 ? partsum[j - 1] : 0) + gs[j];
                    }

                    long result = 0;
                    if (partsum[n - 1] <= k) result = r * partsum[n - 1];
                    else
                    {
                        long[] visitStepAdd1 = new long[n];
                        long[] stepMoneys = new long[n];

                        long step = 0;
                        long totalmoney = 0;
                        for (int j = 0; j < r; ++j)
                        {
                            visitStepAdd1[step] = j + 1;

                            long nstep = -1;
                            for (long m = n - 1; m > -1; --m)
                            {
                                if (m == 0) throw new Exception("not expected");
                                nstep = (step + m) % n;
                                long v = partsum[(nstep - 1 + n) % n] - (step == 0 ? 0 : partsum[step - 1]);
                                if (nstep > 0 && nstep < step) v += partsum[n - 1];
                                if (v <= k)
                                {
                                    totalmoney += v;
                                    break;
                                }
                            }
                            stepMoneys[j] = totalmoney;

                            long prestepAdd1 = visitStepAdd1[nstep];
                            if (prestepAdd1 == 0)
                            {
                                step = nstep;
                                if (j == r - 1) result = totalmoney;
                                continue;
                            }


                            long loopSteps = (j + 2) - prestepAdd1;
                            long loopMoney = totalmoney - get(prestepAdd1 - 2, stepMoneys);
                            long loopCount = ((r - j - 1) / loopSteps);
                            long leftCount = (r - j - 1) % loopSteps;
                            result = totalmoney + loopMoney * loopCount
                                + get(prestepAdd1 - 2 + leftCount, stepMoneys) - get(prestepAdd1 - 2, stepMoneys);

                            break;
                        }
                    }

                    string line = "Case #" + (i + 1) + ": " + (result);

                    Console.WriteLine(line);
                    sw.WriteLine(line);
                }
            }
        }
        catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
        Console.WriteLine("press any key to quit");
        Console.ReadKey();
    }

    private static long get(long idx, long[] array)
    {
        return idx < 0 ? 0 : array[idx];
    }
}