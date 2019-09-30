using System;

namespace arc088d
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            int len = input.Length;
            int ans = input.Length;

            for (int i = 1; i < len; ++i)
            {
                if (input[i - 1] != input[i] && (ans > len - i && ans > i))
                {
                    ans = (i >= len - i ? i : len - i);
                }
            }

            Console.WriteLine(ans);
        }
    }
}