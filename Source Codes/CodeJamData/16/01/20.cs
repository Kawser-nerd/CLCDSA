using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace CodeJam2106
{
    class CountingSheep
    {
        private const string NO_ANSWER = "INSOMNIA";


        public static void SolveAll()
        {
            using (StreamReader reader = File.OpenText("input.txt"))
            {
                using (StreamWriter writer = File.CreateText("output.txt"))
                {
                    int T = int.Parse(reader.ReadLine());
                    for (int i = 0; i < T; i++)
                    {
                        int N = int.Parse(reader.ReadLine());
                        int solution = Solve(N);
                        if(solution == -1)
                        {
                            writer.WriteLine(string.Format("case #{0}: {1}", i + 1, NO_ANSWER));
                        }
                        else
                        {
                            writer.WriteLine(string.Format("case #{0}: {1}", i + 1, solution));
                        }
                    }
                }
            }
                
        }

        public static int Solve(int n)
        {
            if(n == 0)
            {
                return -1;
            }

            bool[] counted = new bool[10];
            for (int i = 0; i < counted.Length; i++)
            {
                counted[i] = false;
            }

            int s = n;
            while(true)
            {
                int digits = s;
                while (digits != 0)
                {
                    counted[digits % 10] = true;
                    digits /= 10;
                }
                if(counted.Aggregate(true, (x, y) => x && y))
                {
                    return s;
                }
                s += n;
            }
        }
    }
}
