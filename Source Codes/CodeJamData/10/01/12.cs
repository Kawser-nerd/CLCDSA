using System;
using System.IO;
using System.Collections.Generic;

public class Q1
{
    static void Main(string[] args)
    {
        long[] v = new long[31];
        for (int i = 1; i <= 30; ++i) v[i] = v[i - 1] * 2 + 1;
        try
        {
            using (StreamReader sr = new StreamReader(args[0]))
            using (StreamWriter sw = new StreamWriter(args[1]))
            {
                long t = long.Parse(sr.ReadLine().Trim());
                for (int i = 0; i < t; ++i)
                {
                    string[] strs = sr.ReadLine().Trim().Split(' ');
                    long n = int.Parse(strs[0]), k = int.Parse(strs[1]);

                    string line = "Case #" + (i + 1) + ": " + (k > 0 && k % (v[n] + 1) == v[n] ? "ON" : "OFF");

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





