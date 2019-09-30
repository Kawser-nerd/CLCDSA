using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();

            var min = int.MaxValue;
            for (int i = 0; i < str.Length - 2; i++)
            {
                var num = int.Parse(str.Substring(i, 3));

                var diff = Math.Abs(753 - num);
                if (diff < min)
                {
                    min = diff;
                }
            }
            Console.WriteLine(min);
        }
    }
}