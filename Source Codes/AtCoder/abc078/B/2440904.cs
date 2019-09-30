using System;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int ans = 0;
            input[0] -= input[2];
            while (input[0] >= input[1] + input[2])
            {
                ans++;
                input[0] -= input[1] + input[2];
            }
            Console.WriteLine(ans);
        }
    }
}