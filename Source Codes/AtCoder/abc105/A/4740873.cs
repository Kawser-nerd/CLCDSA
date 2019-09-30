using System;

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
            string[] N_K = Console.ReadLine().Split(' ');
            int n = int.Parse(N_K[0]);
            int k = int.Parse(N_K[1]);

            if(n%k == 0)
            {
                Console.WriteLine("0");
            }
            else
            {
                Console.WriteLine("1");
            }
        }
    }
}