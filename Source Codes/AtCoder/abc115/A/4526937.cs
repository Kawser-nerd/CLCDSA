using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int D = int.Parse(Console.ReadLine());
            if (D == 25)
            {
                Console.WriteLine("Christmas");
            }
            else if (D == 24)
            {
                Console.WriteLine("Christmas Eve");
            }
            else if (D == 23)
            {
                Console.WriteLine("Christmas Eve Eve");
            }
            else
            {
                Console.WriteLine("Christmas Eve Eve Eve");
            }
        }
    }
}