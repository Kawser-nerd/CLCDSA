using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Empty
{
    static class ConsoleWrapper
    {
        private static string[] tokens;
        private static int index;

        public static bool IsEmpty
        {
            get
            {
                string v = Read();
                index--;
                return v == null;
            }
        }

        public static string Read()
        {
            if (index < 0)
                return null;
            if (tokens == null || index == tokens.Length)
            {
                string input = Console.ReadLine();
                if (input == null)
                {
                    index = -1;
                    return null;
                }
                tokens = input.Split(' ');
                index = 0;
            }
            return tokens[index++];
        }

        public static void NextLine()
        {
            tokens = null;
        }

        public static int ReadInt()
        {
            return int.Parse(Read());
        }

        public static long ReadLong()
        {
            return long.Parse(Read());
        }

        public static double ReadDouble()
        {
            return double.Parse(Read());
        }
    }

    class B
    {
        static bool testBit(int N, int i)
        {
            return (N & (1 << i)) != 0;
        }

        static int countBits(int N, int l)
        {
            int ans = 0;
            for(int i=0; i<l; i++)
            {
                if (testBit(N, i))
                    ans++;
            }
            return ans;
        }

        static bool testLoc(int N, int x, int y, int C)
        {
            return testBit(N, x + y * C);
        }

        static void Main(string[] args)
        {
            int cases = ConsoleWrapper.ReadInt();
            for (int c = 1; c <= cases; c++)
            {
                int R = ConsoleWrapper.ReadInt();
                int C = ConsoleWrapper.ReadInt();
                int N = ConsoleWrapper.ReadInt();
                int best = int.MaxValue;
                for (int mask = 0; mask < (2 << (R * C)); mask++)
                {
                    if (countBits(mask, R * C) != N)
                        continue;
                    int unhappy = 0;
                    for (int i = 0; i < R * C; i++)
                    {
                        if (!testBit(mask, i))
                            continue;
                        int x = i % C;
                        int y = i / C;
                        if (x > 0 && testLoc(mask, x - 1, y, C))
                            unhappy++;
                        if (y > 0 && testLoc(mask, x, y - 1, C))
                            unhappy++;
                    }
                    if (unhappy < best)
                        best = unhappy;
                }
                Console.WriteLine("Case #" + c + ": " + best);
            }
        }
    }
}
