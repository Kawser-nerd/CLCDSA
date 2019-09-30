using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cShaprTest
{
    class Program
    {
        public static int N { get; private set; }
        public static int A { get; private set; }
        public static int B { get; private set; }
        public static int C { get; private set; }

        private static int max;
        private static int[] l;

        static void Main(string[] args)
        {
            var NABC = Console.ReadLine().Split().Select(int.Parse).ToArray();
            N = NABC[0];
            A = NABC[1];
            B = NABC[2];
            C = NABC[3];

            max = int.MaxValue;
            l = new int[N];
            for (var i = 0; i < N; i++)
            {
                l[i] = int.Parse(Console.ReadLine());
            }

            var ans = Dfs(0, 0, 0, 0);
            Console.WriteLine(ans);
        }


        public static int Dfs(int index, int a, int b, int c)
        {
           // Console.WriteLine(index);
          //  Console.WriteLine(N);
 //           Console.WriteLine();

            if (index == N)
            {
                if (a == 0 || b == 0 || c == 0)
                {
                    return 100000;
                }
//                Console.WriteLine(Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c));
                return Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c) - 30;
            }
            var pattern = new int[4];

            pattern[0] = Dfs(index + 1, a, b, c);

            pattern[1] = Dfs(index + 1, a + l[index], b, c) + 10;
            pattern[2] = Dfs(index + 1, a, b + l[index], c) + 10;
            pattern[3] = Dfs(index + 1, a, b, c + l[index]) + 10;

            return pattern.Min();
        }
    }
}