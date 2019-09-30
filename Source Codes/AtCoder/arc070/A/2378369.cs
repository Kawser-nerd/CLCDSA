using System;

namespace ARC070
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var X = int.Parse(Console.ReadLine());

            for (var i = 1;; i++)
            {
                if (i * (i + 1) / 2 >= X)
                {
                    Console.WriteLine(i);
                    return;
                }
            }
        }
    }
}