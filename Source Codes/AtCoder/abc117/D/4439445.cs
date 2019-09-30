using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BitArray = System.Collections.BitArray;
using BigInteger = System.Numerics.BigInteger;

namespace AtCoderProject
{
    static class Program
    {
        static ulong K;
        static List<ulong> A;
        static List<BitArray> Ab;

        static void Main(string[] args)
        {
            var input = ReadLineSplitUInt64();
            K = input[1];
            A = ReadLineSplitUInt64();
            Ab = A.Select(ToBitArray).ToList();

            Console.WriteLine(dfs());
        }

        static ulong dfs()
        {
            var kb = K.ToBitArray();
            var start = -1;
            for (int i = 63; i >= 0; i--)
            {
                if (kb[i])
                {
                    start = i;
                    break;
                }
            }

            kb = new BitArray(64);
            for (int i = start; i >= 0; i--)
            {
                var trueNum = Ab.Count(ab => ab[i]);
                kb[i] = trueNum * 2 <= Ab.Count;
                if (kb[i] && kb.ToUInt64() > K)
                    kb[i] = false;
            }

            ulong k = kb.ToUInt64();
            ulong sum = 0;
            foreach (var a in A)
            {
                sum += a ^ k;
            }

            return sum;
        }

#if DEBUG
        static string input = @"
1 2
1000000000000
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
        static long ReadLineInt64() => long.Parse(ReadLine());
        static ulong ReadLineUInt64() => ulong.Parse(ReadLine());
        static double ReadLineDouble() => double.Parse(ReadLine());
        static List<string> ReadLineSplit() => ReadLine().Split().ToList();
        static List<int> ReadLineSplitInt32() => ReadLine().Split().Select(s => int.Parse(s)).ToList();
        static List<long> ReadLineSplitInt64() => ReadLine().Split().Select(s => long.Parse(s)).ToList();
        static List<ulong> ReadLineSplitUInt64() => ReadLine().Split().Select(s => ulong.Parse(s)).ToList();
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

        static BitArray ToBitArray(this long l)
        {
            return new BitArray(BitConverter.GetBytes(l));
        }
        static long ToInt64(this BitArray bitArray)
        {
            var array = new byte[8];
            bitArray.CopyTo(array, 0);
            return BitConverter.ToInt64(array, 0);
        }
        static BitArray ToBitArray(this ulong l)
        {
            return new BitArray(BitConverter.GetBytes(l));
        }
        static ulong ToUInt64(this BitArray bitArray)
        {
            var array = new byte[8];
            bitArray.CopyTo(array, 0);
            return BitConverter.ToUInt64(array, 0);
        }
    }
}