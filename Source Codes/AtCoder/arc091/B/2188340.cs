using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    class Program
    {
        static long N, K;
        static void Main(string[] args)
        {
            var temp = ReadLinesToIntListList(1);
            N = temp[0][0];
            K = temp[0][1];
            long sum = 0;
            if(K == 0)
            {
                Console.WriteLine(N * N);
                return;
            }
            for (long b = K + 1; b <= N; b++)
            {
                var threshold = b - K;
                var q = N / b;
                var mod = N % b;
                var tmp = mod - K + 1;

                sum += q * threshold + (tmp > 0 ? tmp : 0);
            }
            Console.WriteLine(sum);
        }

        static List<List<int>> ReadLinesToIntListList(int n)
        {
            List<List<int>> list = new List<List<int>>();
            for(int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                list.Add(temp);
            }
            return list;
        }

        static List<int> ReadLinesToIntList(int n)
        {
            List<int> list = new List<int>();
            for(int i = 0; i < n; i++)
            {
                var temp = int.Parse(Console.ReadLine());
                list.Add(temp);
            }
            return list;
        }
    }
}