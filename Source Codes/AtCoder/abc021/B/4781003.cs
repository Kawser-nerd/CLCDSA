using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC021B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            var line = Console.ReadLine().Split(' ').ToArray();
            var a = int.Parse(line[0]); var b = int.Parse(line[1]);

            var K = int.Parse(Console.ReadLine());

            var path = Console.ReadLine().Split(' ').ToArray();
            int[] P = new int[K];

            int flag = 0;

            for(var i = 0; i < K; i++)
            {
                P[i] = int.Parse(path[i]);
                if(P[i] == a || P[i] == b)
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
            {
                IEnumerable<int> setP = P.Distinct();

                var len = setP.ToArray().Length;

                if(len == K)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}