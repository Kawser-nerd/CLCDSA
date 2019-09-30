using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int ab = Math.Abs(a - b);
            if (ab > 5)
            {
                ab = 10 - ab;
            }
            Console.WriteLine(ab);
        }
    }
}