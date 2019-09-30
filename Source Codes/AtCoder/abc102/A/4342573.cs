using System;

namespace AtCoder.ABC102
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);

            var val = 0;
            if (a % 2 == 0)
            {
                val = a;
            }
            else
            {
                val = a * 2;
            }
            
            Console.WriteLine(val);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC102.A.Solve();
        }
    }
}