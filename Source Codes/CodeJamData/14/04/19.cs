using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Algorithms;

// Algorithms namespace is implemented in my own Algorithms library available to public at
// https://github.com/Lexey/Algorithms

namespace task4
{
    class Program
    {

        private static void Benchmark()
        {
            var n = 1000;
            var nayomy = Enumerable.Range(0, n).Select(_ => 0.0004 * _ + 0.1).ToArray();
            var ken = Enumerable.Range(0, n).Select(_ => 0.0001 * _ + 0.2).ToArray();
            var sw = Stopwatch.StartNew();
            var r1 = ScoreWar(nayomy, ken, n);
            var r2 = ScoreDeceitfulWar(nayomy, ken, n);
            var result = String.Format(CultureInfo.InvariantCulture, "{0} {1} {2}"
                , r1, r2, sw.Elapsed);
            Console.WriteLine(result);
        }

        static void Main(string[] args)
        {
            TextReader reader = null;
            TextWriter writer = null;
            try
            {
                //Benchmark();
                //return;
                reader = new StreamReader(args[0], Encoding.ASCII);
                writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
                var cases = int.Parse(reader.ReadLine());
                Console.WriteLine("Cases {0}", cases);
                for (var i = 1; i <= cases; ++i)
                {
                    var n = int.Parse(reader.ReadLine());
                    var naiomy = reader.ReadLine().Split(new[] {' '})
                        .Select(_ => double.Parse(_, CultureInfo.InvariantCulture)).OrderBy(_ => _).ToArray();
                    var ken = reader.ReadLine().Split(new[] { ' ' })
                        .Select(_ => double.Parse(_, CultureInfo.InvariantCulture)).OrderBy(_ => _).ToArray();
                    var r1 = ScoreWar(naiomy, ken, n);
                    var r2 = ScoreDeceitfulWar(naiomy, ken, n);
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1} {2}"
                        , i, r2, r1);
                    writer.WriteLine(result);
                }
            }
            finally
            {
                if (writer != null)
                    writer.Close();
                if (reader != null)
                    reader.Close();
            }
        }

        /// <summary>Оценка War</summary>
        /// <param name="naiomy">Список блоков Naiomy. Отсортирован</param>
        /// <param name="ken">Список блоков Ken. Отсортирован</param>
        /// <param name="n">Число блоков</param>
        /// <returns>Результат игры для Найоми</returns>
        private static int ScoreWar(double[] naiomy, double[] ken, int n)
        {
            // Стратегия Кена - на любой блок Найоми кладем свой
            // наименее больший. Если такого нет, то кладем минимальный
            var listK = new List<double>(ken);
            var result = 0;
            // перебираем блоки Найоми от старшего к младшему
            for (var i = n - 1; i >= 0; --i)
            {
                var naiomyBlock = naiomy[i];
                if (naiomyBlock < listK[0])
                {
                    // наибольший у Найоми меньше наименьшего у Кена
                    // Найоми больше ничего не светит
                    return result;
                }
                var index = listK.LowerBound(naiomyBlock);
                if (index < listK.Count)
                {
                    // У Кена есть блок, который доминирует. Он его и сыграет
                    listK.RemoveAt(index);
                }
                else
                {
                    // У Кена нет старшего блока. Он скинет минимальный
                    listK.RemoveAt(0);
                    ++result;
                }
            }
            return result;
        }

        /// <summary>Оценка Deceitful War</summary>
        /// <param name="naiomy">Список блоков Naiomy. Отсортирован</param>
        /// <param name="ken">Список блоков Ken. Отсортирован</param>
        /// <param name="n">Число блоков</param>
        /// <returns>Результат игры для Найоми</returns>
        private static int ScoreDeceitfulWar(double[] naiomy, double[] ken, int n)
        {
            // Стратегия Найоми - берем самый легкий блок. Если у Кена есть блок, который легче его,
            // то называем свой вес, который на eps больше веса самого тяжелого блока Кена
            // в итоге Кен сбрасывает свой самый легкий блок на наш
            // Если у Кена нет более легких блоков, то называем вес чуть меньше, чем вес его максимального блока
            // В итоге он сбрасывает этот блок на наш легкий
            var listK = new List<double>(ken);
            var result = 0;
            // перебираем блоки Найоми от младшего к старшему
            for (var i = 0; i < n; ++i)
            {
                var naiomyBlock = naiomy[i];
                if (naiomyBlock > listK[0])
                {
                    listK.RemoveAt(0);
                    ++result;
                }
                else
                {
                    listK.RemoveAt(listK.Count - 1);
                }
            }
            return result;
        }
    }
}
