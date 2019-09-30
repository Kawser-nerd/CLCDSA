using System;
using System.IO;
using System.Collections.Generic;
using Oyster.Math;

public class Q
{
    private static IntX gcj(IntX a, IntX b)
    {
        if (a < b) return gcj(b, a);
        if (b == 0) return a;
        return gcj(b, a % b);
    }


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
                    long n = int.Parse(strs[0]);

                    IntX[] values = new IntX[n];
                    for (int j = 0; j < n; ++j) values[j] = IntX.Parse(strs[j + 1]);
                    Array.Sort(values);

                    IntX common = values[1] - values[0];
                    for (int j = 2; j < n; ++j)
                    {
                        common = gcj(common, values[j] - values[j - 1]);
                    }

                    IntX val = common - values[0] % common;

                    string line = "Case #" + (i + 1) + ": " + (val % common);

                    Console.WriteLine(line);
                    sw.WriteLine(line);
                }
            }
        }
        catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
        Console.WriteLine("press any key to quit");
        Console.ReadKey();
    }
}