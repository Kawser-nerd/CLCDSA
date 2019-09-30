using System;

namespace ABC
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            for (var i = 0; i < 25; i++)
            {
                for (var j = 0; j < 15; j++)
                {
                    if ((i * 4) + (j * 7) == N)
                    {
                        Console.WriteLine("Yes");
                        return;
                    }
                }
            }
            Console.WriteLine("No");
        }
    }
}