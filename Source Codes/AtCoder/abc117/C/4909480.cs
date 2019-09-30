using System;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            var arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int N = arr[0], M = arr[1];
            var X = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(val => val).ToArray();
            var delta = new int[M - 1];
            for (var i = 0; i < delta.Length; i++) delta[i] = X[i + 1] - X[i];
            delta = delta.OrderBy(val => val).ToArray();
            int sum = 0;
            for (int i = 0; i < M - N; i++)
            {
                sum += delta[i];
            }

            Console.WriteLine(sum);
        }
    }
}