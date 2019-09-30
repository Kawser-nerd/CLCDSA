using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static int best;
        static int k;
        static string s;
        static bool[] used;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                k = int.Parse(Console.ReadLine());
                s = Console.ReadLine();

                best = s.Length;
                int[] p = new int[k];
                used = new bool[k];
                Perm(0, p);

                Console.WriteLine("Case #{0}: {1}", casen, best);
            }
        }

        static void Perm(int index, int[] p)
        {
            if (index == k)
            {
                RLE(p);
                return;
            }
            for(int i=0; i<k; i++)
                if (!used[i])
                {
                    used[i] = true;
                    p[index] = i;
                    Perm(index + 1, p);
                    used[i] = false;
                }
        }

        static void RLE(int[] p)
        {
            char[] array = new char[s.Length];
            for (int i = 0; i < array.Length; i += k)
            {
                for (int j = 0; j < k; j++)
                    array[i + j] = s[i + p[j]];
            }
            int count = 0;
            char prev = '\0';
            foreach (char ch in array)
            {
                if (ch != prev)
                {
                    prev = ch;
                    count++;
                }
            }
            best = Math.Min(best, count);
        }

        static string[] Input()
        {
            return Console.ReadLine().Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
        }
    }

    class Node
    {
        public int GateType;
        public int Changable;
        public int Value;
    }
}
