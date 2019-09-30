using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int a = input[0];
            int b = input[1];
            int c = input[2];
            int d = input[3];
            int ab = Math.Abs(a - b);
            int bc = Math.Abs(b - c);
            int ac = Math.Abs(a - c);

            if (ac <= d)
            {
                Console.WriteLine("Yes");
            }
            else if (ab <= d && bc <= d)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}