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
            var date = ReadLine();
            Console.WriteLine(DateTime.Parse(date) < new DateTime(2019, 5, 1) ? "Heisei" : "TBD");
        }

#if DEBUG
        private static string ReadLineImpl() => queue.Dequeue();
        private static Queue<string> queue = new Queue<string>
        {
            "2019/05/04"
        };
#else
        private static string ReadLineImpl() => Console.ReadLine();
#endif
        static string ReadLine() => ReadLineImpl();
        static int ReadLineInt32() => int.Parse(ReadLine());
        static string[] ReadLineSplit(char c) => ReadLine().Split(',');
        static int[] ReadLineSplitInt32(char c) => ReadLine().Split(',').Select(s => int.Parse(s)).ToArray();
        static long[] ReadLineSplitInt64(char c) => ReadLine().Split(',').Select(s => long.Parse(s)).ToArray();
        static void Add<T>(this Queue<T> queue, T value) => queue.Enqueue(value);
    }
}