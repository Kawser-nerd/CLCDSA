using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;


namespace Otoshidama
{
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                var ny = GetArrayIntInput();
                for (int i = 0; i <= ny[0]; i++) // 10000
                {
                    for (int j = 0; j + i <= ny[0]; j++) // 5000
                    {
                        int thousandNum = ny[0] - i - j;
                        if (ny[1] == i * 10000 + j * 5000 + thousandNum * 1000)
                        {
                            CWrite($"{i} {j} {thousandNum}");
                            return;
                        }
                    }
                }
                CWrite("-1 -1 -1");
            }
        }

        static string[] GetArrayCharInput() => Console.ReadLine().Split();
        static int[] GetArrayIntInput() => Console.ReadLine().StringToIntArray();
        static int GetIntInput() => Console.ReadLine().ToInt();
        static void CWrite(string str) => Console.WriteLine(str);

    }



    class SetConsole : IDisposable
    {
        readonly StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
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