using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Pyramid
{
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                int n = GetIntInput();
                var xyh = new int[3];
                var list = new List<int[]>();
                for (int i = 0; i < n; i++)
                {
                    var tmp = Console.ReadLine().Split().Select(int.Parse).ToArray();
                    if (tmp[2] != 0)
                    {
                        xyh = tmp;
                    }
                    list.Add(tmp);
                }
                
                bool result = false;
                for (int i = 0; i <= 100; i++)
                {
                    for (int j = 0; j <= 100; j++)
                    {
                        int expH = Math.Abs(xyh[0] - i) + Math.Abs(xyh[1] - j) + xyh[2];
                        var flg = true;
                        for (int k = 0; k < list.Count; k++)
                        {
                            if (list[k][2] != Math.Max(expH - Math.Abs(list[k][0] - i) - Math.Abs(list[k][1] - j), 0))
                            {
                                flg = false;
                                break;
                            }
                        }
                        if (flg && expH >= 1) { Console.WriteLine($"{i} {j} {expH}"); result = true; break; }

                    }
                    if (result) { break; }
                }
            }
        }

        static string[] GetArrayCharInput() => Console.ReadLine().Split();
        static int[] GetArrayIntInput() => Console.ReadLine().StringToIntArray();
        static int GetIntInput() => Console.ReadLine().ToInt();
        static void CWrite(string str) => Console.WriteLine(str);

    }

    class SetConsole : IDisposable
    {
        public SetConsole()
        {
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true };
            Console.SetOut(sw);
        }
        public void Dispose()
        {
            Console.Out.Flush();
        }
    }

    static class ExtentionsLibrary
    {
        public static int[] StringToIntArray(this string str) =>
            str.Split().Select(int.Parse).ToArray();
        public static int ToInt(this string str) => int.Parse(str);
    }
}