using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = input[0];
            int B = input[1];
            int C = input[2];
            char ans;
            if (A + B == C && A - B == C)
            {
                ans = '?';
            }
            else if (A + B == C)
            {
                ans = '+';
            }
            else if (A - B == C)
            {
                ans = '-';
            }
            else
            {
                ans = '!';
            }
            Console.WriteLine(ans);
        }
    }
}