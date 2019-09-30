using System;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int ab, bc;

            string[] str = Console.ReadLine().Split(' ');
            ab = int.Parse(str[0]);
            bc = int.Parse(str[1]);
            Console.WriteLine(ab*bc/2);
        }
    }
}