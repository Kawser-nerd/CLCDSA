using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] price = new int[N];
            for (int i = 0; i < N; i++)
            {
                price[i]= int.Parse(Console.ReadLine());
            }
            Console.WriteLine(price.Sum() -price.Max()/2);
        }
    }
}