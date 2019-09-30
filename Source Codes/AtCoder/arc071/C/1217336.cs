using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC071
{
    class TrBBnsformBBtion
    {
        class BinaryIndexedTree
        {
            int[] array;
            public BinaryIndexedTree(int length)
            {
                array = new int[length];
            }
            public int this[int from, int to]
            {
                get { return At(to) - At(from - 1); }
            }
            int this[int idx]
            {
                set
                {
                    for (var i = idx; i < array.Length; i += RightenZero(i))
                        array[i] += value;
                }
            }
            public void Set(int idx, int value)
            {
                this[idx] = value;
            }
            public int Length
            {
                get { return array.Length; }
            }
            int At(int idx)
            {
                int sum = 0;
                for (var i = idx; i >= 0; i -= RightenZero(i))
                    sum += array[i];
                return sum;
            }
            static int RightenZero(int idx)
            {
                return (~idx) & (idx + 1);
            }
        }
        static BinaryIndexedTree ReadString(string a)
        {
            var bit = new BinaryIndexedTree(a.Length);
            for (var i = 0; i < a.Length; ++i)
                bit.Set(i, (a[i] == 'A') ? 1 : 2);
            return bit;
        }
        static bool IsTransFormable(BinaryIndexedTree a, BinaryIndexedTree b, params int[] query)
        {
            return (a[query[0] - 1, query[1] - 1] % 3 == b[query[2] - 1, query[3] - 1] % 3);
        }
        public static void Main()
        {
            var s = ReadString(ReadLine().Trim());
            var t = ReadString(ReadLine().Trim());
            for (var n = int.Parse(ReadLine()); n > 0; --n)
            {
                var q = ReadLine().Trim().Split(' ').Select(i => int.Parse(i)).ToArray();
                if (IsTransFormable(s, t, q))
                {
                    WriteLine("YES");
                }
                else
                {
                    WriteLine("NO");
                }
            }

        }
    }
}

/*
"A"     => "BB"
"AA"    => "B"
"AAA"   => "BBB"

*/