using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //_reads = new string[] { "200000", string.Join(" ", Enumerable.Repeat("1000000000", 200000)) };
            int count = int.Parse(ReadLine());
            for (int i = 0; i < count; ++i)
            {
                Console.WriteLine(Get());
            }
        }

        static long Get()
        {
            var read = ReadLine().Split(' ').Select(long.Parse).ToArray();
            var min = Math.Min(read[0], read[1]);
            var max = Math.Max(read[0], read[1]);
            long score = read[0] * read[1];
            long sq = (long)Math.Sqrt(score);
            if (sq * sq == score) --sq;
            long result = sq - (min <= sq ? 1 : 0);
            result += sq - (max <= sq ? 1 : 0);
            if (score <= sq * (sq + 1)) --result;
            return result;
        }}}