using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // 4???????
            int a, b, c, d;

            // ??
            a = int.Parse(input.Split(' ')[0]);
            b = int.Parse(input.Split(' ')[1]);
            c = int.Parse(input.Split(' ')[2]);
            d = int.Parse(input.Split(' ')[3]);

            int count = 0;
            for(int i = 1; i <= 100; i++)
            {
                if (a <= c)
                {
                    if (i >= a && i <= b && i > c && i <= d)
                    {
                        count++;
                    }
                }
                else
                {
                    if (i > a && i <= b && i >= c && i <= d)
                    {
                        count++;
                    }
                }
            }

            // ???????
            Console.WriteLine(count);
        }
    }
}