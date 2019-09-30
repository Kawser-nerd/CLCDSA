using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

class DeceitfulWar
{
    public void Solve()
    {
        StreamReader sr = new StreamReader(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\D.in");
        StreamWriter sw = new StreamWriter(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\D.out");

        int test_cases = Int32.Parse(sr.ReadLine());
        for (int t = 1; t <= test_cases; t++)
        {
            int N = Int32.Parse(sr.ReadLine());
            string[] str_naomi = sr.ReadLine().Split();
            string[] str_ken = sr.ReadLine().Split();
            double[] naomi = new double[N];
            double[] ken = new double[N];

            for (int i = 0; i < N; i++)
            {
                naomi[i] = Double.Parse(str_naomi[i]);
                ken[i] = Double.Parse(str_ken[i]);
            }

            // Naomi's strategy moves from the bottom of her list to the top.
            // If she can beat Ken's lowest element, she does so (by saying her block
            // is a billion and Ken will throw his lowest). If she cannot, she
            // uses it to remove Ken's highest block (by saying it is a teeny bit
            // less than Ken's)

            Array.Sort(naomi);
            Array.Sort(ken);

            int removed_from_ken = 0;
            for (int i = 0; i < N; i++)
            {
                if (naomi[i] > ken[removed_from_ken])
                {
                    removed_from_ken++;
                }
            }

            // We can argue the non-deceitful version in many ways, but long story
            // short it's just the same as Naomi playing the deceitful version. i.e.
            // in both versions, one of the two has a strategy available so that the
            // result can be optimal for them

            int removed_from_naomi = 0;
            for (int i = 0; i < N; i++)
            {
                if (ken[i] > naomi[removed_from_naomi])
                {
                    removed_from_naomi++;
                }
            }

            string output = String.Format("Case #{0}: {1} {2}", t, removed_from_ken, N - removed_from_naomi);

            Console.WriteLine(output);
            sw.WriteLine(output);
        }

        sr.Close();
        sw.Close();
    }
}