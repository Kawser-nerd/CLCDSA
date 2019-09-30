using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MagicTrick
{
    class Program
    {
        static private int[] Solve(int r1, int[][] first, int r2, int[][] second)
        {
            return Array.FindAll(first[r1 - 1], x => second[r2 - 1].Contains(x));
        }
        static void Main(string[] args)
        {
            string filename = "../A-small-attempt0";
            StreamReader sr = new StreamReader(filename + ".in");
            StreamWriter sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int r1 = int.Parse(sr.ReadLine());
                int[][] first = new int[4][];
                for (int j = 0; j < 4; j++) { first[j] = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse); }
                int r2 = int.Parse(sr.ReadLine());
                int[][] second = new int[4][];
                for (int j = 0; j < 4; j++) { second[j] = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse); }
                int[] row = Solve(r1, first, r2, second);
                string res = (row.Length == 0) ? "Volunteer cheated!"
                           : (row.Length == 1) ? row[0].ToString()
                                               : "Bad magician!";
                sw.WriteLine("Case #{0}: {1}", i, res);
                Console.WriteLine("Case #{0}: {1}", i, res);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
