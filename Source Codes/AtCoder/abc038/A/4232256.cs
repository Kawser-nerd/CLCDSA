using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            if (S.EndsWith("T"))
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