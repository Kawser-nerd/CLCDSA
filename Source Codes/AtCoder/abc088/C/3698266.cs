using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class ABC
    {
        static void Main(string[] args)
        {
            int[][] N = new int[3][];
            for (int i = 0; i < 3; i++)
            {
                N[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
            }

            bool j = true;
            if (N[0][0] + N[1][1] + N[2][2] != N[2][0] + N[1][1] + N[0][2]) j = false;
            if (N[0][0] + N[1][2] + N[2][1] != N[0][2] + N[1][0] + N[2][1]) j = false;
            if (N[0][1] + N[1][0] + N[2][2] != N[0][1] + N[1][2] + N[2][0]) j = false;

            int sum = 0;
            for(int i = 0; i < 3; i++)
            {
                for(int k = 0; k < 3; k++)
                {
                    sum += N[i][k];
                }
            }

            if (sum / 3 != N[0][0] + N[1][1] + N[2][2]) j = false;
            if (sum / 3 != N[0][0] + N[1][2] + N[2][1]) j = false;
            if (sum / 3 != N[0][1] + N[1][0] + N[2][2]) j = false;

            Console.WriteLine(j ? "Yes" : "No");
            Console.ReadLine();
        }
    }
}