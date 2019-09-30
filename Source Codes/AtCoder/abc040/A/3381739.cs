using System;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int x = int.Parse(input[1]);

            int dif1 = x - 1;
            int dif2 = n - x;

            if(dif1 > dif2)
            {
                Console.WriteLine(dif2);
            }
            else
            {
                Console.WriteLine(dif1);
            }
        }
    }
}