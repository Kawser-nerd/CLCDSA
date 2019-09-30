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
        static private int Solve1(int N, LinkedList<double> naomi, LinkedList<double> ken)
        {
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (naomi.First() < ken.First())
                {
                    ken.RemoveLast();
                }
                else
                {
                    ken.RemoveFirst();
                    cnt++;
                }
                naomi.RemoveFirst();
            }
            return cnt;
        }
        static private int Solve2(int N, LinkedList<double> naomi, LinkedList<double> ken)
        {
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (naomi.Last() > ken.Last())
                {
                    ken.RemoveFirst();
                    cnt++;
                }
                else
                {
                    ken.RemoveLast();
                }
                naomi.RemoveLast();
            }
            return cnt;
        }
        static void Main(string[] args)
        {
            string filename = "../D-large";
            StreamReader sr = new StreamReader(filename + ".in");
            StreamWriter sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int N = int.Parse(sr.ReadLine());
                double[] naomi = Array.ConvertAll(sr.ReadLine().Split(' '), double.Parse);
                double[] ken = Array.ConvertAll(sr.ReadLine().Split(' '), double.Parse);
                Array.Sort(naomi);
                Array.Sort(ken);
                int y = Solve1(N, new LinkedList<double>(naomi), new LinkedList<double>(ken));
                int z = Solve2(N, new LinkedList<double>(naomi), new LinkedList<double>(ken));
                sw.WriteLine("Case #{0}: {1} {2}", i, y, z);
                Console.WriteLine("Case #{0}: {1} {2}", i, y, z);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
