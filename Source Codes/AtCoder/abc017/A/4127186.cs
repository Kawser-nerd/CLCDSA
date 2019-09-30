using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double ans = 0;
            for(int i = 0; i < 3; i++)
            {
                int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                int s = input[0];
                int e = input[1];
                ans += s * e * 0.1;
            }
            Console.WriteLine(ans);
        }
    }
}