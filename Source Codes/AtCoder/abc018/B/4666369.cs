using System;
using System.Linq;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int N = int.Parse(Console.ReadLine());

            for(int i = 0; i < N; i++)
            {
                int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                int l = input[0];
                int r = input[1];
                var a = S.Substring(0, l - 1);
                var b =new string(S.Substring(l - 1, r - l + 1).Reverse().ToArray());
                var c = S.Substring(r);
                S = a + b + c;
            }
            Console.WriteLine(S);
        }
    }
}