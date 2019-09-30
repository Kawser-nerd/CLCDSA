using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "C-small-attempt0";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {
            var n = cin.NextInt();
            var b = new int[n];
            for (var i = 0; i < b.Length; i++)
            {
                b[i] = cin.NextInt() - 1;
            }
            var best = 0;

            for (var i = 2; i <= n; i++)
            {
                var items = new int[n];
                for (var j = 0; j < n - i; j++)
                {
                    items[j] = 0;
                }
                for (var j = n - i; j < n; j++)
                {
                    items[j] = 1;
                }

                do
                {
                    var ii = 0;
                    var idx = new int[i];
                    for (var j = 0; j < items.Length; j++)
                    {
                        if (items[j] == 1)
                        {
                            idx[ii++] = j;
                        }
                    }

                    do
                    {
                        var isGood = true;
                        for (var j = 0; j < idx.Length; j++)
                        {
                            var idx1 = ((j - 1) + idx.Length)%idx.Length;
                            var idx2 = (j + 1)%idx.Length;
                            if (idx[idx1] == b[idx[j]] || idx[idx2] == b[idx[j]])
                            {

                            }
                            else
                            {
                                isGood = false;
                                break;
                            }
                        }
                        if (isGood)
                        {
                            best = idx.Length;
                            break;
                        }
                    } while (NextPermutation(idx));
                } while (NextPermutation(items));
            }

            
            Console.WriteLine(best);
        }

        public static bool NextPermutation<T>(T[] items) where T : IComparable
        {
            var i = -1;
            for (var x = items.Length - 2; x >= 0; x--)
            {
                if (items[x].CompareTo(items[x + 1]) < 0)
                {
                    i = x;
                    break;
                }
            }

            if (i == -1)
            {
                return false;
            }
            var j = 0;
            for (var x = items.Length - 1; x > i; x--)
            {
                if (items[x].CompareTo(items[i]) > 0)
                {
                    j = x;
                    break;
                }
            }
            var temp = items[i];
            items[i] = items[j];
            items[j] = temp;
            Array.Reverse(items, i + 1, items.Length - (i + 1));
            //var index = i + 1;
            //var endIndex = index + items.Length - (i + 1) - 1;
            //while (index < endIndex)
            //{
            //    temp = items[index];
            //    items[index] = items[endIndex];
            //    items[endIndex] = temp;
            //    index++;
            //    endIndex--;
            //}
            return true;
        } 
    }

    internal class Scanner
    {
        private string[] s = new string[0];
        private int i;
        private readonly char[] cs = { ' ' };

        public string NextString()
        {
            if (i < s.Length) return s[i++];
            var line = Console.ReadLine() ?? string.Empty;
            if (line == string.Empty)
            {
                return NextString();
            }
            s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 1;
            return s.First();
        }

        public double NextDouble()
        {
            return double.Parse(NextString());
        }

        public int NextInt()
        {
            return int.Parse(NextString());
        }

        public long NextLong()
        {
            return long.Parse(NextString());
        }
    }
}