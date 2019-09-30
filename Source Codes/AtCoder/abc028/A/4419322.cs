using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            if (N<=59)
            {
                Console.WriteLine("Bad");
            }
            else if (60<=N&&N<=89)
            {
                Console.WriteLine("Good");
            }
            else if (90 <= N && N <= 99)
            {
                Console.WriteLine("Great");
            }
            else if (N==100)
            {
                Console.WriteLine("Perfect");
            }
        }
    }
}