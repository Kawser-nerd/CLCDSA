using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoderProject
{
    static class Program
    {
        static int N;
        static int M;
        static List<int> X;

        static void Main(string[] args)
        {
            var input = ReadLineSplitInt32();
            N = input[0];
            M = input[1];
            X = ReadLineSplitInt32();
            X.Sort();

            Console.WriteLine(dfs());
        }

        static int dfs()
        {
            if (N >= M) return 0;
            var diff = CalcDiff().ToList();
            diff.Sort((a, b) => a - b);

            return diff.Take(M-N).Sum();
        }
        static IEnumerable<int> CalcDiff()
        {
            for (int i = 1; i < X.Count; i++)
            {
                yield return X[i] - X[i - 1];
            }
        }

#if DEBUG
        static string input = @"
2 5
10 12 1 2 14
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