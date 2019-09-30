using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int A = int.Parse(Console.ReadLine());
            int money = N - 500 * (N / 500);
            Console.WriteLine(money <= A ? "Yes" : "No");
        }
    }
}