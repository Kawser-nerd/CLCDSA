using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            Console.WriteLine(char.ToUpper(S[0]) + S.Substring(1).ToLower());
        }
    }
}