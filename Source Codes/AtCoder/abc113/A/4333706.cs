using System;

namespace AtCoder.ABC113
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            
            
            Console.WriteLine((a + (b / 2)));
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC113.A.Solve();
        }
    }
}