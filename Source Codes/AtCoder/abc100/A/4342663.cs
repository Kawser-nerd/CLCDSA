using System;

namespace AtCoder.ABC100
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            if (a <= 8 && b <= 8)
            {
                Console.WriteLine("Yay!");
            }
            else
            {
                Console.WriteLine(":(");
            }
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC100.A.Solve();
        }
    }
}