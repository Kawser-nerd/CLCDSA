using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());
            int Y = int.Parse(Console.ReadLine());

            if (N <= K)
            {
                Console.Write(X * N);
            }
            else
            {
                Console.Write(X * K + (N - K) * Y);
            }
            System.Threading.Thread.Sleep(1000);
        }
    }
}