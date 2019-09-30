using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc_015_C
{
    class Program
    {
        static int height, weight;
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] a = new int[n[0], n[1]];
            height = n[0];
            weight = n[1];
            for (int i = 0; i < n[0]; i++)
            {
                int[] u = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < n[1]; j++)
                {
                    a[i, j] = u[j];
                }
            }
            Console.WriteLine(!dfs(0, 0, a) ? "Nothing" : "Found");
            Console.ReadLine();
        }
        static bool dfs(int numQ, int value, int[,] a)
        {
            if (numQ == height) { return (value == 0); }
            for (int i = 0; i < weight; i++)
            {
                if (dfs(numQ + 1, value ^ a[numQ, i], a)) { return true; }
            }
            return false;
        }
    }
}