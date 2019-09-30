using System;

namespace AtCoder.ABC099
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);

            if (a >= 1000)
            {
                Console.WriteLine("ABD");
            }
            else
            {
                Console.WriteLine("ABC");
            }
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC099.A.Solve();
        }
    }
}