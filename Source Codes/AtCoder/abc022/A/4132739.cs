using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int N = input[0];
            int S = input[1];
            int T = input[2];

            int W = 0;
            int day = 0;
            for(int i = 1; i <= N; i++)
            {
                W += int.Parse(Console.ReadLine());

                if (W >= S && W <= T)
                {
                    day += 1;
                }
            }
            Console.WriteLine(day);
        }
    }
}