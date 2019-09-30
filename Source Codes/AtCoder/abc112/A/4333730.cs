using System;

namespace AtCoder.ABC112
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            if (n == 1)
            {
                Console.WriteLine("Hello World");
            } else if (n == 2)
            {
                int a, b;
                a = int.Parse(Console.ReadLine());
                b = int.Parse(Console.ReadLine());
                Console.WriteLine(a + b);
                
            }
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC112.A.Solve();
        }
    }
}