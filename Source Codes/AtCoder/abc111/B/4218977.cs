using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var n = int.Parse(str);

            var zoroStr = "" + str[0] + str[0] + str[0];
            var zoro = int.Parse(zoroStr);
            if (n <= zoro)
            {
                for (int i = 0; i < str.Length; i++)
                {
                    Console.Write(str[0]);
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine(zoro + 111);
            }
        }
    }
}