using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoderProject
{
    static class Program
    {
        static void Main(string[] args)
        {
            ReadLine();
            var input = ReadLineSplitInt32();
            input.Sort();
            var max = input[input.Count - 1];
            var sum = input.Take(input.Count - 1).Sum();
            Console.WriteLine(max < sum ? "Yes" : "No");
        }

#if DEBUG
        static string input = @"
4
3 8 4 1
";
        static string _ReadLineImpl() => queue.Dequeue();
        static Queue<string> queue;
        static Program()
        {
            queue = new Queue<string>();
            foreach (var line in input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries))
                queue.Enqueue(line);
        }
#else
        private static string _ReadLineImpl() => Console.ReadLine();
#endif
        static string ReadLine() => _ReadLineImpl();
        static int ReadLineInt32() => int.Parse(ReadLine());
        static double ReadLineDouble() => double.Parse(ReadLine());
        static List<string> ReadLineSplit() => ReadLine().Split().ToList();
        static List<int> ReadLineSplitInt32() => ReadLine().Split().Select(s => int.Parse(s)).ToList();
        static List<double> ReadLineSplitDouble() => ReadLine().Split().Select(s => double.Parse(s)).ToList();

        static IEnumerable<string> RepeatReadLines(int count)
        {
            for (int i = 0; i < count; i++)
                yield return ReadLine();
        }
        static IEnumerable<int> RepeatReadLinesInt32(int count)
        {
            for (int i = 0; i < count; i++)
                yield return ReadLineInt32();
        }
        static IEnumerable<List<string>> RepeatReadLinesSplit(int count)
        {
            for (int i = 0; i < count; i++)
                yield return ReadLineSplit();
        }
    }
}