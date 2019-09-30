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
            var names = new Tuple<int, string, string>[n];
            for (var i = 0; i < names.Length; i++)
            {
                names[i] = new Tuple<int, string, string>(i, cin.NextString(), cin.NextString());
            }

            //var count = 0;
            //for (var i = 0; i < names.Length; i++)
            //{
            //    var hasFirst = false;
            //    var hasSecond = false;
            //    for (var j = 0; j < names.Length; j++)
            //    {
            //        if (i == j)
            //        {
            //            continue;
            //        }
            //        if (names[i].Item2 == names[j].Item2)
            //        {
            //            hasFirst = true;
            //        }
            //        if (names[i].Item3 == names[j].Item3)
            //        {
                        
            //        }
            //    }
            //}


            var max = int.MinValue;
            for (var i = 0; i < 700000; i++)
            {
                Shuffle(names);
                var first = new HashSet<string>();
                var second = new HashSet<string>();
                var count = 0;
                foreach (var name in names)
                {
                    if (first.Contains(name.Item2) && second.Contains(name.Item3))
                    {
                        count++;
                    }
                    first.Add(name.Item2);
                    second.Add(name.Item3);
                }
                max = Math.Max(max, count);
            }
            Console.WriteLine(max);
        }

        static Random _random = new Random();

        /// <summary>
        /// Shuffle the array.
        /// </summary>
        /// <typeparam name="T">Array element type.</typeparam>
        /// <param name="array">Array to shuffle.</param>
        static void Shuffle<T>(T[] array)
        {
            int n = array.Length;
            for (int i = 0; i < n; i++)
            {
                // NextDouble returns a random number between 0 and 1.
                // ... It is equivalent to Math.random() in Java.
                int r = i + (int)(_random.NextDouble() * (n - i));
                T t = array[r];
                array[r] = array[i];
                array[i] = t;
            }
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