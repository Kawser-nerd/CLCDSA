using System;

namespace AtCoder.ABC094
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);

            if (c >= a && c <= a + b)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC094.A.Solve();
        }
    }
}