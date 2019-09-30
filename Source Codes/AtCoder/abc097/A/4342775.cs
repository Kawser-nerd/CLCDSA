using System;

namespace AtCoder.ABC097
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);
            int d = int.Parse(input[3]);

            var res = "No";
            
            if (Math.Abs(a - c) <= d)
            {
                res = "Yes";
            }
            else
            {
                if (Math.Abs(a - b) <= d)
                {
                    if (Math.Abs(b - c) <= d)
                    {
                        res = "Yes";
                    }
                }
            }
        
            Console.WriteLine(res);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC097.A.Solve();
        }
    }
}