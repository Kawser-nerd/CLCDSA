using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int n = input[0];
            int X = input[1];
            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if (((X >> i) & 1) == 1)
                {
                    ans += a[i];
                }
            }
            Console.WriteLine(ans);
        }
    }
}