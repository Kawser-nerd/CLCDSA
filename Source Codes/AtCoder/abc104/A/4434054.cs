using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int R = int.Parse(Console.ReadLine());
            if (R < 1200)
            {
                Console.WriteLine("ABC");
            }
            else if (R < 2800)
            {
                Console.WriteLine("ARC");
            }
            else
            {
                Console.WriteLine("AGC");
            }
        }
    }
}