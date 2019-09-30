using System;

namespace AtCoder.ABC110
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            Console.WriteLine((a * b) % 2 == 0 ? "No" : "Yes");
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC110.A.Solve();
        }
    }
}