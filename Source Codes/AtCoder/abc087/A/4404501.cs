using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int X = int.Parse(Console.ReadLine());
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int donut = (X - A) / B;
            Console.WriteLine(X - A - B * donut);
        }
    }
}