using System;

namespace ARC57_A
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long a = long.Parse(input[0]);
            long k = long.Parse(input[1]);

            long twoTrillion = Convert.ToInt64(2 * Math.Pow(10, 12));
            if (k == 0)
            {
                Console.WriteLine(twoTrillion - a);
                return;
            }

            long t = a;
            int count = 0;
            while (t < twoTrillion)
            {
                count++;
                t += 1 + t * k;
            }
            
            Console.WriteLine(count);
        }
    }
}