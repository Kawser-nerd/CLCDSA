using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace cs
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(ReadLine());
            var line = ReadLine()
                .Split(' ')
                .Select(_ => int.Parse(_))
                .ToArray();

            int count = 0;
            for (int i = 0; i < line.Length; i++)
            {
                if (line[i] == i + 1)
                {
                    int j = (i + 1 < line.Length)
                        ? i + 1
                        : i - 1;
                    int buf = line[i];
                    line[i] = line[j];
                    line[j] = buf;
                    count++;
                }
            }

            WriteLine(count);
            ReadLine();
        }
    }
}