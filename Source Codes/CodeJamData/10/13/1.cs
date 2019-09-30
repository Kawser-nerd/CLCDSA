using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

namespace GoogleCodeJam
{
    class Program
    {
        readonly StreamReader reader = new StreamReader("../../Input.txt");
        readonly StreamWriter writer = new StreamWriter("../../Output.txt");
        string bufferedLine;
        int bufferedLineIndex;

        static IEnumerable<int> ReadInts(string data)
        {
            return data.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
        }

        string ReadToken()
        {
            if (bufferedLine == null)
                bufferedLine = reader.ReadLine();
            while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            while (bufferedLineIndex >= bufferedLine.Length)
            {
                bufferedLine = reader.ReadLine();
                bufferedLineIndex = 0;
                while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                    bufferedLineIndex++;
            }
            int index = bufferedLineIndex;
            while (bufferedLineIndex < bufferedLine.Length && !char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            return bufferedLine.Substring(index, bufferedLineIndex - index);
        }

        int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            var program = new Program();
            stopwatch.Start();
            program.Run();
            stopwatch.Stop();
            program.reader.Close();
            program.writer.Close();
            Console.WriteLine("Elapsed: " + stopwatch.Elapsed);
        }

        void Run()
        {
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                Stopwatch stopwatch = new Stopwatch();
                int A1 = ReadInt(), A2 = ReadInt(), B1 = ReadInt(), B2 = ReadInt();
                stopwatch.Start();
                var res = Calc(A1, A2, B1, B2);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        int[] start;
        int[] end;
        const int N = 1000000;

        void Calc()
        {
            if (start != null)
                return;
            start = new int[N + 1];
            end = new int[N + 1];
            var queue = new Queue<Pair>();
            bool gg = true;
            for (int i = 1; i < N + 1; i++)
            {
                Pair p = queue.Count == 0 ? new Pair(i, i) : queue.Peek();
                while (p.Key < i)
                {
                    queue.Dequeue();
                    p = queue.Count == 0 ? new Pair(i, i) : queue.Peek();
                }
                start[i] = p.Value;
                end[i] = start[i] + i - 1;
                if (gg)
                {
                    if (end[i] > N)
                        gg = false;
                    queue.Enqueue(new Pair(end[i], i));
                }
            }
        }

        long Calc(int A1, int A2, int B1, int B2)
        {
            return Calc(A2, B2) - Calc(A1 - 1, B2) - Calc(A2, B1 - 1) + Calc(A1 - 1, B1 - 1);
        }

        long Calc(int A, int B)
        {
            Calc();
            if (B < A)
            {
                var t = A;
                A = B;
                B = t;
            }
            long res = 0;
            for (int i = 1; i <= A; i++)
            {
                int e = Math.Min(end[i], B);
                int b = Math.Min(start[i], B + 1);
                res += e - b + 1;
            }
            return (long) A * B - res;
        }
    }
}