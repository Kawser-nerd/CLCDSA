using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace MSP
{
    class Program
    {
        TextReader cin = Console.In;
        TextWriter cout = Console.Out;

        public Program(string s)
        {
            cin = new StreamReader(s);
            s = s.Substring(0, s.Length - 2) + "out";
            cout = new StreamWriter(s);
        }

        public static void Main(string[] args)
        {
            foreach (string s in Directory.GetFiles(@"C:\Users\Michael\Desktop\GCJ", "*.in"))
            {
                new Program(s).run();
            }
        }

        private void run()
        {
            int T = readInt();
            for (int cn = 1; cn <= T; cn++)
            {
                int n = readInt();
                int[] v1 = readInts();
                int[] v2 = readInts();
                Array.Sort(v2);
                int res = int.MaxValue;
                do
                {
                    res = Math.Min(res, scalarProduct(v1, v2));
                }
                while (nextPermutation(v2));
                cout.WriteLine("Case #{0}: {1}", cn, res);
            }
            cout.Close();
        }

        int scalarProduct(int[] v1, int[] v2)
        {
            int res = 0;
            for (int i = 0; i < v1.Length; i++)
                res += v1[i] * v2[i];
            return res;
        }

        int readInt()
        {
            return int.Parse(cin.ReadLine().Trim());
        }

        int[] readInts()
        {
            return Array.ConvertAll<string, int>(cin.ReadLine().Split(), int.Parse);
        }

        double readDouble()
        {
            return double.Parse(cin.ReadLine().Trim());
        }

        double[] readDoubles()
        {
            return Array.ConvertAll<string, double>(cin.ReadLine().Split(), double.Parse);
        }

        static bool nextPermutation<T>(T[] arr) where T : IComparable<T>
        {
            if (arr.Length <= 1) return false;
            int idx = arr.Length - 1;
            T tmp = arr[idx];
            while (idx > 0 && tmp.CompareTo(arr[idx - 1]) <= 0) tmp = arr[--idx];
            if (idx <= 0)
            {
                reverse(arr);
                return false;
            }
            reverse(arr, idx);
            int idx2 = idx--;
            tmp = arr[idx2];
            while (tmp.CompareTo(arr[idx]) <= 0) tmp = arr[++idx2];
            swap(arr, idx, idx2);
            return true;
        }

        static void swap<T>(T[] arr, int a, int b)
        {
            T c = arr[a];
            arr[a] = arr[b];
            arr[b] = c;
        }

        static void reverse<T>(T[] arr) { reverse(arr, 0, arr.Length); }
        static void reverse<T>(T[] arr, int start) { reverse(arr, start, arr.Length - start); }
        static void reverse<T>(T[] arr, int start, int len)
        {
            int end = start + len;
            while (start < end - 1)
                swap(arr, start++, --end);
        }
    }
}
