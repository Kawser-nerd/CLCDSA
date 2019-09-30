using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemD
{
    class Program
    {
        static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            int N = Convert.ToInt32(sr.ReadLine());

            string[] args = sr.ReadLine().Split();
            double count = 0.0;
            for (int i = 0; i < N; i++)
                if (i+1 != Convert.ToInt32(args[i]))
                    count++;

            Console.WriteLine("Case #{0}: {1:0.000000}", caseNo, count);
            sw.WriteLine("Case #{0}: {1:0.000000}", caseNo, count);
        }

        static void Main(string[] args)
        {
            string file = args[0];
            StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
            StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));
            int maxCase = Convert.ToInt32(sr.ReadLine());

            int caseNo = 1;
            while (caseNo <= maxCase)
            {
                Solve(caseNo, sr, sw);
                caseNo++;
            }

            sr.Close();
            sw.Close();
        }
    }
}
