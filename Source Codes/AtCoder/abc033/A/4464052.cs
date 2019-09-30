using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string N=Console.ReadLine();

            if (N.Substring(0, 1)== N.Substring(1, 1)&& N.Substring(0, 1)== N.Substring(2, 1)&& N.Substring(0, 1)== N.Substring(3, 1))
            {
                Console.WriteLine("SAME");
            }
            else
            {
                Console.WriteLine("DIFFERENT");
            }

        }
    }
}