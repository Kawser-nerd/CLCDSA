using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int X = Convert.ToInt32(input[0], 16);
            int Y = Convert.ToInt32(input[1], 16);
           
            if (X < Y)
            {
                Console.WriteLine("<");
            }
            else if (X > Y)
            {
                Console.WriteLine(">");
            }
            else
            {
                Console.WriteLine("=");
            }
        }
    }
}