using System;

namespace AtCoder.ABC096
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            var num = 0;
            if (a <= b)
            {
                num = a;
            }
            else
            {
                num = a - 1;
            }
        
            Console.WriteLine(num);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC096.A.Solve();
        }
    }
}