using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string C1 = Console.ReadLine();
            string C2 = Console.ReadLine();

            if (C1[0] == C2[2] && C1[1] == C2[1] && C1[2] == C2[0])
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}