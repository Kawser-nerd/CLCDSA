using System;

namespace B___Coins
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = int.Parse(Console.ReadLine());
            var B = int.Parse(Console.ReadLine());
            var C = int.Parse(Console.ReadLine());
            var X = int.Parse(Console.ReadLine());
            int cnt = 0;

            for (int a = 0; a <= A; a++)
            {
                for (int b = 0; b <= B; b++)
                {
                    for (int c = 0; c <= C; c++)
                    {
                        if (500 * a + 100 * b + 50 * c == X)
                        {
                            cnt++;
                        }
                    }
                }
            }
            Console.WriteLine(cnt);
        }
    }
}