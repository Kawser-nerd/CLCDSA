using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {



        public static void Main(string[] args)
        {
            var NM = System.Console.ReadLine().Split();
            int N = int.Parse(NM[0]);
            int M = int.Parse(NM[1]);

            bool[] from1 = new bool[N+1];
            bool[] toN = new bool[N+1];

            for (int i = 0; i < M; i++)
            {
                var ab = System.Console.ReadLine().Split();
                int a = int.Parse(ab[0]);
                int b = int.Parse(ab[1]);

                if (a == 1)
                {
                    from1[b] = true;
                    if (toN[b] == true)
                    {
                        System.Console.WriteLine("POSSIBLE");
                        return;
                    }
                }

                if (b == N)
                {
                    toN[a] = true;
                    if (from1[a] == true)
                    {
                        System.Console.WriteLine("POSSIBLE");
                        return;
                    }
                }
            }

            System.Console.WriteLine("IMPOSSIBLE");
        }
    }
}