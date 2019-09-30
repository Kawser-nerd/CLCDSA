using System;

namespace WA047B
{
    class MainProgram
    {
        static void Main(string[] args)
        {
            var A = int.Parse(Console.ReadLine());
            var B = int.Parse(Console.ReadLine());
            var C = int.Parse(Console.ReadLine());
            var X = int.Parse(Console.ReadLine());

            int total = 0; int count = 0;

            for(var i = 0; i <= A; i++)
            {
                for(var j = 0; j <= B; j++)
                {
                    for(var k = 0; k <= C; k++)
                    {
                        total = 500 * i + 100 * j + 50 * k;
                        if (total == X) count++;
                    }
                }
            }

            Console.WriteLine($"{count}");
        }
    }
}