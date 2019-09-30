using System;

namespace AtCoder.ABC098
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            var max = -100000000;
            max = Math.Max(max, (a + b));
            max = Math.Max(max, (a - b));
            max = Math.Max(max, (a * b));
        
            Console.WriteLine(max);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC098.A.Solve();
        }
    }
}