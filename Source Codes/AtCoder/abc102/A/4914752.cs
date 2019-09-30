using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            int n = int.Parse(Console.ReadLine());

            if (n%2==0)
            {
                Console.WriteLine(n);
            }
            else
            {
                Console.WriteLine(n * 2);
            }
        }
    }
}