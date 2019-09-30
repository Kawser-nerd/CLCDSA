using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int h = int.Parse(Console.ReadLine());
            int ans = (a + b) * h / 2;
            Console.WriteLine(ans);
        }
    }
}