using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamGoroSort
{
    class Program
    {
        static void Main(string[] args)
        {
            string line = Console.ReadLine();
            int testCount = int.Parse(line);
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                int count = int.Parse(Console.ReadLine());
                var elements = Console.ReadLine().Split();
                int displaced = 0;
                for (int i = 0; i < elements.Length; i++)
                {
                    if (int.Parse(elements[i]) != i + 1)
                        displaced++;
                }

                Console.Write("Case #{0}: ", testNumber);
                Console.Write(displaced);
                Console.WriteLine();
            }
        }
    }
}
