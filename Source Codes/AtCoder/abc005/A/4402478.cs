using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] N=Console.ReadLine().Split(' ');
            int x = int.Parse(N[0]);
            int y = int.Parse(N[1]);
            Console.WriteLine(y / x);
        }
    }
}