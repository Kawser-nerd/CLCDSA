using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            if (N%1111==0)
            {
                Console.WriteLine("SAME");
            }
            else
            {
                Console.WriteLine("DIFFERENT");
            }
        }
    }
}