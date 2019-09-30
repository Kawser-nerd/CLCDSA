using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            for (int i = 0;; i++)
            {
                if (N-111*(i+1)<=0)
                {
                    Console.WriteLine(111*(i+1));
                    break;
                }
            }
        }
    }
}