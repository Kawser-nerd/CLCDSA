using System;
using System.Linq;

namespace WA055A
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().ToArray();

            int counter = 0;
            
            for(var i = 0; i < line.Length; i++)
            {
                if (line[i] == 'o') counter++;
            }

            Console.WriteLine(700 + 100 * counter);
        }
    }
}