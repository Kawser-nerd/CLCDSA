using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int ans = 0;
            string[] S = Console.ReadLine().Split(' ');

            int H = int.Parse(S[0]);
            int W = int.Parse(S[1]);

            string[] s = Console.ReadLine().Split(' ');

            int h = int.Parse(s[0]);
            int w = int.Parse(s[1]);

            ans = (H - h) * (W - w);

            Console.WriteLine(ans.ToString());
        }
    }
}