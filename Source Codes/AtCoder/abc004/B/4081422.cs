using System;
using System.Collections.Generic;
using System.Linq;

namespace Beginner004B
{
    class Program
    {
        static void Main(string[] args)
        {
            var board = new List<List<string>>();
            for (int i = 0; i < 4; i++)
            {
                var line = new List<string>();
                line.AddRange(Console.ReadLine().Split(' '));
                board.Add(line);
            }

            board.Reverse();
            var rotatedList = board.Select(line => { line.Reverse(); return line; });
            Console.WriteLine(string.Join(Environment.NewLine, rotatedList.Select(x => string.Join(" ", x.Select(y => y)))));
        }
    }
}