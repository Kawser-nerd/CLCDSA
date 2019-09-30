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
                .GroupBy(_ => _)
                .ToDictionary(_ => _.Key, __ => __.Count())
                ;
            int result = 0;
            foreach (var num in line)
            {
                int value = num.Value;
                if (line.ContainsKey(num.Key - 1))
                    value += line[num.Key - 1];
                if (line.ContainsKey(num.Key + 1))
                    value += line[num.Key + 1];
                if(result < value)
                    result = value;
            }
            WriteLine(result);
            ReadLine();
        }
    }
}