using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int C = int.Parse(Console.ReadLine());
            int D = int.Parse(Console.ReadLine());

            int ans = Math.Min(A, B) + Math.Min(C, D);
            Console.WriteLine(ans);
        }
    }
}