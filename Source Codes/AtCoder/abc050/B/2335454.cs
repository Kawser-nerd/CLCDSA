using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            long sum = 0;
            int N = int.Parse(Console.ReadLine());
            String[] str = Console.ReadLine().Split(' ');
            var T= new int[101];

            for(int i = 0; i < N; i++)
            {
                T[i] = int.Parse(str[i]);
                sum += T[i];
            }
            int M = int.Parse(Console.ReadLine());
            var P = new int[101];
            var X = new int[101];
            for (int i = 0; i < M; i++)
            {
                String[] tmpstr = Console.ReadLine().Split(' ');
                P[i] = int.Parse(tmpstr[0])-1;
                X[i] = int.Parse(tmpstr[1]);
            }
            for (int i = 0; i < M; i++)
            {
                Console.WriteLine(sum + (X[i] - T[P[i]]));

            }


        }
    }
}