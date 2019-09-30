using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        private static int Solve(int R, int C, int W)
        {
            int n = C / W * R + W;
            return C % W == 0 ? n - 1 : n;
        }
        static void Main(string[] args)
        {
            string filename = "../A-large";
            var sr = new StreamReader(filename + ".in");
            var sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                var values = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                int result = Solve(values[0], values[1], values[2]);
                sw.WriteLine("Case #{0}: {1}", i + 1, result);
                Console.WriteLine("Case #{0}: Done", i + 1);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
