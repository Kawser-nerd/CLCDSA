using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            double[] A = Array.ConvertAll(Console.ReadLine().Split(' '), double.Parse);

            double sum = 0;
            int count = 0;
            for(int i = 0; i < N; i++)
            {
                if (A[i] != 0)
                {
                    sum += A[i];
                    count++;
                }
            }
            double ans = sum / count;
            Console.WriteLine(Math.Ceiling(ans));
        }
    }
}