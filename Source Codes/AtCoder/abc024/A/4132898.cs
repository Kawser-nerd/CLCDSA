using System;
namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input1 = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = input1[0];
            int B = input1[1];
            int C = input1[2];
            int K = input1[3];
            int[] input2 = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int S = input2[0];
            int T = input2[1];

            int ans = A * S + B * T;
            if (K <= S + T)
            {
                int D = (S + T) * C; //??????
                ans -= D;
            }
            Console.WriteLine(ans);
        }
    }
}