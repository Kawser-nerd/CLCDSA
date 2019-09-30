using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            string[] args = sr.ReadLine().Split();
            int N = Convert.ToInt32(args[0]);

            int posO = 1;
            int posB = 1;
            int moveO = 0;
            int moveB = 0;
            int time = 0;

            for (int i = 1; i < N * 2; i += 2) {
                char robot = args[i][0];
                int pos = Convert.ToInt32(args[i + 1]);
                if (robot == 'B')
                {
                    int tmp = Math.Abs(pos - posB) - moveB > 0 ? Math.Abs(pos - posB) - moveB : 0;
                    time += 1 + tmp;
                    posB = pos;
                    moveO += 1 + tmp;
                    moveB = 0;
                }
                else 
                {
                    int tmp = Math.Abs(pos - posO) - moveO > 0 ? Math.Abs(pos - posO) - moveO : 0;
                    time += 1 + tmp;
                    posO = pos;
                    moveB += 1 + tmp;
                    moveO = 0;
                }
            }

            Console.WriteLine("Case #{0}: {1}", caseNo, time);
            sw.WriteLine("Case #{0}: {1}", caseNo, time);
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
