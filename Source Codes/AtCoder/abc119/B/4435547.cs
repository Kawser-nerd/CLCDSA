using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace AtCoderProject
{
    static class Program
    {
        static void Main(string[] args)
        {
            var N = ReadLineInt32();
            double res = 0;
            foreach (var line in RepeatReadLinesSplit(N))
            {
                var x = double.Parse(line[0]);
                var type = line[1];

                res += type == "BTC" ? 380000 * x : x;
            }
            WriteLine(res);
        }

#if DEBUG
        private static string _ReadLineImpl() => queue.Dequeue();
        private static Queue<string> queue = new Queue<string>
        {
            "5",
            "10 BTC",
            "10 JPY",
            "10 BTC",
            "10 BTC",
            "10 BTC"
        };
#else
        private static string _ReadLineImpl() => Console.ReadLine();
#endif
        static string ReadLine() => _ReadLineImpl();
        static int ReadLineInt32() => int.Parse(ReadLine());
        static string[] ReadLineSplit(char c = ' ') => ReadLine().Split(c);
        static int[] ReadLineSplitInt32(char c = ' ') => ReadLine().Split(c).Select(s => int.Parse(s)).ToArray();
        static long[] ReadLineSplitInt64(char c = ' ') => ReadLine().Split(c).Select(s => long.Parse(s)).ToArray();
        static IEnumerable<string> RepeatReadLines(int count)
        {
            for (int i = 0; i < count; i++)
                yield return ReadLine();
        }
        static IEnumerable<string[]> RepeatReadLinesSplit(int count, char c = ' ')
        {
            for (int i = 0; i < count; i++)
                yield return ReadLineSplit(c);
        }

        static void Add<T>(this Queue<T> queue, T value) => queue.Enqueue(value);
    }
}