using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - 1 Dimensional World's Tale
            var line = ReadLine();
            int x = line[2];
            int y = line[3];

            var xCoords = ReadLine().OrderByDescending(c => c).ToList();
            int xMax = xCoords[0];

            var yCoords = ReadLine().OrderBy(c => c).ToList();
            int yMin = yCoords[0];

            for(int i = xMax + 1; i <= yMin; i++)
            {
                if (i > x && i <= y)
                {
                    Console.WriteLine("No War");
                    return;
                }
            }

            Console.WriteLine("War");
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            var numbers = new List<int>();

            foreach (var s in array)
            {
                int num = int.Parse(s);
                numbers.Add(num);
            }

            return numbers;
        }
    }
}