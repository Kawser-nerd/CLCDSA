using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace ID
{

    class City
    {
        public int Order;
        public long Id;
        public City(int o, long i)
        {
            Order = o;
            Id = i;
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                var nm = GetArrayIntInput();
                List<City>[] Prefectures = new List<City>[nm[0] + 1];
                for (int i = 1; i <= nm[0]; i++) { Prefectures[i] = new List<City>(); }
                for (int i = 1; i <= nm[1]; i++)
                {
                    var py = GetArrayIntInput();
                    Prefectures[py[0]].Add(new City(i, py[1]));
                }

                var results = new List<City>();
                for (int i = 1; i <= nm[0]; i++)
                {
                    Prefectures[i] = Prefectures[i].OrderBy(p => p.Id).ToList();
                    for (int j = 0; j < Prefectures[i].Count; j++)
                    {
                        Prefectures[i][j].Id = (long)i * 1000000 + j + 1;
                        results.Add(Prefectures[i][j]);
                    }
                }

                foreach (var id in results.OrderBy(r => r.Order).Select(r => r.Id))
                {
                   CWrite(Convert.ToString(id, 10).PadLeft(12, '0'));
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
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
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