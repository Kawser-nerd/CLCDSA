using System;

namespace AtCoder.ABC104
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            
            var rank = ""; 
            if (a < 1200)
            {
                rank = "ABC";
            }
            else if (1200 <= a && a < 2800)
            {
                rank = "ARC";
            }
            else
            {
                rank = "AGC";
            }
            
            Console.WriteLine(rank);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC104.A.Solve();
        }
    }
}