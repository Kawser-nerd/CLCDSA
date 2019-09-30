using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using __CURRENT_PROBLEM__ = _2016_round1a.B;

// https://code.google.com/codejam/contest/4304486/dashboard
namespace _2016_round1a
{
    public class A
    {
        public object Solve(Func<string> read)
        {
            var ss = read();
            return ss.Skip(1).Aggregate(ss.Substring(0, 1), (s, c) => Sel(c + s, s + c));
        }

        private static string Sel(string a, string b)
        {
            return a.CompareTo(b) > 0 ? a : b;
        }
    }

    public class B
    {
        public object Solve(Func<string> read)
        {
            var n = read().One<int>();
            var ll = read.Many<int>(2*n - 1);

            return string.Join(" ", ll.SelectMany(l => l).GroupBy(x => x).Where(g => g.Count() % 2 == 1).Select(g => g.Key).OrderBy(k => k));
        }
    }

    public class C
    {
        public object Solve(Func<string> read)
        {
            throw new NotImplementedException();
        }
    }

    public static class Util
    {
        public static T One<T>(this string s) => (T)Convert.ChangeType(s, typeof(T));
        public static T[] Some<T>(this string s) => s.Split(' ').Select(One<T>).ToArray();
        public static T[][] Many<T>(this Func<string> read, int rows)
            => Enumerable.Range(1, rows).Select(_ => read().Some<T>()).ToArray();
    }

    public class Program
    {
        public static void Main()
        {
            const int buf = 1024 * 1024;
            using (var reader = new StreamReader(Console.OpenStandardInput(buf), Console.InputEncoding, false, buf))
            {
                using (var writer = new StreamWriter(new FileStream("output.txt", FileMode.Create)))
                {
                    var cases = reader.ReadLine().One<int>();
                    for (var i = 0; i < cases; i++)
                    {
                        var result = new __CURRENT_PROBLEM__().Solve(reader.ReadLine);
                        var output = $"Case #{i + 1}: {result}";
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.WriteLine(output);
                        Console.ResetColor();
                        writer.WriteLine(output);
                    }
                    Console.ReadLine();
                }
            }
        }
    }
}
