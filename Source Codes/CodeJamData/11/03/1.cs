using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemC
{
    class Program
    {
        static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            int N = Convert.ToInt32(sr.ReadLine());
            string[] argv = sr.ReadLine().Split();

            int result = 0;
            int smallest = int.MaxValue;
            int sum = 0;
            for (int i = 0; i < N; i++) 
            {
                int arg = Convert.ToInt32(argv[i]);
                result ^= arg;
                sum += arg;
                if (smallest > arg) smallest = arg;
            }

            Console.WriteLine("Case #{0}: {1}", caseNo, result == 0 ? (sum - smallest).ToString() : "NO");
            sw.WriteLine("Case #{0}: {1}", caseNo, result == 0 ? (sum - smallest).ToString() : "NO");
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
