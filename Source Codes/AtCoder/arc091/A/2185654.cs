using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static int N, M;
        static void Main(string[] args)
        {
            var temp = ReadLinesToIntListList(1);
            N = temp[0][0];
            M = temp[0][1];
            if (N > 2 && M > 2)
            {
                var naka = ((long)N - 2) * ((long)M - 2);

                Console.WriteLine(naka);
            }
            else if(N == 2 || M == 2)
            {
                Console.WriteLine(0);
            }else if (N == 1 && M == 1)
            {
                Console.WriteLine(1);
            }
            else
            {
                var large = N > M ? N : M;
                Console.WriteLine(large - 2);
            }

        }

        static List<List<int>> ReadLinesToIntListList(int n)
        {
            List<List<int>> list = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                list.Add(temp);
            }
            return list;
        }
    }
}