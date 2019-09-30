using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {

        

        static void Main(string[] args)
        {

            int[] data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = data[0];
            int M = data[1];
            int X = data[2];

            int[] A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            if (X == N && X == 0) Console.WriteLine(0);

            var dic = new Dictionary<int, int>();
            for(int i = 0; i < M; i++)
            {
                dic[A[i]] = 1;
            }

            int cost1 = 0;
            int cost2 = 0;

            for (int i = X; i <= N; i++)
            {
                if (dic.ContainsKey(i)) cost1++;
            }

            for(int i = X; i >= 0; i--)
            {
                if (dic.ContainsKey(i)) cost2++;
            }

            Console.WriteLine(Math.Min(cost1, cost2));


        }
    }
}