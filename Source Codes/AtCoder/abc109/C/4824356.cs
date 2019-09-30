using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Skip
{
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                var input = GetArrayIntInput();
                int x = input[1];
                var xs = new List<int>(Console.ReadLine().Split().Select(int.Parse)) { x }.ToList();
                xs.Sort();
                var list = new List<int>();
                for (int i = 0; i < xs.Count - 1; i++)
                {
                    list.Add(xs[i + 1] - xs[i]);
                }

                for (int i = 0; i < list.Count - 1; i++)
                {
                    int gcd = GCD(list[i], list[i + 1]);
                    list[i + 1] = gcd;
                }
                CWrite(list[list.Count - 1]);
            }
        }

        static int GCD(int x, int y)
        {
            if (y > x)
            {
                int tmp = x;
                x = y;
                y = tmp;
            }
            int mod = x % y;
            while (mod != 0)
            {
                x = y;
                y = mod;
                mod = x % y;
            }
            return y;
        }
        static string[] GetArrayCharInput() => Console.ReadLine().Split();
        static int[] GetArrayIntInput() => Console.ReadLine().StringToIntArray();
        static int GetIntInput() => Console.ReadLine().ToInt();
        static void CWrite<T>(T str) => Console.WriteLine(str);

    }

    class SetConsole : IDisposable
    {
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        public SetConsole()
        {
            sw.AutoFlush = false;
            Console.SetOut(sw);
        }
        public void Dispose()
        {
            Console.Out.Flush();
            sw.AutoFlush = true;
            Console.SetOut(sw);
        }
    }

    static class ExtentionsLibrary
    {
        public static int[] StringToIntArray(this string str) =>
            str.Split().Select(int.Parse).ToArray();
        public static int ToInt(this string str) => int.Parse(str);
    }
}