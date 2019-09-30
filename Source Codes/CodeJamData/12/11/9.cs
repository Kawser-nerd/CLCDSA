using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class A
{
    static void Main(string[] args)
    {
        Stopwatch watch = new Stopwatch();
        watch.Start();

        StreamReader sr = null;
        StreamWriter sw = null;

        if (args.Length > 0)
        {
            FileInfo info = new FileInfo(args[0]);
            sr = new StreamReader(info.FullName);
            sw = new StreamWriter(info.FullName.Replace(".in", ".out"));
        }
        else
        {
            //sr = new StreamReader("c:\\codejam\\A-tiny.in");
            //sw = new StreamWriter("c:\\codejam\\A-tiny.out");
            sr = new StreamReader("c:\\codejam\\A-small-attempt0.in");
            sw = new StreamWriter("c:\\codejam\\A-small-attempt0.out");
            //sr = new StreamReader("c:\\codejam\\A-large.in");
            //sw = new StreamWriter("c:\\codejam\\A-large.out");
        }

        int T = Int32.Parse(sr.ReadLine());
        foreach (int caseN in Enumerable.Range(1, T))
        {

            int[] tmp = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int A = tmp[0];
            int B = tmp[1];
            double[] Ps = sr.ReadLine().Split(' ').Select(double.Parse).ToArray();

            double[] pAtLeastN = new double[A + 1];
            pAtLeastN[0] = 1;
            for (int e = 1; e <= A; e++)
            {
                pAtLeastN[e] = pAtLeastN[e - 1] * Ps[e - 1];
            }

            //three cases
            //double c1 = pAtLeastN[B-1] * (A - B) + (1 - pAtLeastN[B-1]) * (2*A - B) + 1;

            double[] cBp = new double[A + 2];
            for (int x = 0; x <= A; x++)
            {
                cBp[x] = pAtLeastN[A - x] * (x + B - A + x + 1) + (1 - pAtLeastN[A - x]) * ( x + B + B - A + x + 2) ;
            }
            //enter case
            //double c3 = 2 + A;
            cBp[A + 1] = 2 + B;



            sw.WriteLine(String.Format("Case #{0}: {1}", caseN, cBp.Min()));
            sw.Flush();

            Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));
        }

        sr.Close();
        sw.Close();
    }
}
