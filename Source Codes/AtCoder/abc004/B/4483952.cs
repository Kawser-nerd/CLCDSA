using System;

namespace ABC004B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] c = new string[4];
            for(var i = 0; i < 4; i++)
            {
                c[i] = Console.ReadLine();
            }

            for(var i = 0; i < 4; i++)
            {
                for(var j = 0; j < 7; j++)
                {
                    Console.Write(c[3 - i][6 - j]);
                }
                Console.WriteLine();
            }
        }
    }
}