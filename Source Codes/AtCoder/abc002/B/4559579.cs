using System;
using System.Linq;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var W = Console.ReadLine();
            var str = "aiueo";
            for(int i = 0; i < W.Length; i++)
            {
                if (!str.Contains(W[i])){
                    Console.Write(W[i]);
                }
            }
            Console.WriteLine();
        }
    }
}