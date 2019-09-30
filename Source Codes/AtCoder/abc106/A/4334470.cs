using System;

namespace AtCoder.ABC106
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            
            Console.WriteLine((a - 1)*(b - 1));
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC106.A.Solve();
        }
    }
}