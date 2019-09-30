using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string N = Console.ReadLine();
            if (N[0] == N[1] && N[0] == N[2])
            {
                Console.WriteLine("Yes");
            }
            else if (N[1] == N[2] && N[2] == N[3])
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}